/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw_protagonists.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:42:18 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/11 12:06:49 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	calc(t_data *data, int start, int d)
{
	int	tex_x;
	int	tex_y;

	tex_x = (int)(256 * (start - \
	(-1 * data->col_u.s_wdth / 2 + \
	data->col_u.sprite_screen)) * \
	128 / data->col_u.s_wdth) / 256;
	if (tex_x < 0)
		tex_x = 0;
	tex_y = ((d * 128) / data->col_u.s_hgt) / 256;
	return (tex_y * 128 + tex_x);
}

void	display_coll(t_data *data, int start, int end, bool type)
{
	int	col;
	int	y;
	int	d;

	while (start < end)
	{
		if (data->col_u.trans[1] > 0 && start > 0 && start < IMG_WIDTH && \
			data->col_u.trans[1] < data->zbuffer[start])
		{
			y = data->col_u.draw_start_y;
			while (y < data->col_u.draw_end_y)
			{
				d = y * 256 - IMG_HEIGHT * 128 + data->col_u.s_hgt * 128;
				if (!type)
					col = ((int *)data->mushroom.addr)[calc(data, start, d)];
				else
					col = get_cat_color(data, y, start, calc(data, start, d));
				if (!(col & 0xff000000))
					ft_my_put_pixel(data, y, start, col);
				y++;
			}
		}		
		start++;
	}
}

void	is_visible_continued(t_data *data, t_v2f sprite)
{
	float	inv_det;

	inv_det = 1.0 / (data->plane[0] * data->camera_dir[1] - \
	data->camera_dir[0] * data->plane[1]);
	data->col_u.trans[0] = inv_det * (data->camera_dir[1] * sprite[0] - \
	data->camera_dir[0] * sprite[1]);
	data->col_u.trans[1] = inv_det * (-1 * data->plane[1] * sprite[0] + \
	data->plane[0] * sprite[1]);
	data->col_u.sprite_screen = (int)(IMG_WIDTH / 2) *\
	(1 + data->col_u.trans[0] / data->col_u.trans[1]);
}

void	is_visible(t_data *data, t_coll *coll)
{
	t_v2f	sprite;
	int		draw_start_x;
	int		draw_end_x;

	sprite[0] = coll->pos[0] - data->player_pos[0];
	sprite[1] = coll->pos[1] - data->player_pos[1];
	is_visible_continued(data, sprite);
	data->col_u.s_hgt = abs_value((int)(IMG_HEIGHT / data->col_u.trans[1]));
	data->col_u.draw_start_y = -1 * data->col_u.s_hgt / 2 + IMG_HEIGHT / 2;
	if (data->col_u.draw_start_y < 0)
		data->col_u.draw_start_y = 0;
	data->col_u.draw_end_y = data->col_u.s_hgt / 2 + IMG_HEIGHT / 2;
	if (data->col_u.draw_end_y >= IMG_HEIGHT)
		data->col_u.draw_end_y = IMG_HEIGHT - 1;
	data->col_u.s_wdth = abs_value((int)(IMG_HEIGHT / data->col_u.trans[1]));
	draw_start_x = -1 * data->col_u.s_wdth / 2 + data->col_u.sprite_screen;
	if (draw_start_x < 0)
		draw_start_x = 0;
	draw_end_x = data->col_u.s_wdth / 2 + data->col_u.sprite_screen;
	if (draw_end_x >= IMG_WIDTH)
		draw_end_x = IMG_WIDTH - 1;
	data->cat_timer++;
	display_coll(data, draw_start_x, draw_end_x, coll->type);
}

void	draw_collectible_and_protagonist(t_data *data)
{
	t_coll	*tmp;

	tmp = data->coll;
	while (tmp)
	{
		is_visible(data, tmp);
		tmp = tmp->next;
	}
}
