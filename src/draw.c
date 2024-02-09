/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:29:55 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 10:59:40 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_floor(t_data *data, int x, int start, int *i)
{
	static int	*imgs[] = {NULL, NULL, NULL, NULL, NULL, NULL};
	int			color;
	int			tex_y;

	if (!imgs[1])
	{
		imgs[0] = (int *)data->door.addr;
		imgs[1] = (int *)data->north.addr;
		imgs[2] = (int *)data->south.addr;
		imgs[3] = (int *)data->west.addr;
		imgs[4] = (int *)data->east.addr;
		imgs[5] = (int *)data->door.addr;
	}
	while (*i <= start && *i < IMG_HEIGHT)
	{
		tex_y = (int)data->tex_pos & (TEX_HEIGHT - 1);
		color = imgs[data->side][tex_y * TEX_HEIGHT + data->tex_x];
		if (data->side && data->side != DOOR_2)
			color = (color >> 1) & 8355711;
		ft_my_put_pixel(data, *i, x, data->floor_color_2);
		color += data->step_all;
		color /= data->step_all;
		(*i)++;
	}
}

static void	draw_wall(t_data *data, int x, int end, int *i)
{
	static int	*imgs[] = {NULL, NULL, NULL, NULL, NULL, NULL};
	int			color;
	int			tex_y;

	// printf("wtf : %p\n", imgs[0]);
	if (!imgs[1])
	{
		imgs[0] = (int *)data->door.addr;
		imgs[1] = (int *)data->north.addr;
		imgs[2] = (int *)data->south.addr;
		imgs[3] = (int *)data->west.addr;
		imgs[4] = (int *)data->east.addr;
		imgs[5] = (int *)data->door.addr;
	}
	data->tex_pos_tmp = data->tex_pos;
	while (*i <= end && *i < IMG_HEIGHT)
	{
		tex_y = (int)data->tex_pos & (TEX_HEIGHT - 1);
		data->tex_pos += data->step_all;
		color = imgs[data->side][tex_y * TEX_HEIGHT + data->tex_x];
		if (data->side)
			color = (color >> 1) & 8355711;
		ft_my_put_pixel(data, *i, x, color);
		(*i)++;
	}
}

void	draw_ceiling(t_data *data, int x, int *i)
{
	static int	*imgs[] = {NULL, NULL, NULL, NULL, NULL, NULL};
	int			color;
	int			tex_y;

	if (!imgs[1])
	{
		imgs[0] = (int *)data->door.addr;
		imgs[1] = (int *)data->north.addr;
		imgs[2] = (int *)data->south.addr;
		imgs[3] = (int *)data->west.addr;
		imgs[4] = (int *)data->east.addr;
		imgs[5] = (int *)data->door.addr;
	}
	while (*i < IMG_HEIGHT)
	{
		tex_y = (int)data->tex_pos & (TEX_HEIGHT - 1);
		color = imgs[data->side][tex_y * TEX_HEIGHT + data->tex_x];
		if (data->side)
			color = (color >> 1) & 8355711;
		ft_my_put_pixel(data, *i, x, data->ceiling_color_2);
		color += data->step_all;
		color /= data->step_all;
		(*i)++;
	}
}

// void	draw_catterpilar(t_data *data, int x, int end, int i) // bonus
// {
// 	int	color;
// 	int	tex_y;

// 	while (i <= end && i < IMG_HEIGHT)
// 	{
// 		tex_y = (int)data->tex_pos_tmp & (128 - 1);
// 		data->tex_pos_tmp += data->step_all;
// 		color = ((int *)data->catterpilar[data->time / 100].addr) \
// 			[tex_y * 128 + data->tex_x];
// 		if (color > 0)
// 			ft_my_put_pixel(data, i, x, color);
// 		(i)++;
// 	}
// }

void	draw_slice(t_data *data, int x)
{
	int	i;
	int	tmp;

	i = 0;
	draw_floor(data, x, data->draw_start, &i);
	tmp = i;
	draw_wall(data, x, data->draw_end, &i);
	// if (data->display_catterpilar || data->drogue)
	// 	draw_catterpilar(data, x, data->draw_end, tmp);
	draw_ceiling(data, x, &i);
}
