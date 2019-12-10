#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // check for proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // create buffer
    unsigned char buffer[512];
    int i = 0;

    // iterate over the file to find JPEG
    // read the infile's JPEG
    // and write the new JPEG
    while (fread(&buffer, 1, 512, inptr) != 0x00)
    {
        //check if file is JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            char jpeg[8];
            // re-open output file
            FILE *outptr = fopen(jpeg, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", jpeg);
                return 3;
            }

            // write outfile JPEG

            fwrite(buffer, 1, 512, outptr);
            sprintf(jpeg, "%03i.jpg", i);
            fclose(outptr);
            i++;
        }

        // if it's the end of file close
        else if (fread(&buffer, 1, 512, inptr) == 1)
        {
            fclose(inptr);
            return 0;
        }

        // continue if JPEG not found
        else
        {
            continue;
        }
    }
}
