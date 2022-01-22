#include "n64dd.h"

UNK_TYPE func_801CF0B0(UNK_TYPE); // Handwritten function, looks up in a table.

/**
 * Seems to work out if a pair of bytes is a valid EUC-JP character, although there may be additions to the font that
 * make the strange first check make more sense.
 *
 * @param bytes Array 2 bytes to test
 * @return boolean
 */
s32 func_801C9440(u8* bytes) {
    // This is every possible first byte. May make more sense what was intended with the font files?
    if (((*bytes >= 0x8E) && (*bytes <= 0xFE)) || ((*bytes != 0x8F) && (*bytes != 0xA0))) {
        bytes++;
        return (*bytes >= 0xA0) && (*bytes <= 0xFE);
    }
    return false;
}

/**
 * Seems to be a crude check for a valid 2-byte Shift-JIS character
 *
 * @param bytes Array 2 bytes to test
 * @return boolean
 */
s32 func_801C9494(u8* bytes) {
    if (((*bytes >= 0x81) && (*bytes <= 0x9F)) || ((*bytes >= 0xE0) && (*bytes <= 0xFC))) {
        bytes++;
        return (*bytes >= 0x40) && (*bytes <= 0xFC) && *bytes != 0x7F;
    }
    return false;
}

// Extracts 2 bytes from a bytepacked big-endian short.
void func_801C94F8(char* arg0, u16 arg1) {
    arg0[0] = arg1 >> 8;
    arg0[1] = arg1 & 0xFF;
}

// Convert EUC-JP to JIS X 0208
u16 func_801C9514(u16 eucjpCh) {
    return eucjpCh - 0x8080;
}

/**
 * @brief Converts a JIS X 0208 codepoint to a Shift-JIS one.
 *
 * @param jisCodepoint Two bytes, each between 0x21 and 0x7E, packed big-endian into a short.
 * @return u16 Shift-JIS character representation (expected to be big-endian)
 */
u16 func_801C9534(u16 jisCodepoint) {
    u8 hiByte = (jisCodepoint >> 8) & 0xFF;
    u8 loByte = jisCodepoint & 0xFF;

    if (hiByte & 1) {
        loByte += 0x1F;
        if (loByte >= 0x7F) {
            loByte++;
        }
    } else {
        loByte += 0x7E;
    }

    hiByte = (hiByte - 0x21) / 2 + 0x81;
    if (hiByte >= 0xA0) {
        hiByte += 0x40;
    }

    return (hiByte << 8) + loByte;
}



void func_801C95C0(s32, s32, UNK_TYPE);
#pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C95C0.s")

// #pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C95F0.s")

s32 func_801C95F0(char* arg0) {
    return func_801CF0B0(func_801C9534(func_801C9514((arg0[0] << 8) | arg0[1]))) + 0xA0000;
}

// #pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C963C.s")
extern s32 B_801E0F70;

s32 func_801CFBB0(s32, UNK_PTR, UNK_PTR, UNK_PTR);

s32 func_801C963C(s32* arg0, UNK_PTR arg1, UNK_PTR arg2, UNK_PTR arg3, u8 arg4) {
    s32 temp_v0;
    s32 temp_v1;

    u16 temp = (arg4 - 0x20);
    temp += ((0xC0 * B_801E0F70));

    temp_v0 = func_801CFBB0(temp, arg1, arg2, arg3);
    temp_v1 = temp_v0 & 0xF;
    *arg0 = (temp_v0 - temp_v1) + 0xA0000;
    return temp_v1;
}

// #pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C969C.s")
s32 func_801C969C(UNK_TYPE arg0, UNK_PTR* arg1, UNK_PTR* arg2, UNK_PTR* arg3, u8* arg4) {
    s32 sp24;
    s32 phi_v1;

    if (func_801C9440(arg4) != 0) {
        sp24 = func_801C95F0(arg4);
        *arg1 = 0x10;
        *arg2 = 0x10;
        *arg3 = 0xB;
        phi_v1 = 0;
    } else {
        phi_v1 = func_801C963C(&sp24, arg1, arg2, arg3, *arg4);
    }
    // sp20 = phi_v1;
    func_801C95C0(arg0, sp24, 0x80);
    return phi_v1;
}

// #pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C9740.s")
UNK_TYPE4 func_801C9740(u8* arg0, UNK_TYPE4 arg1, u8 arg2) {
    if (arg1 == 1) {
        *arg0 = arg2 * 0x10;
        return 0;
    } else {
        *arg0 |= arg2;
        return 1;
    }
}

// #pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C9778.s")
UNK_TYPE4 func_801C9778(UNK_TYPE4 arg0, UNK_TYPE4* arg1, s32 arg2) {
    arg0 += (arg2 >> 1);

    if (((*arg1 == 1) && !(arg2 & 1)) || ((*arg1 == 0) && (arg2 & 1))) {
        arg0 += arg2 & 1;
        *arg1 = 1;
    } else {
        *arg1 = 0;
    }
    return arg0;
}

#pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C97C4.s")

// #pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C9954.s")
void func_801C9954(u8* bytes, s32* arg1, s32* arg2) {
    u8 prevCh;
    u8 nextCh;

    if (func_801C9440(bytes)) {
        *arg2 = 0;
        *arg1 = 0;
    } else {
        *arg2 = 0;
        *arg1 = 0;

        prevCh = bytes[-1];
        nextCh = bytes[1];

        switch (bytes[0]) {
            case ' ':
                *arg2 = 0;
                *arg1 = 0;
                break;

            case 'I':
            case 'i':
                *arg2 = 2;
                *arg1 = 2;
                if (1) {}
                *arg2 = 2;
                if (prevCh == 0x20) {
                    *arg1 = 0;
                }
                if (nextCh == 0x20) {
                    *arg2 = 0;
                }
                break;

            default:
                *arg2 = 1;
                *arg1 = 1;
                if (1) {}
                *arg2 = 1;
                break;
        }
    }
}

void func_801C9A10(u8*, s32, char*);
#pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C9A10.s")

#pragma GLOBAL_ASM("oot/ne0/asm/functions/n64dd/n64dd_801C9440/func_801C9B50.s")
