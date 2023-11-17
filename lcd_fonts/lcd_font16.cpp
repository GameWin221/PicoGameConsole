#include "lcd_fonts.hpp"

const unsigned char FONT_16_PX_DATA[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//  
	0x00,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// !
	0x00,0x00,0x00,0x00,0x1d,0xc0,0x1d,0xc0,0x08,0x80,0x08,0x80,0x08,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// "
	0x00,0x00,0x0d,0x80,0x0d,0x80,0x0d,0x80,0x0d,0x80,0x3f,0xc0,0x1b,0x00,0x3f,0xc0,0x1b,0x00,0x1b,0x00,0x1b,0x00,0x1b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// #
	0x04,0x00,0x1f,0x80,0x31,0x80,0x31,0x80,0x38,0x00,0x1e,0x00,0x0f,0x00,0x03,0x80,0x31,0x80,0x31,0x80,0x3f,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// $
	0x00,0x00,0x18,0x00,0x24,0x00,0x24,0x00,0x18,0xc0,0x07,0x80,0x1e,0x00,0x31,0x80,0x02,0x40,0x02,0x40,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// %
	0x00,0x00,0x00,0x00,0x0f,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x0c,0x00,0x1d,0x80,0x37,0x00,0x33,0x00,0x1d,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// &
	0x00,0x00,0x00,0x00,0x07,0x00,0x07,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// '
	0x00,0x00,0x03,0x00,0x03,0x00,0x06,0x00,0x0e,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0e,0x00,0x06,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// (
	0x00,0x00,0x18,0x00,0x18,0x00,0x0c,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x0c,0x00,0x1c,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// )
	0x00,0x00,0x06,0x00,0x06,0x00,0x3f,0xc0,0x3f,0xc0,0x0f,0x00,0x1f,0x80,0x19,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// *
	0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x3f,0x80,0x04,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// +
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x04,0x00,0x0c,0x00,0x08,0x00,0x08,0x00,0x00,0x00,0x00,0x00,// ,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// -
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// .
	0x00,0xc0,0x00,0xc0,0x01,0x80,0x01,0x80,0x03,0x00,0x03,0x00,0x06,0x00,0x0c,0x00,0x0c,0x00,0x18,0x00,0x18,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// /
	0x00,0x00,0x0e,0x00,0x1b,0x00,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x1b,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 0
	0x00,0x00,0x06,0x00,0x3e,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 1
	0x00,0x00,0x0f,0x00,0x19,0x80,0x31,0x80,0x31,0x80,0x03,0x00,0x06,0x00,0x0c,0x00,0x18,0x00,0x30,0x00,0x3f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 2
	0x00,0x00,0x3f,0x00,0x61,0x80,0x01,0x80,0x03,0x00,0x1f,0x00,0x03,0x80,0x01,0x80,0x01,0x80,0x61,0x80,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 3
	0x00,0x00,0x07,0x00,0x07,0x00,0x0f,0x00,0x0b,0x00,0x1b,0x00,0x13,0x00,0x33,0x00,0x3f,0x80,0x03,0x00,0x0f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 4
	0x00,0x00,0x1f,0x80,0x18,0x00,0x18,0x00,0x18,0x00,0x1f,0x00,0x11,0x80,0x01,0x80,0x01,0x80,0x21,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 5
	0x00,0x00,0x07,0x80,0x1c,0x00,0x18,0x00,0x30,0x00,0x37,0x00,0x39,0x80,0x31,0x80,0x31,0x80,0x19,0x80,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 6
	0x00,0x00,0x7f,0x00,0x43,0x00,0x03,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 7
	0x00,0x00,0x1f,0x00,0x31,0x80,0x31,0x80,0x31,0x80,0x1f,0x00,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 8
	0x00,0x00,0x1e,0x00,0x33,0x00,0x31,0x80,0x31,0x80,0x33,0x80,0x1d,0x80,0x01,0x80,0x03,0x00,0x07,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 9
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// :
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x04,0x00,0x08,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// ;
	0x00,0x00,0x00,0x00,0x00,0xc0,0x03,0x00,0x04,0x00,0x18,0x00,0x60,0x00,0x18,0x00,0x04,0x00,0x03,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// <
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xc0,0x00,0x00,0x7f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// =
	0x00,0x00,0x00,0x00,0x60,0x00,0x18,0x00,0x04,0x00,0x03,0x00,0x00,0xc0,0x03,0x00,0x04,0x00,0x18,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// >
	0x00,0x00,0x00,0x00,0x1f,0x00,0x31,0x80,0x31,0x80,0x01,0x80,0x07,0x00,0x0c,0x00,0x0c,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// ?
	0x00,0x00,0x0e,0x00,0x11,0x00,0x21,0x00,0x21,0x00,0x27,0x00,0x29,0x00,0x29,0x00,0x27,0x00,0x20,0x00,0x11,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// @
	0x00,0x00,0x00,0x00,0x3f,0x00,0x0f,0x00,0x09,0x00,0x19,0x80,0x19,0x80,0x1f,0x80,0x30,0xc0,0x30,0xc0,0x79,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// A
	0x00,0x00,0x00,0x00,0x7f,0x00,0x31,0x80,0x31,0x80,0x31,0x80,0x3f,0x00,0x31,0x80,0x31,0x80,0x31,0x80,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// B
	0x00,0x00,0x00,0x00,0x1f,0x40,0x30,0xc0,0x60,0x40,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x40,0x30,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// C
	0x00,0x00,0x00,0x00,0x7f,0x00,0x31,0x80,0x30,0xc0,0x30,0xc0,0x30,0xc0,0x30,0xc0,0x30,0xc0,0x31,0x80,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// D
	0x00,0x00,0x00,0x00,0x7f,0x80,0x30,0x80,0x30,0x80,0x32,0x00,0x3e,0x00,0x32,0x00,0x30,0x80,0x30,0x80,0x7f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// E
	0x00,0x00,0x00,0x00,0x7f,0xc0,0x30,0x40,0x30,0x40,0x32,0x00,0x3e,0x00,0x32,0x00,0x30,0x00,0x30,0x00,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// F
	0x00,0x00,0x00,0x00,0x1e,0x80,0x31,0x80,0x60,0x80,0x60,0x00,0x60,0x00,0x67,0xc0,0x61,0x80,0x31,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// G
	0x00,0x00,0x00,0x00,0x7b,0xc0,0x31,0x80,0x31,0x80,0x31,0x80,0x3f,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x7b,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// H
	0x00,0x00,0x00,0x00,0x3f,0xc0,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// I
	0x00,0x00,0x00,0x00,0x1f,0xc0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x63,0x00,0x63,0x00,0x63,0x00,0x3e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// J
	0x00,0x00,0x00,0x00,0x7b,0xc0,0x31,0x80,0x33,0x00,0x36,0x00,0x3c,0x00,0x3e,0x00,0x33,0x00,0x31,0x80,0x79,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// K
	0x00,0x00,0x00,0x00,0x7e,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x40,0x18,0x40,0x18,0x40,0x7f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// L
	0x00,0x00,0x00,0x00,0xe0,0xe0,0x60,0xc0,0x71,0xc0,0x7b,0xc0,0x6a,0xc0,0x6e,0xc0,0x64,0xc0,0x60,0xc0,0xfb,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// M
	0x00,0x00,0x00,0x00,0x73,0xc0,0x31,0x80,0x39,0x80,0x3d,0x80,0x35,0x80,0x37,0x80,0x33,0x80,0x31,0x80,0x79,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// N
	0x00,0x00,0x00,0x00,0x1f,0x00,0x31,0x80,0x60,0xc0,0x60,0xc0,0x60,0xc0,0x60,0xc0,0x60,0xc0,0x31,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// O
	0x00,0x00,0x00,0x00,0x7f,0x00,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x3f,0x00,0x30,0x00,0x30,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// P
	0x00,0x00,0x00,0x00,0x1f,0x00,0x31,0x80,0x60,0xc0,0x60,0xc0,0x60,0xc0,0x60,0xc0,0x60,0xc0,0x31,0x80,0x1f,0x00,0x0c,0xc0,0x1f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,// Q
	0x00,0x00,0x00,0x00,0x7f,0x00,0x31,0x80,0x31,0x80,0x31,0x80,0x3e,0x00,0x33,0x00,0x31,0x80,0x31,0x80,0x7c,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// R
	0x00,0x00,0x00,0x00,0x1f,0x80,0x31,0x80,0x31,0x80,0x38,0x00,0x1f,0x00,0x03,0x80,0x31,0x80,0x31,0x80,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// S
	0x00,0x00,0x00,0x00,0x7f,0x80,0x4c,0x80,0x4c,0x80,0x4c,0x80,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// T
	0x00,0x00,0x00,0x00,0x7b,0xc0,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// U
	0x00,0x00,0x00,0x00,0x7b,0xc0,0x31,0x80,0x31,0x80,0x1b,0x00,0x1b,0x00,0x1b,0x00,0x0a,0x00,0x0e,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// V
	0x00,0x00,0x00,0x00,0xfb,0xe0,0x60,0xc0,0x64,0xc0,0x6e,0xc0,0x6e,0xc0,0x2a,0x80,0x3b,0x80,0x3b,0x80,0x31,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// W
	0x00,0x00,0x00,0x00,0x7b,0xc0,0x31,0x80,0x1b,0x00,0x0e,0x00,0x0e,0x00,0x0e,0x00,0x1b,0x00,0x31,0x80,0x7b,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// X
	0x00,0x00,0x00,0x00,0x79,0xe0,0x30,0xc0,0x19,0x80,0x0f,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x1f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Y
	0x00,0x00,0x00,0x00,0x3f,0x80,0x21,0x80,0x23,0x00,0x06,0x00,0x04,0x00,0x0c,0x00,0x18,0x80,0x30,0x80,0x3f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Z
	0x00,0x00,0x07,0x80,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,// [
	0x30,0x00,0x30,0x00,0x18,0x00,0x18,0x00,0x0c,0x00,0x0c,0x00,0x06,0x00,0x03,0x00,0x03,0x00,0x01,0x80,0x01,0x80,0x00,0xc0,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,// backslash
	0x00,0x00,0x1e,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x1e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// ]
	0x04,0x00,0x0a,0x00,0x0a,0x00,0x11,0x00,0x20,0x80,0x20,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// ^
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,// _
	0x08,0x00,0x04,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// `
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x00,0x01,0x80,0x01,0x80,0x1f,0x80,0x31,0x80,0x33,0x80,0x1d,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// a
	0x00,0x00,0x70,0x00,0x30,0x00,0x30,0x00,0x37,0x00,0x39,0x80,0x30,0xc0,0x30,0xc0,0x30,0xc0,0x39,0x80,0x77,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// b
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1e,0x80,0x31,0x80,0x60,0x80,0x60,0x00,0x60,0x80,0x31,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// c
	0x00,0x00,0x03,0x80,0x01,0x80,0x01,0x80,0x1d,0x80,0x33,0x80,0x61,0x80,0x61,0x80,0x61,0x80,0x33,0x80,0x1d,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// d
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x00,0x31,0x80,0x60,0xc0,0x7f,0xc0,0x60,0x00,0x30,0xc0,0x1f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// e
	0x00,0x00,0x07,0xe0,0x0c,0x00,0x0c,0x00,0x3f,0x80,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x3f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// f
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1d,0xc0,0x33,0x80,0x61,0x80,0x61,0x80,0x61,0x80,0x33,0x80,0x1d,0x80,0x01,0x80,0x01,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,// g
	0x00,0x00,0x70,0x00,0x30,0x00,0x30,0x00,0x37,0x00,0x39,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x7b,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// h
	0x00,0x00,0x06,0x00,0x06,0x00,0x00,0x00,0x1e,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// i
	0x00,0x00,0x06,0x00,0x06,0x00,0x00,0x00,0x3f,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x3e,0x00,0x00,0x00,0x00,0x00,// j
	0x00,0x00,0x70,0x00,0x30,0x00,0x30,0x00,0x37,0x80,0x36,0x00,0x3c,0x00,0x3c,0x00,0x36,0x00,0x33,0x00,0x77,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// k
	0x00,0x00,0x1e,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// l
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x80,0x36,0xc0,0x36,0xc0,0x36,0xc0,0x36,0xc0,0x36,0xc0,0x76,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// m
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x00,0x39,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x7b,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// n
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x00,0x31,0x80,0x60,0xc0,0x60,0xc0,0x60,0xc0,0x31,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// o
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x00,0x39,0x80,0x30,0xc0,0x30,0xc0,0x30,0xc0,0x39,0x80,0x37,0x00,0x30,0x00,0x30,0x00,0x7c,0x00,0x00,0x00,0x00,0x00,// p
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1d,0xc0,0x33,0x80,0x61,0x80,0x61,0x80,0x61,0x80,0x33,0x80,0x1d,0x80,0x01,0x80,0x01,0x80,0x07,0xc0,0x00,0x00,0x00,0x00,// q
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7b,0x80,0x1c,0xc0,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// r
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x80,0x31,0x80,0x3c,0x00,0x1f,0x00,0x03,0x80,0x31,0x80,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// s
	0x00,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x7f,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x80,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// t
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x73,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x33,0x80,0x1d,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// u
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7b,0xc0,0x31,0x80,0x31,0x80,0x1b,0x00,0x1b,0x00,0x0e,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// v
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf1,0xe0,0x60,0xc0,0x64,0xc0,0x6e,0xc0,0x3b,0x80,0x3b,0x80,0x31,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// w
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7b,0xc0,0x1b,0x00,0x0e,0x00,0x0e,0x00,0x0e,0x00,0x1b,0x00,0x7b,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// x
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0xe0,0x30,0xc0,0x19,0x80,0x19,0x80,0x0b,0x00,0x0f,0x00,0x06,0x00,0x06,0x00,0x0c,0x00,0x3e,0x00,0x00,0x00,0x00,0x00,// y
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x80,0x21,0x80,0x03,0x00,0x0e,0x00,0x18,0x00,0x30,0x80,0x3f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// z
	0x00,0x00,0x06,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x18,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x0c,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// {
	0x00,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// |
	0x00,0x00,0x0c,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x03,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// }
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x24,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 // ~
};

font_t lcd_font_16px = { FONT_16_PX_DATA, 11, 16 };