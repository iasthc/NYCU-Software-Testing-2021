#include <stdlib.h>
#include <stdio.h>
#include "bmp_lib.h"

int main(int argc, char *argv[])
{
    // usage
    if (argc != 3)
    {
        printf("usage : ./bmpgrayscale [inputfile] [outfile]");
        return 0;
    }

    bmpimage img;
    bmp_initial(&img);

    
    if (bmp_transform(&img, argv[1]) == 1)
    {
        printf("readerror\n");
        return 0;
    }

    if (bmpwrite(&img, argv[2]) == 1)
    {
        printf("writeerror\n");
        return 0;
    }
    return 0;
}