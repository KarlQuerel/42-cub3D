#include "../include/cub3d.h"

void    my_put_img_to_img_2(t_data *data, t_img_info *src, t_img_info *dest, int x, int y)
{
    int i;
    int j;
    int pixel;

    i = 0;
    (void)dest;
    while (i < 128)
    {
        j = 0;
        while (j < 128)
        {
            pixel = ((int *)src->addr)[i * 128 + 127 -  j];
            // pixel = 0x00ffffff;
            if (pixel > 0)
                ft_my_put_pixel(data, x + i, y + j, pixel);
            // if (!j)
            //     printf("%d mon pixel de mort\n",pixel);
            // printf("je put un pixel quand")
            // ((int *)dest->addr)[(x + i) * data->width + y + j] = ((int *)src->addr)[i * src->width + j];
            j++;
        }
        i++;
    }
}

void    my_put_img_to_img(t_data *data, t_img_info *src, t_img_info *dest, int x, int y)
{
    int i;
    int j;
    int pixel;

    i = 0;
    (void)dest;
    while (i < 128)
    {
        j = 0;
        while (j < 128)
        {
            pixel = ((int *)src->addr)[i * 128 + j];
            // pixel = 0x00ffffff;
            if (pixel > 0)
                ft_my_put_pixel(data, x + i, y + j, pixel);
            // if (!j)
            //     printf("%d mon pixel de mort\n",pixel);
            // printf("je put un pixel quand")
            // ((int *)dest->addr)[(x + i) * data->width + y + j] = ((int *)src->addr)[i * src->width + j];
            j++;
        }
        i++;
    }
}

void    draw_alice(t_data *data, int x, int y)
{
    static int anim = 0;

    my_put_img_to_img_2(data, &data->alice[anim/200], &data->img, x, y);
    anim++;
    if (anim / 200 > 16)
        anim = 0;
}

void    draw_white_rabbit(t_data *data, int x, int y)
{
    static int anim = 0;

    my_put_img_to_img(data, &data->white_rabbit[anim/200], &data->img, x, y);
    anim++;
    if (anim / 200 > 9)
        anim = 0;
}
