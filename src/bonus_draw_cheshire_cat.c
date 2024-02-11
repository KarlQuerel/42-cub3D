/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw_cheshire_cat.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:18:56 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/11 12:08:01 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	progressiv_draw(int the_set, int cat, int time)
{
	int	r;
	int	g;
	int	b;
	int	color;

	if (cat & 0xff000000)
		return (the_set);
	r = (((cat & 0x00ff0000) >> 16) * time + ((the_set & 0x00ff0000) >> 16) * \
		(100 - time)) / 100;
	g = (((cat & 0x0000ff00) >> 8) * time + ((the_set & 0x0000ff00) >> 8) * \
		(100 - time)) / 100;
	b = ((cat & 0x000000ff) * time + (the_set & 0x000000ff) * (100 - time)) / \
		100;
	color = r;
	color <<= 8;
	color += g;
	color <<= 8;
	color += b;
	return (color);
}

int	get_cat_color(t_data *data, int x, int y, int pixel)
{
	int	frame;
	int	instant;
	int	cat_color;
	int	set_color;

	frame = data->cat_timer / 90;
	if (frame > 5 || data->cat_timer < 0)
	{
		data->cat_timer = 0;
		frame = 0;
	}
	instant = (data->time_2_le_retour - 1000) % 5000;
	set_color = ((int *)data->img.addr)[x * (IMG_WIDTH * \
		!data->drug + IMG_HEIGHT * data->drug) + ((IMG_WIDTH - IMG_HEIGHT) / 2 \
		* IMG_HEIGHT * data->drug) + y];
	cat_color = ((int *)(data->wall_cat[frame].addr))[pixel];
	if (instant < 600)
		return (progressiv_draw(set_color, cat_color, instant / 6));
	else if (instant > 4400)
		return (progressiv_draw(set_color, cat_color, 100 - (instant - 4400) / \
			6));
	(void)x;
	(void)y;
	return (((int *)(data->wall_cat[frame].addr))[pixel]);
}
