#ifndef MACROS_H
#define MACROS_H

#define VERSION_ne0 0
#define VERSION_ne1 1
#define VERSION_np0 2
#define VERSION_ne2 3
#define VERSION_np1 4

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define ALIGN8(val) (((val) + 7) & ~7)

#define STACK(stack, size) u64 stack[ALIGN8(size) / sizeof(u64)]

#define STACK_TOP(stack) ((u8*)(stack) + sizeof(stack))

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#if !defined(__GNUC__) && !defined(__attribute__)
#define __attribute__(x)
#endif

#define FALLTHROUGH  __attribute__((fallthrough))

#endif
