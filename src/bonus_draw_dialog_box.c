/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw_dialog_box.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:09:36 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/03 10:22:26 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	draw_dialog_box_left(t_data *data, int x, int y)
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
			if (color > 0)
				ft_my_put_pixel(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_dialog_box_mid(t_data *data, int x, int y)
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
			if (color > 0)
				ft_my_put_pixel(data, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_dialog_box_right(t_data *data, int x, int y)
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
			if (color > 0)
				ft_my_put_pixel(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_dialog_box(t_data *data, int x, int y)
{
	if (data->dialog_stage != DIALOG_NOT_STARTED && \
		data->dialog_stage != DIALOG_FINISH_1)
	{
		draw_dialog_box_left(data, x, y);
		draw_dialog_box_mid(data, x, y + 16);
		draw_dialog_box_right(data, x, 960 - y - 64);
		draw_msg(data, x + 30, y + 45);
	}
}

void draw_all(t_data *data)
{
	int	x;
	int	y;

	x = (int)data->player_pos[0] / MINIMAP_HEIGHT * MINIMAP_HEIGHT;
	y = (int)data->player_pos[1] / MINIMAP_WIDTH * MINIMAP_WIDTH;
	draw_minimap(data, x, y);
	draw_alice(data, IMG_HEIGHT - IMG_HEIGHT / 20 - 128, IMG_WIDTH / 20);
	if (data->dialog_stage != DIALOG_NOT_STARTED && \
		data->dialog_stage != DIALOG_FINISH_1)
	{
		draw_white_rabbit(data, IMG_HEIGHT - IMG_HEIGHT / 20 - 128, \
			IMG_WIDTH - IMG_WIDTH / 20 - 128);
		draw_dialog_box(data, IMG_HEIGHT - IMG_HEIGHT / 20 - 128, \
			IMG_WIDTH / 20 + 192);
	}
}
