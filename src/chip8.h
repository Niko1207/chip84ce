#ifndef CHIP8_H
#define CHIP8_H

#define CHIP8_FONTSIZE     5
#define CHIP8_KEYCOUNT     16
#define CHIP8_SCRHEIGHT    32
#define CHIP8_SCRWIDTH     64
#define CHIP8_SPRITEWIDTH  8
#define CHIP8_PROGRAMSTART 0x200

typedef signed char i8;
typedef unsigned char u8;

typedef signed short i16;
typedef unsigned short u16;

typedef signed long i32;
typedef unsigned long u32;

static const u8 test_rom[478] =
{
    0x12,0x4e,0xea,0xac,0xaa,0xea,0xce,0xaa,0xaa,0xae,0xe0,0xa0,0xa0,0xe0,0xc0,0x40,0x40,0xe0,0xe0,0x20,0xc0,0xe0,0xe0,0x60,0x20,0xe0,0xa0,0xe0,0x20,0x20,0x60,0x40,
    0x20,0x40,0xe0,0x80,0xe0,0xe0,0xe0,0x20,0x20,0x20,0xe0,0xe0,0xa0,0xe0,0xe0,0xe0,0x20,0xe0,0x40,0xa0,0xe0,0xa0,0xe0,0xc0,0x80,0xe0,0xe0,0x80,0xc0,0x80,0xa0,0x40,
    0xa0,0xa0,0xa2,0x02,0xda,0xb4,0x00,0xee,0xa2,0x02,0xda,0xb4,0x13,0xdc,0x68,0x01,0x69,0x05,0x6a,0x0a,0x6b,0x01,0x65,0x2a,0x66,0x2b,0xa2,0x16,0xd8,0xb4,0xa2,0x3e,
    0xd9,0xb4,0xa2,0x02,0x36,0x2b,0xa2,0x06,0xda,0xb4,0x6b,0x06,0xa2,0x1a,0xd8,0xb4,0xa2,0x3e,0xd9,0xb4,0xa2,0x06,0x45,0x2a,0xa2,0x02,0xda,0xb4,0x6b,0x0b,0xa2,0x1e,
    0xd8,0xb4,0xa2,0x3e,0xd9,0xb4,0xa2,0x06,0x55,0x60,0xa2,0x02,0xda,0xb4,0x6b,0x10,0xa2,0x26,0xd8,0xb4,0xa2,0x3e,0xd9,0xb4,0xa2,0x06,0x76,0xff,0x46,0x2a,0xa2,0x02,
    0xda,0xb4,0x6b,0x15,0xa2,0x2e,0xd8,0xb4,0xa2,0x3e,0xd9,0xb4,0xa2,0x06,0x95,0x60,0xa2,0x02,0xda,0xb4,0x6b,0x1a,0xa2,0x32,0xd8,0xb4,0xa2,0x3e,0xd9,0xb4,0x22,0x42,
    0x68,0x17,0x69,0x1b,0x6a,0x20,0x6b,0x01,0xa2,0x0a,0xd8,0xb4,0xa2,0x36,0xd9,0xb4,0xa2,0x02,0xda,0xb4,0x6b,0x06,0xa2,0x2a,0xd8,0xb4,0xa2,0x0a,0xd9,0xb4,0xa2,0x06,
    0x87,0x50,0x47,0x2a,0xa2,0x02,0xda,0xb4,0x6b,0x0b,0xa2,0x2a,0xd8,0xb4,0xa2,0x0e,0xd9,0xb4,0xa2,0x06,0x67,0x2a,0x87,0xb1,0x47,0x2b,0xa2,0x02,0xda,0xb4,0x6b,0x10,
    0xa2,0x2a,0xd8,0xb4,0xa2,0x12,0xd9,0xb4,0xa2,0x06,0x66,0x78,0x67,0x1f,0x87,0x62,0x47,0x18,0xa2,0x02,0xda,0xb4,0x6b,0x15,0xa2,0x2a,0xd8,0xb4,0xa2,0x16,0xd9,0xb4,
    0xa2,0x06,0x66,0x78,0x67,0x1f,0x87,0x63,0x47,0x67,0xa2,0x02,0xda,0xb4,0x6b,0x1a,0xa2,0x2a,0xd8,0xb4,0xa2,0x1a,0xd9,0xb4,0xa2,0x06,0x66,0x8c,0x67,0x8c,0x87,0x64,
    0x47,0x18,0xa2,0x02,0xda,0xb4,0x68,0x2c,0x69,0x30,0x6a,0x34,0x6b,0x01,0xa2,0x2a,0xd8,0xb4,0xa2,0x1e,0xd9,0xb4,0xa2,0x06,0x66,0x8c,0x67,0x78,0x87,0x65,0x47,0xec,
    0xa2,0x02,0xda,0xb4,0x6b,0x06,0xa2,0x2a,0xd8,0xb4,0xa2,0x22,0xd9,0xb4,0xa2,0x06,0x66,0xe0,0x86,0x6e,0x46,0xc0,0xa2,0x02,0xda,0xb4,0x6b,0x0b,0xa2,0x2a,0xd8,0xb4,
    0xa2,0x36,0xd9,0xb4,0xa2,0x06,0x66,0x0f,0x86,0x66,0x46,0x07,0xa2,0x02,0xda,0xb4,0x6b,0x10,0xa2,0x3a,0xd8,0xb4,0xa2,0x1e,0xd9,0xb4,0xa3,0xe8,0x60,0x00,0x61,0x30,
    0xf1,0x55,0xa3,0xe9,0xf0,0x65,0xa2,0x06,0x40,0x30,0xa2,0x02,0xda,0xb4,0x6b,0x15,0xa2,0x3a,0xd8,0xb4,0xa2,0x16,0xd9,0xb4,0xa3,0xe8,0x66,0x89,0xf6,0x33,0xf2,0x65,
    0xa2,0x02,0x30,0x01,0xa2,0x06,0x31,0x03,0xa2,0x06,0x32,0x07,0xa2,0x06,0xda,0xb4,0x6b,0x1a,0xa2,0x0e,0xd8,0xb4,0xa2,0x3e,0xd9,0xb4,0x12,0x48,0x13,0xdc
};

struct chip8
{
    u8 DT, ST, V[16], Kbd[16];
    u16 PC, SP, I, Stk[16];
    u8 FrmBuf[CHIP8_SCRHEIGHT][CHIP8_SCRWIDTH];
    u8 Mem[4096];
};

static const u8 chip8_font[16 * CHIP8_FONTSIZE] =
{
    0xF0, 0x90, 0x90, 0x90, 0xF0,
    0x20, 0x60, 0x20, 0x20, 0x70,
    0xF0, 0x10, 0xF0, 0x80, 0xF0,
    0xF0, 0x10, 0xF0, 0x10, 0xF0,
    0x90, 0x90, 0xF0, 0x10, 0x10,
    0xF0, 0x80, 0xF0, 0x10, 0xF0,
    0xF0, 0x80, 0xF0, 0x90, 0xF0,
    0xF0, 0x10, 0x20, 0x40, 0x40,
    0xF0, 0x90, 0xF0, 0x90, 0xF0,
    0xF0, 0x90, 0xF0, 0x10, 0xF0,
    0xF0, 0x90, 0xF0, 0x90, 0x90,
    0xE0, 0x90, 0xE0, 0x90, 0xE0,
    0xF0, 0x80, 0x80, 0x80, 0xF0,
    0xE0, 0x90, 0x90, 0x90, 0xE0,
    0xF0, 0x80, 0xF0, 0x80, 0xF0,
    0xF0, 0x80, 0xF0, 0x80, 0x80
};

bool chip8_exec(struct chip8 *);
bool chip8_init(struct chip8 *);

#endif
