# Questions

## What's `stdint.h`?

stdint.h is header file in C standard library, provides a set of typedefs that specify the width and the defined minimum and maximum values. Useful for embedded programming which involves considerable manipulation of hardware I/O registers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are corresponding integer types that make the code more portable and safer. It also allows the programmer to clarify the specific use of the data. so uint16_t would be 16 bits wide exactly.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 1 byte 
DWORD: 4 bytes 
LONG: 4 bytes
WORD: 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

hex: 0x42
Ascii: BM
decimal: 66

## What's the difference between `bfSize` and `biSize`?

bfSize: The size, in bytes, of the bitmap file.
biSize: Specifies the number of bytes required by the structure but the value does not
include the size of the color table or color mask.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount: specifies bits per pixel.

## Why might `fopen` return `NULL` in `copy.c`?

if the file that fopen is trying to open does not exist

## Why is the third argument to `fread` always `1` in our code?

Reading the contents or data of the file one at a time.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

(4 - (3*255 mod 4) mod 4 = 3

## What does `fseek` do?

fseek() function clears the end-of-file indicator for the stream and undoes any effects of the ungetc(3) function on  the  same stream.

## What is `SEEK_CUR`?

the start of the file, the current position indicator, or end-of-file.
