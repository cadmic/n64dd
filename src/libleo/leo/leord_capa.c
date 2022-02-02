#include "n64dd.h"
#include "n64dd_functions.h"
#include "libleo_functions.h"

// leoRd_capacity
void leoRd_capacity(void) {
    if (LEOcur_command->header.control & LEO_CONTROL_WRT) { // Possibly LEO_CONTROL_TBL
        LEOcur_command->data.readWrite.lba = LEORAM_START_LBA[LEOdisk_type] - 0x18;
        LEOcur_command->data.readWrite.transferBlks = 0x10C3;
        LEOcur_command->data.readWrite.buffPtr = LEORAM_BYTE[LEOdisk_type];
    } else {
        LEOcur_command->data.readWrite.lba = 0;
        LEOcur_command->data.readWrite.transferBlks = 0x10C3;
        LEOcur_command->data.readWrite.buffPtr = 0x3D78F40; // Total capacity, approx. 64.45 MB
    }
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}