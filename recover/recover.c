#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    BYTE buffer[512];
    int bytes, counter = 0;
    char filename[8];

    //opening card.raw
    FILE *file = fopen(argv[1], "r");
    FILE *image = NULL;

    if (argc != 2) // checking for 2 arguments
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    if (file == NULL)
    {
        printf("./recover card.raw");
        return 1;
    }
    // repeat process until all jpegs are recovered
    while (1)
    {
        // buffering 512 bytes
        bytes = fread(buffer, sizeof(BYTE), 512, file);
        // finding jpeg files
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (counter == 0) // if jpeg file is found create and write file
            {
                sprintf(filename, "%03i.jpg", counter);
                image = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes, image);
                counter++;

            }
            else // close file and open new file
            {
                fclose(image);
                sprintf(filename, "%03i.jpg", counter);
                image = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes, image);
                counter++;
            }
        }
        else if (counter != 0) // jpeg is found
        {
            fwrite(buffer, sizeof(BYTE), bytes, image);
            if (bytes == 0)
            {
                fclose(image); // freeing memory
                fclose(file);
                return 0;
            }
        }
    }
    fclose(image); // freeing memory
    fclose(file);
}
