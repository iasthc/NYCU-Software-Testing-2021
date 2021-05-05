#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bmp_lib.h"

// bmp header https://zh.wikipedia.org/wiki/BMP
#pragma pack(2)
struct bmpfileheader
{
    char BM[2];
    unsigned int bfSize;
    unsigned int reserved;
    int offset;
};
struct bmpinfoheader
{
    int headersize;
    int width;
    int height;
    unsigned short color_planes;
    unsigned short bits_per_pixel;
    unsigned int compress;
    int image_size;
    unsigned int horizontal;
    unsigned int vertical;
    unsigned int colors;
    unsigned int important_colors;
};
#pragma pack()

int bmpwrite(bmpimage *img, char *name)
{
    // new header
    struct bmpfileheader file_h = {
        .BM[0] = 0x42,
        .BM[1] = 0x4d,
        .reserved = 0,
        .offset = 54,
    };
    file_h.bfSize = file_h.offset + img->width * img->height * img->bits / 8;

    struct bmpinfoheader info_h = {
        .headersize = 40,
        .color_planes = 1,
        .compress = 0,
        .horizontal = 0,
        .vertical = 0,
        .colors = 0,
        .important_colors = 0,
    };

    info_h.width = img->width;
    info_h.height = img->height;
    info_h.bits_per_pixel = img->bits;
    info_h.image_size = img->width * img->height * img->bits / 8;

    // open output file
    FILE *bmpfile = NULL;
    bmpfile = fopen(name, "wb+");
    if (!bmpfile)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // write header
    fwrite((char *)&file_h, sizeof(char), sizeof(file_h), bmpfile);
    fwrite((char *)&info_h, sizeof(char), sizeof(info_h), bmpfile);

    // write grayscale data
    for (int i = 0; i < img->width * img->height; i++)
    {
        fwrite((char *)&img->transform_data[i * 3], sizeof(char), sizeof(char), bmpfile);
        fwrite((char *)&img->transform_data[i * 3 + 1], sizeof(char), sizeof(char), bmpfile);
        fwrite((char *)&img->transform_data[i * 3 + 2], sizeof(char), sizeof(char), bmpfile);
    }

    // free all malloc
    free(img->data);
    free(img->transform_data);

    // close file
    fclose(bmpfile);
    return 0;
}

int bmp_transform(bmpimage *img, char *name)
{
    struct bmpfileheader file_h;
    struct bmpinfoheader info_h;

    // open bmp file
    FILE *bmpfile = fopen(name, "rb+");
    if (!bmpfile)
    {
        printf("Error opening file.\n");
        return 1;
    }
    // read header
    fread((char *)&file_h, sizeof(char), sizeof(file_h), bmpfile);
    fread((char *)&info_h, sizeof(char), sizeof(info_h), bmpfile);

    img->width = info_h.width;
    img->height = info_h.height;
    img->bits = info_h.bits_per_pixel;

    // check header is 'BM'
    if (file_h.BM[0] != 0x42 || file_h.BM[1] != 0x4d)
    {
        printf("BMP header error\n");
        return 1;
    }

    // check bits_per_pixel is 24
    if (img->bits != 24)
    {
        printf("bits should be 24 but is %d.\n", img->bits);
        return 1;
    }

    // prevent huge file
    if (img->width > 1025 || img->height > 1025)
    {
        printf("file too huge.\n");
        return 1;
    }

    // rgb, so *3
    size_t image_size = img->width * img->height * 3;

    // malloc data
    img->data = malloc(image_size * sizeof(char));
    if (!img->data)
    {
        printf("malloc fail.\n");
        return 1;
    }

    // malloc transform data to save
    img->transform_data = malloc(image_size * sizeof(char));
    if (!img->transform_data)
    {
        free(img->data);
        printf("malloc fail.\n");
        return 1;
    }

    // jump to rgb data
    fseek(bmpfile, file_h.offset, SEEK_SET);

    // read all file to data until EOF
    int idx = 0;
    while (1)
    {
        if (feof(bmpfile))
            break;

        fread((char *)&img->data[idx], sizeof(char), sizeof(char), bmpfile);
        idx++;
    }

    // change to grayscale 
    // https://www.tutorialspoint.com/dip/grayscale_to_rgb_conversion.htm
    // New grayscale image = ((0.3 * R) + (0.59 * G) + (0.11 * B))
    for (int i = 0; i < img->width * img->height; i++)
    {
        int gray = (30 * img->data[i * 3] + 59 * img->data[i * 3 + 1] + 11 * img->data[i * 3 + 2]) / 100;
        img->transform_data[i * 3] = (char)gray;
        img->transform_data[i * 3 + 1] = (char)gray;
        img->transform_data[i * 3 + 2] = (char)gray;
    }

    fclose(bmpfile);
    return 0;
}

void bmp_initial(bmpimage *img)
{
    memset(img, 0, sizeof(bmpimage));
}
