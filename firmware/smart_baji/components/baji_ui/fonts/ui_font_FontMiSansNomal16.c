/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font F:/baji_ui/assets/MiSans-Normal.ttf -o F:/baji_ui/assets\ui_font_FontMiSansNomal16.c --format lvgl -r 0x20-0x7f --symbols 设置吧唧 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONTMISANSNOMAL16
#define UI_FONT_FONTMISANSNOMAL16 1
#endif

#if UI_FONT_FONTMISANSNOMAL16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0x10,

    /* U+0022 "\"" */
    0xb6, 0xd0,

    /* U+0023 "#" */
    0x9, 0x2, 0x41, 0x11, 0xff, 0x12, 0x4, 0x81,
    0x23, 0xfe, 0x22, 0x9, 0x82, 0x40, 0x90,

    /* U+0024 "$" */
    0x10, 0x21, 0xf6, 0xb9, 0x12, 0x24, 0x38, 0x38,
    0x2c, 0x48, 0x99, 0x3f, 0x8e, 0x8,

    /* U+0025 "%" */
    0x70, 0x24, 0x43, 0x22, 0x31, 0x13, 0x7, 0x10,
    0x1, 0x0, 0x1b, 0xc0, 0xb3, 0x9, 0x8, 0x88,
    0x4c, 0x66, 0x41, 0xe0,

    /* U+0026 "&" */
    0x1c, 0xc, 0x82, 0x20, 0x88, 0x34, 0x6, 0x6,
    0x82, 0x12, 0x87, 0x20, 0xcc, 0x71, 0xe2,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x69, 0x69, 0x24, 0x92, 0x64, 0x98,

    /* U+0029 ")" */
    0xc9, 0x32, 0x49, 0x24, 0xb4, 0xb0,

    /* U+002A "*" */
    0x27, 0xc9, 0xf2, 0x0,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0xe0,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x10, 0x84, 0x62, 0x11, 0x88, 0x46, 0x21, 0x0,

    /* U+0030 "0" */
    0x3c, 0x46, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x42, 0x46, 0x3c,

    /* U+0031 "1" */
    0x3f, 0x91, 0x11, 0x11, 0x11, 0x11,

    /* U+0032 "2" */
    0x3d, 0x8e, 0x8, 0x10, 0x20, 0x83, 0xc, 0x30,
    0xc1, 0x7, 0xf0,

    /* U+0033 "3" */
    0xfe, 0x8, 0x30, 0xc3, 0xf, 0x81, 0x81, 0x3,
    0x7, 0x13, 0xc0,

    /* U+0034 "4" */
    0x6, 0xe, 0xa, 0x1a, 0x32, 0x22, 0x62, 0xc2,
    0xff, 0x2, 0x2, 0x2,

    /* U+0035 "5" */
    0xfd, 0x83, 0x4, 0xb, 0x98, 0x80, 0x81, 0x3,
    0x7, 0x13, 0xc0,

    /* U+0036 "6" */
    0x8, 0x10, 0x30, 0x20, 0x7c, 0x42, 0x81, 0x81,
    0x81, 0x81, 0x42, 0x3c,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x20, 0x81, 0x6, 0x8, 0x30,
    0x40, 0x83, 0x0,

    /* U+0038 "8" */
    0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x42, 0x81,
    0x81, 0x81, 0x42, 0x3c,

    /* U+0039 "9" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x43, 0x3e, 0x6,
    0x4, 0xc, 0x18, 0x10,

    /* U+003A ":" */
    0x80, 0x80,

    /* U+003B ";" */
    0x80, 0xe0,

    /* U+003C "<" */
    0x0, 0xc, 0x73, 0x8c, 0x18, 0xc, 0x6, 0x6,

    /* U+003D "=" */
    0xfe, 0x0, 0x0, 0xf, 0xe0,

    /* U+003E ">" */
    0x1, 0x81, 0xc0, 0xe0, 0x60, 0xc6, 0x30, 0xc0,

    /* U+003F "?" */
    0x3c, 0x8c, 0x8, 0x10, 0x61, 0x86, 0x8, 0x10,
    0x0, 0x0, 0x80,

    /* U+0040 "@" */
    0xf, 0x83, 0xc, 0x40, 0x24, 0xeb, 0x99, 0x99,
    0x9, 0x90, 0x99, 0x99, 0xcf, 0x64, 0x0, 0x30,
    0x1, 0xf8,

    /* U+0041 "A" */
    0xc, 0x3, 0x0, 0xe0, 0x68, 0x13, 0x4, 0xc3,
    0x10, 0xfe, 0x60, 0x98, 0x24, 0xf, 0x1,

    /* U+0042 "B" */
    0xfe, 0x83, 0x81, 0x81, 0x83, 0xfe, 0x83, 0x81,
    0x81, 0x81, 0x82, 0xfc,

    /* U+0043 "C" */
    0x1f, 0x10, 0xd0, 0x10, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x80, 0x20, 0x8, 0x63, 0xe0,

    /* U+0044 "D" */
    0xfe, 0x20, 0x48, 0xa, 0x3, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x60, 0x28, 0x13, 0xf8,

    /* U+0045 "E" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xe0, 0x40, 0x81,
    0x2, 0x7, 0xf0,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x2, 0x4, 0x0,

    /* U+0047 "G" */
    0x1f, 0x8, 0x34, 0x3, 0x0, 0x80, 0x20, 0xf8,
    0x6, 0x1, 0x80, 0x50, 0x12, 0x8, 0x7c,

    /* U+0048 "H" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xf, 0xfe, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x30, 0x10,

    /* U+0049 "I" */
    0xff, 0xf0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x41, 0x4, 0x14,
    0x5e,

    /* U+004B "K" */
    0x83, 0x43, 0x23, 0x13, 0xb, 0x7, 0x83, 0x61,
    0x10, 0x8c, 0x43, 0x20, 0x90, 0x20,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x2, 0x7, 0xf0,

    /* U+004D "M" */
    0x80, 0x38, 0xf, 0x83, 0xd0, 0x5b, 0x1b, 0x22,
    0x62, 0x8c, 0x71, 0x84, 0x30, 0x6, 0x0, 0xc0,
    0x10,

    /* U+004E "N" */
    0x80, 0xe0, 0x78, 0x36, 0x19, 0xc, 0xc6, 0x33,
    0x9, 0x86, 0xc1, 0xe0, 0x70, 0x10,

    /* U+004F "O" */
    0x1f, 0x4, 0x11, 0x1, 0x40, 0x18, 0x3, 0x0,
    0x60, 0xc, 0x1, 0x80, 0x28, 0x8, 0x82, 0xf,
    0x80,

    /* U+0050 "P" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x82, 0xfc, 0x80,
    0x80, 0x80, 0x80, 0x80,

    /* U+0051 "Q" */
    0x1f, 0x4, 0x11, 0x1, 0x40, 0x38, 0x3, 0x0,
    0x60, 0xc, 0x1, 0x81, 0x68, 0x38, 0x83, 0xf,
    0xa0, 0x2,

    /* U+0052 "R" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x82, 0xfc, 0x8c,
    0x84, 0x82, 0x83, 0x81,

    /* U+0053 "S" */
    0x3c, 0x43, 0x80, 0x80, 0xc0, 0x78, 0xe, 0x3,
    0x1, 0x81, 0xc3, 0x3c,

    /* U+0054 "T" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0,

    /* U+0055 "U" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xe0, 0xd8, 0xc7, 0xc0,

    /* U+0056 "V" */
    0xc0, 0x50, 0x34, 0x9, 0x82, 0x21, 0x8c, 0x41,
    0x10, 0x4c, 0x1a, 0x2, 0x80, 0xc0, 0x30,

    /* U+0057 "W" */
    0xc1, 0x2, 0x83, 0xd, 0xa, 0x12, 0x14, 0x26,
    0x2c, 0x44, 0xc9, 0x89, 0x12, 0x1a, 0x24, 0x14,
    0x38, 0x30, 0x60, 0x60, 0xc0, 0xc1, 0x80,

    /* U+0058 "X" */
    0x40, 0x88, 0x43, 0x30, 0x48, 0xc, 0x3, 0x0,
    0xc0, 0x58, 0x32, 0x8, 0x46, 0x19, 0x2,

    /* U+0059 "Y" */
    0xc1, 0xa0, 0x98, 0xc4, 0x43, 0x60, 0xa0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0,

    /* U+005A "Z" */
    0xff, 0x3, 0x6, 0x4, 0xc, 0x8, 0x10, 0x30,
    0x20, 0x60, 0xc0, 0xff,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0x38,

    /* U+005C "\\" */
    0xc2, 0x10, 0xc2, 0x10, 0xc2, 0x10, 0x86, 0x10,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x92, 0x78,

    /* U+005E "^" */
    0x10, 0x70, 0xa2, 0x24, 0x40,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0x48, 0x80,

    /* U+0061 "a" */
    0x3c, 0x8c, 0x8, 0x13, 0xf8, 0x60, 0xc3, 0x7a,

    /* U+0062 "b" */
    0x80, 0x80, 0x80, 0xbc, 0xc2, 0x83, 0x81, 0x81,
    0x81, 0x83, 0xc2, 0xbc,

    /* U+0063 "c" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x20, 0x23, 0x3c,

    /* U+0064 "d" */
    0x1, 0x1, 0x1, 0x3d, 0x43, 0xc3, 0x81, 0x81,
    0x81, 0x81, 0x43, 0x3d,

    /* U+0065 "e" */
    0x38, 0x8a, 0xc, 0x1f, 0xf0, 0x20, 0x23, 0x3c,

    /* U+0066 "f" */
    0x3a, 0x11, 0xf4, 0x21, 0x8, 0x42, 0x10, 0x80,

    /* U+0067 "g" */
    0x3d, 0x43, 0xc1, 0x81, 0x81, 0x81, 0x81, 0x43,
    0x3d, 0x1, 0xc2, 0x3c,

    /* U+0068 "h" */
    0x81, 0x2, 0x5, 0xec, 0x70, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x10,

    /* U+0069 "i" */
    0x9f, 0xf0,

    /* U+006A "j" */
    0x20, 0x12, 0x49, 0x24, 0x92, 0x70,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x69, 0x96, 0x28, 0x78, 0x91,
    0x32, 0x34, 0x20,

    /* U+006C "l" */
    0xaa, 0xaa, 0xab,

    /* U+006D "m" */
    0xb9, 0xd9, 0xce, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xc, 0x21, 0x84, 0x20,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x82,

    /* U+006F "o" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81, 0x42,
    0x3c,

    /* U+0070 "p" */
    0xbc, 0xc2, 0xc3, 0x81, 0x81, 0x81, 0x83, 0xc2,
    0xbc, 0x80, 0x80, 0x80,

    /* U+0071 "q" */
    0x3d, 0x43, 0xc3, 0x81, 0x81, 0x81, 0xc1, 0x43,
    0x3d, 0x1, 0x1, 0x1,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88, 0x80,

    /* U+0073 "s" */
    0x7a, 0x38, 0x30, 0x78, 0x30, 0x61, 0x78,

    /* U+0074 "t" */
    0x42, 0x11, 0xf4, 0x21, 0x8, 0x42, 0x10, 0x70,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xe3, 0x7a,

    /* U+0076 "v" */
    0xc3, 0x42, 0x42, 0x66, 0x24, 0x24, 0x3c, 0x18,
    0x18,

    /* U+0077 "w" */
    0xc6, 0x14, 0x61, 0x45, 0x34, 0x52, 0x69, 0x22,
    0x9a, 0x28, 0xc3, 0x8c, 0x10, 0xc0,

    /* U+0078 "x" */
    0x42, 0x64, 0x24, 0x18, 0x18, 0x38, 0x24, 0x66,
    0xc2,

    /* U+0079 "y" */
    0xc3, 0x42, 0x42, 0x66, 0x24, 0x24, 0x18, 0x18,
    0x18, 0x10, 0x10, 0x30,

    /* U+007A "z" */
    0xfe, 0xc, 0x30, 0xc1, 0x6, 0x18, 0x60, 0xfe,

    /* U+007B "{" */
    0x19, 0x8, 0x42, 0x11, 0x98, 0x61, 0x8, 0x42,
    0x10, 0x60,

    /* U+007C "|" */
    0xff, 0xfe,

    /* U+007D "}" */
    0xc1, 0x8, 0x42, 0x10, 0xc3, 0x31, 0x8, 0x42,
    0x13, 0x0,

    /* U+007E "~" */
    0x67, 0x38,

    /* U+007F "" */
    0x0,

    /* U+5427 "吧" */
    0x7, 0xf7, 0xa4, 0xa5, 0x25, 0x29, 0x29, 0x49,
    0x4a, 0x4a, 0x5f, 0xd2, 0x80, 0x94, 0x4, 0xa0,
    0x3d, 0x3, 0x8, 0x10, 0x41, 0x81, 0xf8,

    /* U+5527 "唧" */
    0xf, 0x7, 0x4b, 0xea, 0x53, 0x5e, 0x9a, 0x94,
    0xd4, 0xa6, 0xa5, 0x35, 0xe9, 0xa8, 0x4d, 0x4a,
    0x7a, 0xdf, 0x1a, 0x88, 0x8c, 0x0, 0x20,

    /* U+7F6E "置" */
    0x7f, 0xf9, 0x12, 0x27, 0xff, 0x80, 0xc0, 0x7f,
    0xf8, 0xc, 0x3, 0xff, 0x8, 0x4, 0x3f, 0xf0,
    0x80, 0x43, 0xff, 0xf, 0xfc, 0x20, 0x13, 0xff,
    0xf0,

    /* U+8BBE "设" */
    0x0, 0x1, 0x87, 0xc3, 0x11, 0x6, 0x44, 0x3,
    0x10, 0x18, 0x7e, 0x0, 0x8, 0xfe, 0x22, 0x8,
    0x84, 0x42, 0x1b, 0xb, 0x38, 0x38, 0xe0, 0x8c,
    0x60, 0xc0, 0x40
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 74, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 67, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 85, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 5, .adv_w = 181, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 147, .box_w = 7, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 34, .adv_w = 210, .box_w = 13, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 179, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 49, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 70, .adv_w = 77, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 76, .adv_w = 77, .box_w = 3, .box_h = 15, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 82, .adv_w = 113, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 86, .adv_w = 154, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 93, .adv_w = 65, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 94, .adv_w = 115, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 95, .adv_w = 62, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 100, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 101, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 151, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 153, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 133, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 159, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 152, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 62, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 65, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 218, .adv_w = 154, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 226, .adv_w = 154, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 231, .adv_w = 154, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 239, .adv_w = 125, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 211, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 168, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 169, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 295, .adv_w = 178, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 190, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 152, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 346, .adv_w = 188, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 61, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 120, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 164, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 143, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 223, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 187, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 200, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 158, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 200, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 489, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 501, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 153, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 179, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 168, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 243, .box_w = 15, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 579, .adv_w = 159, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 594, .adv_w = 158, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 608, .adv_w = 151, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 620, .adv_w = 89, .box_w = 3, .box_h = 15, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 626, .adv_w = 87, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 89, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 640, .adv_w = 112, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 645, .adv_w = 116, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 646, .adv_w = 66, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 648, .adv_w = 137, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 656, .adv_w = 153, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 668, .adv_w = 136, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 153, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 143, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 88, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 153, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 716, .adv_w = 148, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 727, .adv_w = 62, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 729, .adv_w = 62, .box_w = 3, .box_h = 15, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 735, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 746, .adv_w = 62, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 749, .adv_w = 226, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 148, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 770, .adv_w = 147, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 779, .adv_w = 153, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 791, .adv_w = 153, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 803, .adv_w = 95, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 808, .adv_w = 120, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 89, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 823, .adv_w = 148, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 129, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 201, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 854, .adv_w = 123, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 863, .adv_w = 130, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 875, .adv_w = 122, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 883, .adv_w = 89, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 893, .adv_w = 56, .box_w = 1, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 895, .adv_w = 89, .box_w = 5, .box_h = 15, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 905, .adv_w = 133, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 907, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 908, .adv_w = 256, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 931, .adv_w = 256, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 954, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 979, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x100, 0x2b47, 0x3797
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 96, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 21543, .range_length = 14232, .glyph_id_start = 97,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 2,
    1, 0, 0, 0, 0, 3, 4, 3,
    5, 6, 0, 7, 8, 9, 10, 11,
    12, 13, 14, 0, 0, 0, 0, 0,
    15, 0, 16, 17, 18, 19, 20, 21,
    22, 0, 0, 23, 24, 25, 0, 0,
    19, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 0, 0, 0, 0,
    0, 0, 37, 38, 39, 0, 40, 41,
    42, 43, 0, 0, 44, 45, 43, 43,
    38, 38, 42, 46, 47, 48, 42, 49,
    50, 51, 49, 52, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 2,
    1, 0, 0, 0, 0, 3, 4, 3,
    5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 0, 0, 0, 0, 0,
    16, 0, 17, 0, 18, 0, 0, 0,
    18, 0, 0, 19, 0, 0, 0, 0,
    18, 0, 18, 0, 20, 21, 22, 23,
    24, 25, 26, 27, 0, 0, 0, 0,
    0, 0, 28, 0, 29, 29, 29, 30,
    29, 0, 31, 31, 0, 32, 33, 33,
    29, 33, 29, 33, 34, 35, 36, 37,
    38, 39, 37, 40, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -23, 0, -15, 5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -7, -4, -23, -6, -23, -14,
    0, -25, 0, -4, -2, 1, 0, -5,
    0, 0, -6, 0, -9, -7, 0, 0,
    0, 0, 0, 0, 0, -9, -23, 0,
    0, -12, -5, -5, -8, -2, -26, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -7,
    0, 0, 0, 0, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -18, 0, -13, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -9, 0, 0, 0, 0, -8,
    -4, 0, 0, 0, -5, 0, 0, 0,
    -7, 0, -7, 0, -9, 0, -7, -4,
    0, -13, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, -4, 0, 0,
    -7, -9, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, 0, 0, 0, 0, -5,
    0, 0, 0, 0, 0, 0, -3, -7,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, -7, 0,
    -5, 0, 0, 0, -7, 0, -5, -8,
    0, 0, 0, 0, -7, 0, -10, 0,
    0, -10, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, 0, 0, 0, -7, 0,
    0, 0, 0, 0, -5, 0, 0, -11,
    0, 0, 0, 0, 0, 0, -6, 0,
    -6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -18, 0, -5, 0, 0, 0, -15, 0,
    0, 0, 0, 0, -14, 0, -3, -17,
    0, 0, 0, 0, -25, 0, -20, 0,
    -4, -27, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -9, 0, -6, -5,
    5, 0, -36, -7, -24, -5, 0, 0,
    0, -19, 0, -18, 1, -8, 0, 3,
    -24, 0, -27, 0, 0, 0, 0, 0,
    0, 0, 0, -22, -21, -7, 0, 0,
    -12, -15, 0, -10, 0, 0, -10, -10,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, -6, -5,
    0, 0, 0, 0, -6, 0, -4, 0,
    0, -9, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    0, 0, -28, 0, -13, 0, 0, 0,
    0, -8, 0, -7, 0, -5, 0, 0,
    -18, 0, -21, 0, 0, 0, -2, 0,
    -10, -5, 0, -10, -7, 2, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -13, -5, -8, 3, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -23, -3, 0, -10, 0, -7, -15, 0,
    0, 0, 0, 0, 0, 0, -18, -19,
    0, -9, 0, 0, -24, -4, -25, -17,
    0, -25, 0, 0, -4, -2, 0, -1,
    0, 0, -6, -3, -12, -8, 0, 0,
    -7, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    -5, 0, -2, 0, -6, 0, -10, -5,
    -5, -9, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, -1, -2,
    0, 0, 0, -10, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, 0, 0, -1, 0, 0, 0,
    -5, -7, -3, -3, -5, 0, 0, 0,
    0, 0, 0, 0, -5, -5, -3, 0,
    -5, 0, -10, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    -9, 0, -15, 0, -8, 0, -9, -4,
    -9, -13, -9, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, -3, 0, 0,
    5, -7, -17, 0, 0, 0, 0, 0,
    0, -7, 0, -8, 0, 0, 0, 0,
    -16, 0, -40, -3, 0, 0, 0, 0,
    -5, 0, 0, -13, -9, 0, 0, 0,
    -5, -4, 0, -5, -3, -2, -9, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    -6, 0, 0, 0, -8, 0, -10, -4,
    -4, -12, -3, 0, 0, 0, 0, 0,
    0, -2, 0, 0, -7, -8, -5, 0,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -9, 5, -22, 0, -11, -7, 0,
    0, -7, 0, 0, 0, 0, -11, -8,
    0, -14, -6, -6, 0, -13, 0, 0,
    0, 0, 0, -7, -13, -7, 0, -5,
    -2, -3, -13, -13, -17, -16, 6, 0,
    -23, 0, 7, -23, 0, 0, -17, 0,
    0, 0, 0, 0, -6, 0, -30, -23,
    0, -10, 0, 0, -40, -7, -34, -21,
    0, -44, 0, 0, -5, -6, 0, 0,
    0, 0, -9, -6, -20, -13, 0, 0,
    0, -10, -25, 0, 0, 0, 0, -1,
    0, -7, 0, 0, 0, 0, 0, 0,
    -19, 0, -44, 0, -5, 0, -6, -5,
    -6, -8, -5, -8, -6, 6, 0, 0,
    0, 1, 6, 1, 8, 8, 3, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -7, 0, 0, 0, -8, 0, -6, -6,
    -11, -13, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -7, 0, -5, 0, -4, -2,
    0, -5, 0, -4, -5, 0, 0, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, -2, 1,
    -2, -7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, -5, -3, -4,
    5, -18, -27, -21, 0, -9, 0, 0,
    0, -26, 0, -20, 0, -6, 0, 0,
    -24, -8, -35, -3, 0, 0, -5, 0,
    -7, 0, 0, -30, -30, -10, 0, 0,
    -22, -28, -6, -20, -28, -26, -27, -24,
    0, 0, -9, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, 0, -9, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -17, -33, -10, 0, -7, 0, 0,
    0, -16, -5, -13, 0, -4, 0, 0,
    -25, -9, -38, 1, 0, 0, 0, 0,
    0, 0, 0, -21, -18, -3, 0, 0,
    -12, -15, -2, -10, -7, -7, -9, -8,
    0, -10, -22, -7, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -17, -4, -26, 3, 0, 0, 0, 0,
    0, 0, 0, -16, -13, -3, 0, 0,
    -9, -12, 1, -11, -2, -5, -7, -5,
    0, -6, 3, -19, 0, 0, -7, 0,
    -3, -5, -6, -5, 0, 0, -11, -5,
    0, -9, -1, -1, -7, -4, 0, 0,
    0, 0, 0, -4, -7, -4, 0, -2,
    0, -7, -9, -10, -13, -14, 0, 0,
    0, -20, -29, -17, 0, -13, 0, -5,
    -2, -26, 0, -22, 0, -9, -4, 0,
    -25, -13, -44, -5, 0, 0, 0, 0,
    0, 0, 0, -26, -26, -9, 0, 0,
    -19, -22, -7, -20, -10, -11, -12, -15,
    0, -10, 0, -13, 0, 0, 0, 0,
    0, -12, 0, 0, 0, 0, 0, 0,
    0, -13, 0, 0, 0, -5, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, -7, -8, -11, -10, 0, 0,
    -10, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -13, 0, -4, -13,
    0, 0, 0, 0, -27, 0, -18, -14,
    0, -23, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, -3, 0, 0,
    -10, 0, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -14, 0, -7, -18,
    -4, 0, 0, 0, -30, 0, -18, -13,
    -7, -26, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, -3, -5, -2,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -7,
    0, 0, 0, 0, -28, 0, -14, -8,
    -4, -27, 0, -2, -3, 0, -2, -1,
    0, 0, 0, 0, -2, 0, -5, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -13, 0, 0, -13,
    0, 0, 0, 0, -26, 0, -16, -10,
    -8, -21, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -1, -4, 0,
    7, -8, -17, 0, 0, 0, 0, 0,
    0, -11, 0, 0, 6, 0, 5, 0,
    -15, 0, -18, 0, 0, 0, 0, 0,
    0, 0, 0, -5, -4, 0, 0, 0,
    0, -4, 2, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -8, 0, 0, -7,
    0, 0, 0, 0, -22, 0, -12, -10,
    -2, -19, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -8, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -10, 0, -5, -13,
    0, 0, 0, 0, -30, 0, -20, -15,
    -5, -26, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, -2, -2, 0,
    -5, -4, 3, -7, 0, 0, 0, 0,
    0, -7, 0, -5, 0, -6, -2, -5,
    0, -5, 0, 0, -25, -3, -11, -5,
    0, -19, 0, -2, -6, 0, 0, -1,
    0, -3, -2, -4, 0, 0, 0, 0,
    0, -5, 4, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 0, 0,
    2, 0, 0, 1, -2, -2, 0, 0,
    0, -12, -26, 0, 0, 0, 0, -4,
    -13, -13, 0, -7, 0, 0, 3, 0,
    0, 0, 0, 0, -23, 0, 0, 0,
    -10, -8, -13, -6, -3, 3, 0, 0,
    0, -2, 4, -4, 5, 6, 3, 0,
    -8, 0, 0, 0, 0, 0, -7, 0,
    0, 0, 0, 0, -7, 0, 0, -8,
    0, 0, 0, 0, -27, 0, -14, -11,
    -5, -19, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, -6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, 0, 0, 0, 0, 4, 0,
    0, 0, 0, 0, -5, 0, -4, 1,
    0, -12, 0, 0, -2, 3, 0, 0,
    0, -2, 0, -1, 0, 0, 0, 0,
    0, -10, -20, 0, 0, 0, 0, 0,
    0, -7, 0, -7, 0, 0, 0, 0,
    -12, 0, -23, 0, -28, 0, -7, -2,
    -13, -10, -13, -6, -3, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, -6, -13, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -8, 0, -19, 0, -26, 0, -7, -5,
    -14, -11, -10, -5, -3, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, -3, 0, -5, 0, 0, 0, 0,
    0, -9, 0, -6, -7, -5, 0, 0,
    0, -3, 0, 0, -27, 0, -9, -7,
    4, -12, 0, -4, -5, 0, 0, -3,
    0, -6, 0, -3, 0, 0, 0, 0,
    0, -9, 0, -5, 0, 0, 0, 0,
    0, -10, 0, -5, -6, 0, -2, 0,
    0, -8, 0, 0, -23, 0, -11, -7,
    0, -15, 0, -1, -4, 0, 0, 0,
    0, -2, 0, -2, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 52,
    .right_class_cnt     = 40,
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
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
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
const lv_font_t ui_font_FontMiSansNomal16 = {
#else
lv_font_t ui_font_FontMiSansNomal16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONTMISANSNOMAL16*/

