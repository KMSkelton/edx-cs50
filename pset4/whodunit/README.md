# Questions

## What's `stdint.h`?

'stdint.h' is a header file that declares the sizes of each integer type.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

'uint' declares that an integer is unsigned, the number_t indictes that the int takes up that number of bites.
I would use them when writing C because it does not handle memory management for us the way higher level languages do.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

8, 32, 32, 16

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM, 66 67, or 0x42 0x4D

## What's the difference between `bfSize` and `biSize`?

'bfSize' is the file size of the image, 'biSize' is the size of the infrastructure including headers.

## What does it mean if `biHeight` is negative?

Negative 'biHeight' means the image is "top-down" and starts at the top-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

if the input or output are NULL then fopen returns NULL.

## Why is the third argument to `fread` always `1` in our code?

The third agrument that fread accepts indicates how many files are being read. We are only working with a single file so '1' is hardcoded into the code.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

4

## What does `fseek` do?

fseek sets the file position to the given offset

## What is `SEEK_CUR`?

SEEK_CUR is an agrument that can be passed into fssek(). SEEK_CUR sets the file position to the current position.
