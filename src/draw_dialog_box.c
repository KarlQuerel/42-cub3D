/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dialog_box.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:38:21 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/19 15:18:31 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (color > 0)
				ft_my_put_pixel(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	my_put_img_to_img_3(t_data *data, t_img_info *src, t_img_info *dest, int x, int y)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	(void)dest;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			pixel = ((int *)src->addr)[i * 128 + j];
			if (pixel > 0)
				ft_my_put_pixel(data, x + i, y + j, pixel);
			j++;
		}
		i++;
	}
}

void	draw_msg(t_data *data, int x, int y)
{
	// static t_img_info	imgs[] = {data->}
	my_put_img_to_img_3(data, data->dialog[0], x, y);
}

//Trouver un moyen d'ecrire le texte des enfers
void	draw_dialog_box(t_data *data, int x, int y)
{
	if (data->dialog_stage != DIALOG_NOT_STARTED && \
		data->dialog_stage != DIALOG_FINISH)
	{
		draw_dialog_box_left(data, x, y);
		draw_dialog_box_mid(data, x, y + 16);
		draw_dialog_box_right(data, x, 960 - y - 64);
		draw_msg(data, x + 20, y);
	}
}
