#ifndef N64DD_FUNCTIONS_H
#define N64DD_FUNCTIONS_H

#include "ultra64.h"
#include "n64dd.h"

u32 func_801C6E80(void);
// void func_801C6EA0();
// void func_801C6EAC();
// void func_801C6EF0();
// void func_801C6F08();
// void func_801C6F30();
// void func_801C6F78();
s32 func_801C6FAC(void);
void func_801C6FD8(void);
void func_801C7018(void);
s32 func_801C7064(void);
s32 func_801C7098(void);
s32 func_801C70E4(void);
s32 func_801C70FC(void);
// void func_801C711C();
// void func_801C7268();
// void func_801C7438();
// void func_801C746C();
// void func_801C75BC();
void func_801C761C(void);
s32 func_801C7658(void);
s32 func_801C7818(void);
s32 func_801C78B8(void);
s32 func_801C78F0(void);
// void func_801C7920();
// void func_801C79CC();
void func_801C7A10(LEODiskID*);
s32 func_801C7A1C(struct_801E0D18* arg0);
// void func_801C7B48();
s32 func_801C7BEC(s32 startLBA);
// void func_801C7C1C();
void func_801C7E78(void);
s32 func_801C7E80(void);
s32 func_801C7F24(void);
void n64dd_SetDiskVersion(s32 arg0);

s32 func_801C8000(struct_801D9D50* arg0);
void func_801C819C(UNK_TYPE arg0);
s32 func_801C81C4(void);
s32 func_801C81D4(void);
void func_801C81EC(struct_801E0D18*);
void func_801C8298(struct_801E0D18* arg0);
void func_801C82E0(struct_801E0D18* arg0);
void func_801C832C(struct_801E0D18*);
void func_801C83A0(struct_801E0D18*);
void func_801C8414(struct_801E0D18*);
void func_801C8424(struct_801E0D18* arg0);
void func_801C84D4(void* arg);
void func_801C8554(void);
void func_801C8578(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_801C85F0(struct_801E0D18* arg0, s32 arg1);
void func_801C8638(void (*arg0)(void*, void*, void*), s32 arg1, void (*arg2)(void*, uintptr_t, size_t));
void func_801C868C(s32 arg0, s32 arg1, s32 arg2, u8 arg3);
s32 func_801C873C(struct_801E0D18* arg0);
s8 func_801C8770(void);
s32 func_801C87C0(void);
s32 func_801C87FC(void);
s32 func_801C8844(void);
s32 func_801C885C(void);
s32 func_801C88AC(void);
s32 func_801C88FC(void);

void func_801C8940(s32 errorNum);
void func_801C8974(void);
void func_801C89B8(s32 errorNum);
void func_801C89EC(void);
void func_801C8A30(s32 errorNum);
void func_801C8A64(void);
void func_801C8AA8(void);
void func_801C8B58(s32 arg0, s32 arg1, s32 arg2);
void func_801C8B90(void);
s32 func_801C8BC0(struct_801E0D18* arg0);
s32 func_801C8C1C(struct_801E0D18* arg0);
s32 func_801C8CEC(struct_801E0D18* arg0);
s32 func_801C8DC0(struct_801E0D18* arg0);
s32 func_801C8E70(struct_801E0D18* arg0);
s32 func_801C8F1C(struct_801E0D18* arg0);
s32 func_801C8F58(struct_801E0D18* arg0);
s32 func_801C9000(struct_801E0D18* arg0);
s32 func_801C90C4(struct_801E0D18* arg0);
s32 func_801C90FC(struct_801E0D18* arg0);
s32 func_801C912C(struct_801E0D18* arg0);
s32 func_801C91E0(struct_801E0D18*);
s32 func_801C9260(struct_801E0D18*);
s32 func_801C9334(struct_801E0D18*);
s32 func_801C93C4(struct_801E0D18*);

s32 func_801C9440(u8* bytes);
s32 func_801C9494(u8* bytes);
void func_801C94F8(char* arg0, u16 arg1);
u16 func_801C9514(u16 eucjpCh);
u16 func_801C9534(u16 jisCodepoint);
void func_801C95C0(void* arg0, uintptr_t arg1, size_t arg2);
s32 func_801C95F0(char* arg0);
s32 func_801C963C(s32* arg0, s32* dx, s32* dy, s32* cy, u8 arg4);
s32 func_801C969C(void* arg0, s32* dx, s32* dy, s32* cy, u8* arg4);
s32 func_801C9740(u8* arg0, UNK_TYPE4 arg1, u8 arg2);
// void func_801C9778();
// void func_801C97C4();
void func_801C9954(u8* bytes, s32* arg1, s32* arg2);
// void func_801C9A10();
void func_801C9B50(s32 arg0, void (*arg1)(void*, uintptr_t, size_t));

// void func_801C9B70();
// void func_801C9C48();
// void func_801C9C74();
// void func_801C9CA4();
// void func_801C9CD4();
// void func_801C9D54();
// void func_801C9DB8();
// void func_801C9E28();
// void func_801C9EC0();
// void func_801C9EF4();
// void func_801C9F90();
// void func_801C9FFC();
// void func_801CA030();
// void func_801CA070();

// void func_801CA0B0();
// void func_801CA1D4();
void func_801CA1F0(void* charTexBuf, s32 posX, s32 posY, s32 dx, s32 dy, s32 cy, void* frameBuf, s32 screenWidth);
// void func_801CA2F8();
// void func_801CA314();
// void func_801CA334();
// void func_801CA350();
// void func_801CA3B4();
// void func_801CA3CC();
// void func_801CA4F4();
// void func_801CA5BC();
// void func_801CA618();
// void func_801CA670();
// void func_801CA6A0();
// void func_801CA6D8();
// void func_801CA6E4();
// void func_801CA704();

#endif
