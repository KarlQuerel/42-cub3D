
#include "../include/cub3d.h"
#include <errno.h>

bool    get_door(t_data *data)
{
    if (!upload_img(data, &data->door, "./img/XPM/Walls/DOOR.xpm\0"))
    {
        ft_print_fd(2, "%s\n", strerror(errno));
        return (false);
    }
    // data->door.addr = mlx_get_data_addr(data->door.img, \
	// &data->door.bpp, &data->door.ll, &data->door.endian);
	// if (!data->door.addr)
	// 	return (false);
    return (true);
}

bool    get_cheshire_cat(t_data *data)
{
    static char    file[] = "img/Cheshire_cat/x.xpm\0";
    int            i;

    i = 1;
    while (i - 1 < 6)
    {
        file[17] = i + '0';
        if (!upload_img(data, &((data->cheshire_cat)[i - 1]), file))
        {
            ft_print_fd(2, "%s\n", strerror(errno));
            return (false);
        }
        i++;
    }
    return (true);
}

bool    get_catterpilar(t_data *data)
{
    static char    file[] = "img/Catterpillar/xx.xpm\0";
    int            i;

    i = 1;
    while (i - 1 < 18)
    {
        file[17] = i / 10 + '0';
        file[18] = i % 10 + '0';
        if (!upload_img(data, &((data->catterpilar)[i - 1]), file))
        {
            ft_print_fd(2, "%s\n", strerror(errno));
            return (false);
        }
        i++;
    }
    return (true);
}

bool    get_white_rabbit(t_data *data)
{
    static char    file[] = "img/White_rabbit/xx.xpm\0";
    int            i;

    i = 1;
    while (i - 1 < 10)
    {
        file[17] = i / 10 + '0';
        file[18] = i % 10 + '0';
        if (!upload_img(data, &((data->white_rabbit)[i - 1]), file))
        {
            ft_print_fd(2, "%s\n", strerror(errno));
            return (false);
        }
        i++;
    }
    return (true);
}

bool get_characters(t_data *data)
{
    if (!get_alice(data) || !get_catterpilar(data) || \
        !get_cheshire_cat(data) || !get_white_rabbit(data) || !get_door(data))
        return (false);
    return (true);
}
