/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --stride 1 --align 1 --font Montserrat-Regular.ttf --symbols ¡¢£€¥Š§š©ª«¬­®¯°±²³´µ¶·¸¹º»ŒœŸ ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ --range 32-126 --format lvgl -o Monserat14_ISO_8859_15.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef MONSERAT14_ISO_8859_15
#define MONSERAT14_ISO_8859_15 1
#endif

#if MONSERAT14_ISO_8859_15

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfe, 0x20,

    /* U+0022 "\"" */
    0xb6, 0xd0,

    /* U+0023 "#" */
    0x11, 0x8, 0x84, 0x8f, 0xf1, 0x21, 0x10, 0x89,
    0xff, 0x22, 0x11, 0x8, 0x80,

    /* U+0024 "$" */
    0x10, 0x21, 0xf6, 0x89, 0x12, 0x34, 0x1c, 0x16,
    0x24, 0x4c, 0xb7, 0xc2, 0x4, 0x0,

    /* U+0025 "%" */
    0x70, 0x91, 0x22, 0x24, 0x45, 0x8, 0xa0, 0xeb,
    0x82, 0x88, 0x51, 0x12, 0x24, 0x44, 0x87, 0x0,

    /* U+0026 "&" */
    0x38, 0x44, 0x44, 0x4c, 0x38, 0x30, 0x49, 0x85,
    0x86, 0xc7, 0x79,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x49, 0x49, 0x24, 0x92, 0x24, 0x80,

    /* U+0029 ")" */
    0x49, 0x12, 0x49, 0x24, 0xa4, 0x80,

    /* U+002A "*" */
    0x25, 0x5d, 0xf2, 0x0,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0xe0,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x8, 0x44, 0x21, 0x10, 0x84, 0x42, 0x11, 0x8,
    0x40,

    /* U+0030 "0" */
    0x3c, 0x62, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x42, 0x42, 0x3c,

    /* U+0031 "1" */
    0xe4, 0x92, 0x49, 0x24, 0x80,

    /* U+0032 "2" */
    0x3d, 0x8c, 0x8, 0x10, 0x20, 0x82, 0x8, 0x20,
    0x83, 0xf8,

    /* U+0033 "3" */
    0xfe, 0x8, 0x20, 0x41, 0x7, 0x81, 0x81, 0x3,
    0xd, 0xf0,

    /* U+0034 "4" */
    0x4, 0x2, 0x2, 0x2, 0x3, 0x21, 0x11, 0x9,
    0xff, 0x2, 0x1, 0x0, 0x80,

    /* U+0035 "5" */
    0x7e, 0x81, 0x2, 0x4, 0xf, 0x81, 0x81, 0x3,
    0xd, 0xf0,

    /* U+0036 "6" */
    0x3c, 0xc1, 0x4, 0x8, 0x17, 0xb1, 0xc1, 0x82,
    0x8c, 0xf0,

    /* U+0037 "7" */
    0xff, 0x6, 0x10, 0x20, 0xc1, 0x2, 0x8, 0x10,
    0x20, 0x80,

    /* U+0038 "8" */
    0x7c, 0xc6, 0x82, 0x82, 0xc6, 0x7c, 0xc3, 0x81,
    0x81, 0xc3, 0x3c,

    /* U+0039 "9" */
    0x79, 0x8a, 0xc, 0x18, 0x28, 0xde, 0x81, 0x4,
    0x9, 0xe0,

    /* U+003A ":" */
    0x81,

    /* U+003B ";" */
    0x81, 0xc0,

    /* U+003C "<" */
    0xc, 0xcc, 0x18, 0x18, 0x10,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0xc0, 0xc0, 0xc6, 0x62, 0x0,

    /* U+003F "?" */
    0x7d, 0x8c, 0x8, 0x10, 0x61, 0x82, 0x8, 0x0,
    0x0, 0x40,

    /* U+0040 "@" */
    0xf, 0x81, 0x83, 0x18, 0xc, 0x8e, 0xa8, 0x8c,
    0xc8, 0x26, 0x41, 0x32, 0x9, 0x90, 0x4c, 0x46,
    0xd1, 0xdc, 0xc0, 0x3, 0x0, 0x7, 0xc0,

    /* U+0041 "A" */
    0xc, 0x3, 0x1, 0xa0, 0x48, 0x12, 0x8, 0x42,
    0x11, 0xfe, 0x40, 0x90, 0x28, 0x4,

    /* U+0042 "B" */
    0xfe, 0x83, 0x81, 0x81, 0x83, 0xfc, 0x83, 0x81,
    0x81, 0x83, 0xfe,

    /* U+0043 "C" */
    0x1e, 0x10, 0xd0, 0x10, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x40, 0x30, 0xc7, 0x80,

    /* U+0044 "D" */
    0xfc, 0x41, 0xa0, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x81, 0x41, 0xbf, 0x0,

    /* U+0045 "E" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x3, 0xf8,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x40, 0x81,
    0x2, 0x0,

    /* U+0047 "G" */
    0x1f, 0x10, 0xd0, 0x10, 0x8, 0x4, 0x6, 0x3,
    0x1, 0x40, 0x90, 0xc7, 0xc0,

    /* U+0048 "H" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81,
    0x81, 0x81, 0x81,

    /* U+0049 "I" */
    0xff, 0xe0,

    /* U+004A "J" */
    0x7c, 0x10, 0x41, 0x4, 0x10, 0x41, 0x7, 0x37,
    0x80,

    /* U+004B "K" */
    0x83, 0x86, 0x84, 0x88, 0x90, 0xb0, 0xc8, 0xcc,
    0x84, 0x82, 0x81,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x3, 0xf8,

    /* U+004D "M" */
    0x80, 0x70, 0x3c, 0xe, 0x85, 0xa1, 0x64, 0x99,
    0x26, 0x31, 0x8c, 0x60, 0x18, 0x4,

    /* U+004E "N" */
    0x81, 0xc1, 0xe1, 0xa1, 0xb1, 0x99, 0x8d, 0x85,
    0x87, 0x83, 0x81,

    /* U+004F "O" */
    0x1e, 0x18, 0x64, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x40, 0x98, 0x61, 0xe0,

    /* U+0050 "P" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x81, 0x82, 0xfc,
    0x80, 0x80, 0x80,

    /* U+0051 "Q" */
    0x1e, 0x18, 0x64, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x40, 0x98, 0x61, 0xe0, 0x18, 0x3,
    0xc0,

    /* U+0052 "R" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x81, 0x82, 0xfc,
    0x84, 0x82, 0x81,

    /* U+0053 "S" */
    0x7d, 0x82, 0x4, 0xc, 0x7, 0x1, 0x81, 0x3,
    0xd, 0xf0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+0055 "U" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x42, 0x3c,

    /* U+0056 "V" */
    0x80, 0xd0, 0x24, 0x9, 0x84, 0x21, 0x8, 0xc1,
    0x20, 0x48, 0x1c, 0x3, 0x0, 0xc0,

    /* U+0057 "W" */
    0x82, 0x6, 0xc, 0x18, 0x30, 0x91, 0x42, 0x44,
    0x89, 0x12, 0x46, 0x89, 0xa, 0x14, 0x28, 0x70,
    0xc1, 0x81, 0x6, 0x0,

    /* U+0058 "X" */
    0x41, 0x30, 0x88, 0x82, 0x81, 0xc0, 0x40, 0x50,
    0x2c, 0x22, 0x20, 0x90, 0x60,

    /* U+0059 "Y" */
    0x80, 0xa0, 0x98, 0x44, 0x41, 0x40, 0xa0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+005A "Z" */
    0xff, 0x3, 0x2, 0x4, 0x8, 0x18, 0x10, 0x20,
    0x60, 0xc0, 0xff,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0xc0,

    /* U+005C "\\" */
    0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20,
    0x84,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x93, 0xc0,

    /* U+005E "^" */
    0x0, 0xc3, 0x12, 0x49, 0x28, 0x40,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0xc4,

    /* U+0061 "a" */
    0x7a, 0x30, 0x5f, 0x86, 0x18, 0xdd,

    /* U+0062 "b" */
    0x81, 0x2, 0x5, 0xcc, 0x50, 0x60, 0xc1, 0x83,
    0x8a, 0xe0,

    /* U+0063 "c" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x11, 0x9e,

    /* U+0064 "d" */
    0x2, 0x4, 0x9, 0xd4, 0x70, 0x60, 0xc1, 0x82,
    0x8c, 0xe8,

    /* U+0065 "e" */
    0x38, 0x8a, 0xf, 0xf8, 0x10, 0x11, 0x1e,

    /* U+0066 "f" */
    0x3a, 0x11, 0xe4, 0x21, 0x8, 0x42, 0x10,

    /* U+0067 "g" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,
    0x1, 0x42, 0x3c,

    /* U+0068 "h" */
    0x81, 0x2, 0x5, 0xec, 0x70, 0x60, 0xc1, 0x83,
    0x6, 0x8,

    /* U+0069 "i" */
    0x9f, 0xe0,

    /* U+006A "j" */
    0x10, 0x1, 0x11, 0x11, 0x11, 0x11, 0x16,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x28, 0x92, 0x2c, 0x6c, 0x89,
    0xa, 0x8,

    /* U+006C "l" */
    0xff, 0xe0,

    /* U+006D "m" */
    0xbc, 0xf6, 0x38, 0xe0, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0x8, 0x30, 0x41,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+0070 "p" */
    0xb9, 0x8a, 0xc, 0x18, 0x30, 0x71, 0x5c, 0x81,
    0x2, 0x0,

    /* U+0071 "q" */
    0x3a, 0x8e, 0xc, 0x18, 0x30, 0x51, 0x9d, 0x2,
    0x4, 0x8,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88,

    /* U+0073 "s" */
    0x7a, 0x8, 0x38, 0x1c, 0x18, 0x5e,

    /* U+0074 "t" */
    0x42, 0x3c, 0x84, 0x21, 0x8, 0x41, 0xc0,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x71, 0xbd,

    /* U+0076 "v" */
    0x82, 0x42, 0x42, 0x44, 0x24, 0x28, 0x18, 0x18,

    /* U+0077 "w" */
    0x82, 0x14, 0x61, 0x46, 0x24, 0x92, 0x29, 0x22,
    0x94, 0x30, 0xc1, 0xc,

    /* U+0078 "x" */
    0x42, 0xc8, 0xa0, 0xc1, 0x85, 0x11, 0x21,

    /* U+0079 "y" */
    0x82, 0x42, 0x42, 0x44, 0x24, 0x28, 0x18, 0x18,
    0x10, 0x30, 0xe0,

    /* U+007A "z" */
    0xfc, 0x20, 0x84, 0x21, 0x4, 0x3f,

    /* U+007B "{" */
    0x69, 0x24, 0xa2, 0x49, 0x24, 0xc0,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xc9, 0x24, 0x8a, 0x49, 0x25, 0x0,

    /* U+007E "~" */
    0xe6, 0x70,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0x9f, 0xc0,

    /* U+00A2 "¢" */
    0x10, 0x20, 0xf2, 0xb9, 0x12, 0x24, 0x48, 0x56,
    0x78, 0x40, 0x80,

    /* U+00A3 "£" */
    0xf, 0x8, 0x8, 0x4, 0x2, 0x7, 0xf0, 0x80,
    0x40, 0x20, 0x10, 0x3f, 0xc0,

    /* U+00A5 "¥" */
    0x80, 0xa0, 0x90, 0x44, 0x41, 0x40, 0xa1, 0xfc,
    0x10, 0x7f, 0x4, 0x2, 0x0,

    /* U+00A7 "§" */
    0x7a, 0x18, 0x30, 0xfa, 0x18, 0x5b, 0x1c, 0x18,
    0x5e,

    /* U+00A9 "©" */
    0x1e, 0x8, 0x65, 0xca, 0xc9, 0xa0, 0x68, 0x1a,
    0x6, 0xc9, 0x5c, 0x88, 0x41, 0xe0,

    /* U+00AA "ª" */
    0x71, 0xf9, 0xf0,

    /* U+00AB "«" */
    0x4c, 0xa9, 0x24, 0x80,

    /* U+00AC "¬" */
    0xfc, 0x10, 0x41,

    /* U+00AE "®" */
    0x1e, 0x8, 0x65, 0xea, 0x45, 0x91, 0x64, 0x59,
    0xe6, 0x49, 0x51, 0x88, 0x41, 0xe0,

    /* U+00AF "¯" */
    0xf0,

    /* U+00B0 "°" */
    0x74, 0x63, 0x17, 0x0,

    /* U+00B1 "±" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x0, 0x0, 0xfe,

    /* U+00B2 "²" */
    0x70, 0x42, 0x26, 0x7c,

    /* U+00B3 "³" */
    0xf8, 0x88, 0x70, 0xb8,

    /* U+00B4 "´" */
    0x24,

    /* U+00B5 "µ" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x71, 0xdd, 0x81,
    0x2, 0x0,

    /* U+00B6 "¶" */
    0x7f, 0xe7, 0xcf, 0x97, 0x22, 0x44, 0x89, 0x12,
    0x24, 0x48, 0x91, 0x20,

    /* U+00B7 "·" */
    0x80,

    /* U+00B8 "¸" */
    0x47, 0x80,

    /* U+00B9 "¹" */
    0xe1, 0x8, 0x42, 0x7c,

    /* U+00BA "º" */
    0x74, 0x63, 0x17, 0x0,

    /* U+00BB "»" */
    0xa2, 0x92, 0xaa, 0x0,

    /* U+00C0 "À" */
    0x10, 0x2, 0x0, 0x40, 0x30, 0xc, 0x6, 0x81,
    0x20, 0x48, 0x21, 0x8, 0x47, 0xf9, 0x2, 0x40,
    0xa0, 0x10,

    /* U+00C1 "Á" */
    0x2, 0x1, 0x0, 0x80, 0x30, 0xc, 0x6, 0x81,
    0x20, 0x48, 0x21, 0x8, 0x47, 0xf9, 0x2, 0x40,
    0xa0, 0x10,

    /* U+00C2 "Â" */
    0x4, 0x3, 0x1, 0x20, 0x30, 0xc, 0x6, 0x81,
    0x20, 0x48, 0x21, 0x8, 0x47, 0xf9, 0x2, 0x40,
    0xa0, 0x10,

    /* U+00C3 "Ã" */
    0x1a, 0x5, 0x80, 0x40, 0x30, 0xa, 0x4, 0x81,
    0x10, 0x44, 0x21, 0xf, 0xe4, 0x9, 0x3, 0x40,
    0x40,

    /* U+00C4 "Ä" */
    0x12, 0x0, 0x0, 0xc0, 0x30, 0x1a, 0x4, 0x81,
    0x20, 0x84, 0x21, 0x1f, 0xe4, 0x9, 0x2, 0x80,
    0x40,

    /* U+00C5 "Å" */
    0x4, 0x1, 0x40, 0x28, 0x6, 0x0, 0x40, 0x18,
    0x2, 0x80, 0x50, 0x11, 0x2, 0x20, 0x82, 0x1f,
    0xc2, 0x8, 0x80, 0x90, 0x10,

    /* U+00C6 "Æ" */
    0x3, 0xfc, 0x1c, 0x0, 0x50, 0x2, 0x40, 0x9,
    0x0, 0x47, 0xe1, 0x10, 0xf, 0xc0, 0x21, 0x1,
    0x4, 0x4, 0x1f, 0xc0,

    /* U+00C7 "Ç" */
    0x1e, 0x61, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x40, 0x61, 0x1e, 0x8, 0x4, 0x1c,

    /* U+00C8 "È" */
    0x40, 0x40, 0x47, 0xf8, 0x10, 0x20, 0x40, 0xfd,
    0x2, 0x4, 0x8, 0x1f, 0xc0,

    /* U+00C9 "É" */
    0xc, 0x30, 0x87, 0xf8, 0x10, 0x20, 0x40, 0xfd,
    0x2, 0x4, 0x8, 0x1f, 0xc0,

    /* U+00CA "Ê" */
    0x10, 0x51, 0x17, 0xf8, 0x10, 0x20, 0x40, 0xfd,
    0x2, 0x4, 0x8, 0x1f, 0xc0,

    /* U+00CB "Ë" */
    0x48, 0x3, 0xfc, 0x8, 0x10, 0x20, 0x7e, 0x81,
    0x2, 0x4, 0xf, 0xe0,

    /* U+00CC "Ì" */
    0xc8, 0x92, 0x49, 0x24, 0x92, 0x40,

    /* U+00CD "Í" */
    0x6a, 0x49, 0x24, 0x92, 0x49, 0x0,

    /* U+00CE "Î" */
    0x22, 0xa2, 0x42, 0x10, 0x84, 0x21, 0x8, 0x42,
    0x10,

    /* U+00CF "Ï" */
    0x90, 0x22, 0x22, 0x22, 0x22, 0x22, 0x20,

    /* U+00D0 "Ð" */
    0x7e, 0x10, 0x64, 0x9, 0x1, 0x40, 0x7e, 0x14,
    0x5, 0x1, 0x40, 0x90, 0x67, 0xe0,

    /* U+00D1 "Ñ" */
    0x34, 0x4c, 0x81, 0xc1, 0xe1, 0xa1, 0xb1, 0x99,
    0x8d, 0x85, 0x87, 0x83, 0x81,

    /* U+00D2 "Ò" */
    0x10, 0x2, 0x0, 0x40, 0x78, 0x61, 0x90, 0x28,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x5, 0x2, 0x61,
    0x87, 0x80,

    /* U+00D3 "Ó" */
    0x2, 0x1, 0x0, 0x80, 0x78, 0x61, 0x90, 0x28,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x5, 0x2, 0x61,
    0x87, 0x80,

    /* U+00D4 "Ô" */
    0x4, 0x3, 0x1, 0x20, 0x78, 0x61, 0x90, 0x28,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x5, 0x2, 0x61,
    0x87, 0x80,

    /* U+00D5 "Õ" */
    0x1a, 0x6, 0x82, 0x60, 0x78, 0x61, 0x90, 0x28,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x5, 0x2, 0x61,
    0x87, 0x80,

    /* U+00D6 "Ö" */
    0x12, 0x0, 0x1, 0xe1, 0x86, 0x40, 0xa0, 0x18,
    0x6, 0x1, 0x80, 0x60, 0x14, 0x9, 0x86, 0x1e,
    0x0,

    /* U+00D7 "×" */
    0x99, 0x66, 0x90,

    /* U+00D8 "Ø" */
    0x0, 0x87, 0xc6, 0x19, 0xa, 0x82, 0x61, 0x18,
    0x46, 0x21, 0x88, 0x54, 0x27, 0x18, 0xf8, 0x20,
    0x0,

    /* U+00D9 "Ù" */
    0x20, 0x10, 0x8, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+00DA "Ú" */
    0x4, 0x8, 0x10, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+00DB "Û" */
    0x18, 0x18, 0x24, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+00DC "Ü" */
    0x28, 0x0, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+00DD "Ý" */
    0x6, 0x2, 0x2, 0x10, 0x14, 0x13, 0x8, 0x88,
    0x28, 0x14, 0x4, 0x2, 0x1, 0x0, 0x80, 0x40,

    /* U+00DE "Þ" */
    0x80, 0x80, 0xfc, 0x82, 0x81, 0x81, 0x81, 0x82,
    0xfc, 0x80, 0x80,

    /* U+00DF "ß" */
    0x3c, 0x8e, 0xc, 0x18, 0x53, 0xa1, 0xc1, 0x83,
    0xe, 0x70,

    /* U+00E0 "à" */
    0x60, 0x40, 0x1e, 0x8c, 0x17, 0xe1, 0x86, 0x37,
    0x40,

    /* U+00E1 "á" */
    0x8, 0x40, 0x1e, 0x8c, 0x17, 0xe1, 0x86, 0x37,
    0x40,

    /* U+00E2 "â" */
    0x31, 0x20, 0x1e, 0x8c, 0x17, 0xe1, 0x86, 0x37,
    0x40,

    /* U+00E3 "ã" */
    0x69, 0x60, 0x1e, 0x8c, 0x17, 0xe1, 0x86, 0x37,
    0x40,

    /* U+00E4 "ä" */
    0x48, 0x0, 0x1e, 0x8c, 0x17, 0xe1, 0x86, 0x37,
    0x40,

    /* U+00E5 "å" */
    0x38, 0xa3, 0x80, 0x7a, 0x30, 0x5f, 0x86, 0x18,
    0xdd,

    /* U+00E6 "æ" */
    0x79, 0xc8, 0xe2, 0x4, 0x17, 0xff, 0x84, 0x8,
    0x40, 0x8a, 0x27, 0x1e,

    /* U+00E7 "ç" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x11, 0x9e, 0x10,
    0x10, 0xe0,

    /* U+00E8 "è" */
    0x20, 0x20, 0x1, 0xc4, 0x50, 0x7f, 0xc0, 0x80,
    0x88, 0xf0,

    /* U+00E9 "é" */
    0x8, 0x20, 0x1, 0xc4, 0x50, 0x7f, 0xc0, 0x80,
    0x88, 0xf0,

    /* U+00EA "ê" */
    0x30, 0x10, 0x1, 0xc4, 0x50, 0x7f, 0xc0, 0x80,
    0x88, 0xf0,

    /* U+00EB "ë" */
    0x68, 0x0, 0x1, 0xc4, 0x50, 0x7f, 0xc0, 0x80,
    0x88, 0xf0,

    /* U+00EC "ì" */
    0x44, 0x12, 0x49, 0x24, 0x80,

    /* U+00ED "í" */
    0x50, 0x49, 0x24, 0x92, 0x0,

    /* U+00EE "î" */
    0xd4, 0x24, 0x92, 0x49, 0x0,

    /* U+00EF "ï" */
    0xe0, 0x24, 0x92, 0x49, 0x0,

    /* U+00F0 "ð" */
    0x0, 0x68, 0x63, 0x40, 0x4f, 0xb1, 0xc1, 0x83,
    0x5, 0x13, 0xc0,

    /* U+00F1 "ñ" */
    0x34, 0xb0, 0x5, 0xec, 0x70, 0x60, 0xc1, 0x83,
    0x6, 0x8,

    /* U+00F2 "ò" */
    0x20, 0x20, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+00F3 "ó" */
    0x8, 0x20, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+00F4 "ô" */
    0x30, 0x10, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+00F5 "õ" */
    0x38, 0xb0, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+00F6 "ö" */
    0x28, 0x0, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+00F7 "÷" */
    0x20, 0x1, 0xf0, 0x0, 0x80,

    /* U+00F8 "ø" */
    0x4, 0x71, 0x34, 0x99, 0x32, 0x68, 0xb2, 0x38,
    0x80,

    /* U+00F9 "ù" */
    0x20, 0x20, 0x4, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x8d, 0xe8,

    /* U+00FA "ú" */
    0x8, 0x20, 0x4, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x8d, 0xe8,

    /* U+00FB "û" */
    0x38, 0x88, 0x4, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x8d, 0xe8,

    /* U+00FC "ü" */
    0x2c, 0x0, 0x4, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x8d, 0xe8,

    /* U+00FD "ý" */
    0x8, 0x10, 0x0, 0x82, 0x42, 0x42, 0x44, 0x24,
    0x28, 0x18, 0x18, 0x10, 0x30, 0xe0,

    /* U+00FE "þ" */
    0x81, 0x2, 0x5, 0xcc, 0x50, 0x60, 0xc1, 0x83,
    0x8a, 0xe4, 0x8, 0x10, 0x0,

    /* U+00FF "ÿ" */
    0x28, 0x0, 0x0, 0x82, 0x42, 0x42, 0x44, 0x24,
    0x28, 0x18, 0x18, 0x10, 0x30, 0xe0,

    /* U+0152 "Œ" */
    0x1f, 0xfd, 0x84, 0x4, 0x10, 0x20, 0x40, 0x81,
    0x2, 0x7, 0xe8, 0x10, 0x20, 0x40, 0x41, 0x1,
    0x84, 0x1, 0xff, 0xc0,

    /* U+0153 "œ" */
    0x38, 0xf1, 0x14, 0x28, 0x20, 0x60, 0xff, 0x82,
    0x2, 0x8, 0x4, 0x50, 0x8e, 0x3c,

    /* U+0160 "Š" */
    0x44, 0x50, 0x43, 0xec, 0x10, 0x20, 0x60, 0x38,
    0xc, 0x8, 0x18, 0x6f, 0x80,

    /* U+0161 "š" */
    0x48, 0xc0, 0x1e, 0x82, 0xe, 0x7, 0x6, 0x17,
    0x80,

    /* U+0178 "Ÿ" */
    0x14, 0x0, 0x20, 0x28, 0x26, 0x11, 0x10, 0x50,
    0x28, 0x8, 0x4, 0x2, 0x1, 0x0, 0x80,

    /* U+20AC "€" */
    0xf, 0x4, 0x32, 0x1, 0x0, 0xfe, 0x10, 0xf,
    0xe1, 0x0, 0x20, 0xc, 0x30, 0xf0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 59, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 58, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 84, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 5, .adv_w = 156, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 138, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 32, .adv_w = 186, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 45, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 60, .adv_w = 74, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 66, .adv_w = 74, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 72, .adv_w = 86, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 76, .adv_w = 129, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 83, .adv_w = 47, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 84, .adv_w = 86, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 85, .adv_w = 47, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 75, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 95, .adv_w = 148, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 81, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 126, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 148, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 132, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 143, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 47, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 47, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 198, .adv_w = 129, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 203, .adv_w = 129, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 206, .adv_w = 129, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 211, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 231, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 244, .adv_w = 161, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 169, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 159, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 185, .box_w = 9, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 295, .adv_w = 150, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 173, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 182, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 68, .box_w = 1, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 159, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 132, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 214, .box_w = 10, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 182, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 161, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 188, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 438, .adv_w = 162, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 138, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 129, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 177, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 156, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 249, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 147, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 142, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 540, .adv_w = 146, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 71, .box_w = 3, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 557, .adv_w = 75, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 566, .adv_w = 71, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 572, .adv_w = 129, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 578, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 579, .adv_w = 134, .box_w = 3, .box_h = 2, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 580, .adv_w = 132, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 126, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 135, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 620, .adv_w = 76, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 627, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 638, .adv_w = 151, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 648, .adv_w = 60, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 61, .box_w = 4, .box_h = 14, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 657, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 60, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 669, .adv_w = 238, .box_w = 13, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 682, .adv_w = 151, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 689, .adv_w = 140, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 706, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 716, .adv_w = 90, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 109, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 726, .adv_w = 91, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 733, .adv_w = 151, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 740, .adv_w = 121, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 197, .box_w = 12, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 120, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 767, .adv_w = 121, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 778, .adv_w = 114, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 790, .adv_w = 66, .box_w = 1, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 792, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 798, .adv_w = 129, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 800, .adv_w = 59, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 58, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 803, .adv_w = 126, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 814, .adv_w = 143, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 827, .adv_w = 156, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 110, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 849, .adv_w = 181, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 863, .adv_w = 90, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 866, .adv_w = 107, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 870, .adv_w = 129, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 873, .adv_w = 181, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 887, .adv_w = 134, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 888, .adv_w = 94, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 892, .adv_w = 129, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 900, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 904, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 908, .adv_w = 134, .box_w = 4, .box_h = 2, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 909, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 919, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 931, .adv_w = 56, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 932, .adv_w = 134, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 934, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 938, .adv_w = 93, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 942, .adv_w = 107, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 946, .adv_w = 161, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 964, .adv_w = 161, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 982, .adv_w = 161, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1000, .adv_w = 161, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1017, .adv_w = 161, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1034, .adv_w = 161, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1055, .adv_w = 231, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1075, .adv_w = 159, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1089, .adv_w = 150, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1102, .adv_w = 150, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1115, .adv_w = 150, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1128, .adv_w = 150, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1140, .adv_w = 68, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1146, .adv_w = 68, .box_w = 3, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1152, .adv_w = 68, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1161, .adv_w = 68, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1168, .adv_w = 186, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1182, .adv_w = 182, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1195, .adv_w = 188, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1213, .adv_w = 188, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1231, .adv_w = 188, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1249, .adv_w = 188, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1267, .adv_w = 188, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1284, .adv_w = 129, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 1287, .adv_w = 188, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1304, .adv_w = 177, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1318, .adv_w = 177, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1332, .adv_w = 177, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1346, .adv_w = 177, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1359, .adv_w = 142, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1375, .adv_w = 161, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1386, .adv_w = 150, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1396, .adv_w = 132, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1405, .adv_w = 132, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1414, .adv_w = 132, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1423, .adv_w = 132, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1432, .adv_w = 132, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1441, .adv_w = 132, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1450, .adv_w = 221, .box_w = 12, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1462, .adv_w = 126, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1472, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1482, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1492, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1502, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1512, .adv_w = 60, .box_w = 3, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1517, .adv_w = 60, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1522, .adv_w = 60, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1527, .adv_w = 60, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1532, .adv_w = 132, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1543, .adv_w = 151, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1553, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1563, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1573, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1583, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1593, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1603, .adv_w = 129, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1608, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1617, .adv_w = 151, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1627, .adv_w = 151, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1637, .adv_w = 151, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1647, .adv_w = 151, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1657, .adv_w = 121, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1671, .adv_w = 152, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1684, .adv_w = 121, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1698, .adv_w = 251, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1718, .adv_w = 239, .box_w = 14, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1732, .adv_w = 138, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1745, .adv_w = 109, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1754, .adv_w = 142, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1769, .adv_w = 177, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_1[] = {
    0, 1, 2, 3, 0, 4, 0, 5,
    0, 6, 7, 8, 9, 0, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23
};

static const uint16_t unicode_list_3[] = {
    0x0, 0x1, 0xe, 0xf, 0x26, 0x1f5a
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 28, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_1, .list_length = 28, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 192, .range_length = 64, .glyph_id_start = 120,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 338, .range_length = 8027, .glyph_id_start = 184,
        .unicode_list = unicode_list_3, .glyph_id_ofs_list = NULL, .list_length = 6, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t Monserat14_ISO_8859_15 = {
#else
lv_font_t Monserat14_ISO_8859_15 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if MONSERAT14_ISO_8859_15*/
