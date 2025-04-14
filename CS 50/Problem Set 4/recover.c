#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: please enter EXACTLY one file name\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = NULL;

    if (input == NULL)
    {
        printf("Usage: please enter CORRECT file name\n");
        return 1;
    }

    BYTE byte[512];

    int flag = 0;
    char filename[8];

    while (fread(byte, sizeof(byte[0]), 512, input) != 0)
    {
        if (flag == 0 && byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff &&
            (byte[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", flag);
            output = fopen(filename, "w");
            fwrite(byte, sizeof(byte[0]), 512, output);
            flag += 1;
            continue;
        }

        if (flag > 0 && byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff &&
            (byte[3] & 0xf0) == 0xe0)
        {
            fclose(output);
            sprintf(filename, "%03i.jpg", flag);
            output = fopen(filename, "w");
            fwrite(byte, sizeof(byte[0]), 512, output);
            flag += 1;
            continue;
        }
        if (flag > 0)
            fwrite(byte, sizeof(byte[0]), 512, output);
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);

    return 0;
}
