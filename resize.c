// Resizes a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // check for correct usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // check for correct usage of integer
    if (atoi(argv[1]) < 0 || atoi(argv[1]) > 100)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 2;
    }

    // iterate over argc for arguments
    for (int i = 0; i < argc; i++)
    {
        // iterate over command line to convert to type Char
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            // validate Command line is not alpha
            for (int key = 0, h = strlen(argv[1]); key < h; key++)
            {
                // check for correct usage
                if (!isdigit(argv[1][key]))
                {
                    printf("Usage: ./resize n infile outfile\n");
                    return 3;
                }
            }
        }
    }

    // set integer into variable
    int n = atoi(argv[1]);

    // remember the users filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 5;
    }

    // read the infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read the infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // check that infile is 24-bit uncompressed BMP
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 6;
    }

    // determine padding for scanlines (seems better up here)
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update and remember headers old and new (I think)
    BITMAPFILEHEADER update_bf = bf;
    BITMAPINFOHEADER update_bi = bi;

    // update width and height
    update_bi.biWidth *= n;
    update_bi.biHeight *= n;

    // update padding
    int update_padding = (4 - (update_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update image and size (struggled with this forever was wrtining as bi.sizeImage,)
    update_bi.biSizeImage = (sizeof(RGBTRIPLE) * update_bi.biWidth + update_padding) * abs(update_bi.biHeight);
    update_bf.bfSize = update_bi.biSizeImage + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&update_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&update_bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate and do over (I think)
        for (int r = 0; r < n; r++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read input files size of RGB triple
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                // this should work (borrowed some ideas from discord and stack exchange)
                for (int w = 0; w < n; w++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }


            // skip over padding
            fseek(inptr, padding, SEEK_CUR);

            // adding padding (it rhymes)
            for (int k = 0; k < update_padding; k++)
            {
                fputc(0x00, outptr);
            }

            // stupid padding
            if (r < n -1)
            {
                // messing with the scanline
                // Saw something similar on the stack exchange or overflow
                fseek(inptr, - (bi.biWidth * 3 + padding), SEEK_CUR);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // completed (hopefully)
    return 0;
}
