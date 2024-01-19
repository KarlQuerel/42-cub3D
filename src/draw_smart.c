#include "../include/cub3d.h"

void	draw_msg(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 58)
	{
		j = 0;
		while (j < 400)
		{
			pixel = ((int *)data->dialog[data->dialog_stage].addr)[i * 400 + j];
			if (pixel > 0)
				ft_my_put_pixel(data, x + i, y + j, pixel);
			j++;
		}
		i++;
	}
}
