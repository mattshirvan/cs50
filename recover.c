#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void write(unsigned char *buff, FILE *file);
bool isaHeader(unsigned char *header);


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

    // create buffer and output file
    FILE *outptr;
    unsigned char buffer[512];
    char jpeg[8];
    bool jpegfound = false;
    int i = 0;

    // iterate over the file to find JPEG
    while (fread(&buffer, 1, 512, inptr) != 0x00)
    {
        //check if file is JPEG
        if (isaHeader(buffer))
        {
            // re-open output file
            sprintf(jpeg, "%03i.jpg", i++);
            outptr = fopen(jpeg, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", jpeg);
                return 3;
            }
        }
        // write outfile JPEG
        write(buffer, outptr);
    }
    fclose(inptr);
    fclose(outptr);
}

// write the jpeg bytes to outfile
void write(unsigned char *buff, FILE *file)
{
    if (file != NULL)
    {
        fwrite(buff, 1, 512, file);
    }
}

bool isaHeader(unsigned char *header)
{
    if (header[0] == 0xff &&
    header[1] == 0xd8 &&
    header[2] == 0xff &&
    (header[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}