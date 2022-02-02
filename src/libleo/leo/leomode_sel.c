#include "n64dd.h"
#include "n64dd_functions.h"

void leoMode_sel(void) {
    u32 sense;

    sense = leoSend_asic_cmd_w_nochkDiskChange(0x60000, LEOcur_command->data.time.yearlo << 0x10);
    if (sense != LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
        goto mselerror;
    }
    sense = leoSend_asic_cmd_w_nochkDiskChange(0x70000, LEOcur_command->data.time.month << 0x10);
    if (sense != LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
        goto mselerror;
    }
    sense = leoSend_asic_cmd_w_nochkDiskChange(0x150000, LEOcur_command->data.readWrite.transferBlks);
    if (sense != LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
        goto mselerror;
    }

    if (0) {
    mselerror:
        LEOcur_command->header.sense = sense;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
    } else {
        LEOcur_command->header.sense = sense;
        LEOcur_command->header.status = LEO_STATUS_GOOD;
    }
}
