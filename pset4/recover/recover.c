//  open card file
//  read 512 bytes into a buffer
//   start of a new jpg?
//      yes ->
//      no ->
//    already found a jpg?
//      no ->
//      yes ->
//  close any remaining files

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    char* infile = argv[1];

    const int BLOCK_SIZE = 512;

    // open the input file
    FILE* inptr = fopen(infile, "r");
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s. \n", infile);
        return 2;
    }

    unsigned char buffer[BLOCK_SIZE];

    //pointer to outfile

    FILE* outptr = NULL;

    // make space for jpg file name ###.jpg
    char image[7];

    // number of image files created so far
    int n = 0;

    // search until a jpg is found
    while(fread(buffer, BLOCK_SIZE, 1, inptr) == 1)
    {
        // find the beginning of a jpg
        if(buffer[0] == 0xff &&
           buffer[1] == 0xd8 &&
           buffer[2] == 0xff &&
           buffer[3] >= 0xe0 &&
           buffer[3] <= 0xef)
        {
            // close the image file if one has been created
            if(n > 0)
            {
                fclose(outptr);
            }
            // make a name for this image file
            sprintf(image, "%03d.jpg", n);

            outptr = fopen(image, "w");
            if(outptr == NULL)
            {
                fprintf(stderr, "Could not create image file %s. \n", image);
            }

            // keep track of image number:
            n++;
        }

        if(outptr != NULL)
        {
            //write to image file
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }
    }

    // close the last image
    fclose(outptr);

    // close the .raw file
    fclose(inptr);

    // end program
    return 0;
}