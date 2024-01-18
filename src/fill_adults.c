
#include "../include/cub3d.h"
#include <errno.h>

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
