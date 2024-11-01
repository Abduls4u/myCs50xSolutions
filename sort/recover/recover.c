#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer to hold each 512-byte block
    uint8_t buffer[512];

    // Track the output file and image count
    FILE *img = NULL;
    int img_count = 0;
    char filename[8]; // To hold file names like "000.jpg"

    // While there are 512-byte blocks left to read from the memory card
    while (fread(buffer, sizeof(uint8_t), 512, card) == 512)
    {
        // Check if this block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If there's already an open JPEG file, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new filename and open a new file for writing
            sprintf(filename, "%03i.jpg", img_count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(card);
                printf("Could not create file.\n");
                return 1;
            }

            img_count++;
        }

        // If an image file is open, write the current buffer to it
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, img);
        }
    }

    // Close any remaining open files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
