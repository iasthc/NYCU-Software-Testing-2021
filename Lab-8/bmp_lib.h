typedef struct bmpimage
{
    unsigned int width, height;
    unsigned short bits;
    char *data;
    char *transform_data;
} bmpimage;

void bmp_initial(bmpimage *img);
int bmp_transform(bmpimage *img, char *name);
int bmpwrite(bmpimage *img, char *name);