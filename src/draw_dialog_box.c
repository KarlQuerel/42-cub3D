#include "../include/cub3d.h"

void	draw_dialog_box_left(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 16)
		{
			color = ((int *)data->dialog_box.addr)[i * 66 + j];
			// printf("mon nbr a la con : %d <%d/%d>\n", color, i, j);
			if (color > 0)
				ft_my_put_pixel(data, x + i, y + j, color);
			j++;
		}
		i++;
	}

}

void	draw_dialog_box_mid(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;

	j = 0;
	while (j <= IMG_WIDTH - IMG_WIDTH / 10 -128 -31 - 128 - 128)
	{
		i = 0;
		while (i < 128)
		{
			color = ((int *)data->dialog_box.addr)[i * 66 + 16];
			// printf("mon nbr a la con : %d <%d/%d>\n", color, i, j);
			if (color > 0)
				ft_my_put_pixel(data, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_dialog_box_right(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < 128)
	{
		j = 50;
		while (j < 66)
		{
			color = ((int *)data->dialog_box.addr)[i * 66 + j];
			// printf("mon nbr a la con : %d <%d/%d>\n", color, i, j);
			if (color > 0)
				ft_my_put_pixel(data, x + i, y + j, color);
			j++;
		}
		i++;
	}

}

void	draw_dialog_box(t_data *data, int x, int y)
{
	draw_dialog_box_left(data, x, y);
	draw_dialog_box_mid(data, x, y + 16);
	draw_dialog_box_right(data, x, 960 - y - 64);
}

