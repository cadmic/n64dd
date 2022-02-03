#include "n64dd.h"
#include "n64dd_functions.h"
#include "libleo_functions.h"
#include "libc/stdint.h"

#if 0
s32 LeoCJCreateLeoManager(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt);
//{
//    OSPiHandle* driveRomHandle;
//    OSPiHandle* leoDiskHandle;
//    volatile LEOCmdInquiry cmdBlockInq;
//    volatile LEOCmd cmdBlockID;
//    LEODiskID thisID;
//    u32 stat;
//    u32 data;
//    {
//        volatile s32 dummy;
//    }
//    {
//        volatile u32 dummy;
//    }
//}
#endif

#ifdef NON_MATCHING
s32 LeoCJCreateLeoManager(s32 comPri, s32 intPri, void** cmdBuf, s32 cmdMsgCnt) {
    OSPiHandle* driveRomHandle; // sp84
    OSPiHandle* leoDiskHandle; // sp80
    volatile LEOCmdInquiry cmdBlockInq; // sp6C
    volatile LEOCmd cmdBlockID; // sp50
    LEODiskID thisID; // sp30
    u32 stat; // sp2C
    u32 data; // sp28

    if (__leoActive) {
        return LEO_ERROR_GOOD;
    }

    if (!LeoDriveExist()) {
        return LEO_ERROR_DEVICE_COMMUNICATION_FAILURE;
    }

    osLeoDiskInit();
    driveRomHandle = osDriveRomInit();
    __leoActive = true;

    __osSetHWIntrRoutine(1, __osLeoInterrupt, leoDiskStack + 0xFF0);
    leoInitialize(comPri, intPri, cmdBuf, cmdMsgCnt);

    if (osResetType == 1) {
        __leoSetReset();
    }

    cmdBlockInq.header.command = 2;
    cmdBlockInq.header.reserve1 = 0;
    cmdBlockInq.header.control = 0;
    cmdBlockInq.header.reserve3 = 0;
    leoCommand((void*)&cmdBlockInq);

    {
        volatile s32 dummy = (uintptr_t) &cmdBlockInq & 0xFFFFFF;

        while (dummy > 0) {
            dummy -= ((uintptr_t) __leoSetReset & 0xFFFFFF) | 0x403DF4;
        }
    }

    while (cmdBlockInq.header.status == 8);

    if (cmdBlockInq.header.status != 0) {
        return cmdBlockInq.header.sense;
    }

    __leoVersion.driver = cmdBlockInq.version;
    __leoVersion.drive = 6;
    __leoVersion.deviceType = cmdBlockInq.devType;
    __leoVersion.nDevices = cmdBlockInq.devNum;

    stat = __leoVersion.driver & 0xF;
    if (stat == 4) {
        LEO_country_code = 0;
    } else if ((stat == 3) || (stat == 1)) {
        volatile u32 dummy;

        osEPiReadIo(driveRomHandle, 0x9FF00, &data);
        dummy = 0x3ED98F23;
        if (((data & 0xFF000000) >> 0x18) != 0xC3) {
            while (true) {}
        }

        dummy *= data;
        dummy -= (uintptr_t)&cmdBlockInq;
        LEO_country_code = -0x17B72CEA;
    } else {
        while (true) {}
    }

    return LEO_ERROR_GOOD;
}
#else
#pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/cjcreateleomanager/LeoCJCreateLeoManager.s")
#endif
