/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw_protagonists.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:42:18 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 15:08:23 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	display_coll(t_data *data, int start, int end)
{
	int	tex_x;
	int	y;

	while (start < end)
	{
		tex_x = (int)(256 * (start - (-1 * data->coll_utils.sprite_width / 2 + \
			data->coll_utils.sprite_screen)) * \
			128 / data->coll_utils.sprite_width) / 256;

		if (data->coll_utils.transform[1] > 0 && start > 0 && start < IMG_WIDTH && \
			data->coll_utils.transform[1] < data->zbuffer[start])
		{
			y = data->coll_utils.draw_start_y;
			while (y < data->coll_utils.draw_end_y)
			{
				int d = y * 256 - IMG_HEIGHT * 128 + data->coll_utils.sprite_height * 128;
				int	tex_y = ((d * 128) / data->coll_utils.sprite_height) / 256;
				int	color = ((int *)data->mushroom.addr)[tex_y * 128 + tex_x];
				if (!(color & 0xff000000))
					ft_my_put_pixel(data, y, start, color);
				y++;
			}
		}		
		start++;
	}
}

void	is_visible(t_data *data, t_coll *coll)
{
	float	inv_det;
	t_v2f	sprite;
	

	sprite[0] = coll->pos[0] - data->player_pos[0];
	sprite[1] = coll->pos[1] - data->player_pos[1];
	inv_det = 1.0 / (data->plane[0] * data->camera_dir[1] - data->camera_dir[0] * data->plane[1]);
	data->coll_utils.transform[0] = inv_det * (data->camera_dir[1] * sprite[0] - data->camera_dir[0] * sprite[1]);
	data->coll_utils.transform[1] = inv_det * (-1 * data->plane[1] * sprite[0] + data->plane[0] * sprite[1]);

	data->coll_utils.sprite_screen = (int)(IMG_WIDTH / 2) * (1 + data->coll_utils.transform[0] / data->coll_utils.transform[1]);

	data->coll_utils.sprite_height = abs_value((int)(IMG_HEIGHT / data->coll_utils.transform[1]));

	data->coll_utils.draw_start_y = -1 * data->coll_utils.sprite_height / 2 + IMG_HEIGHT / 2;
	if (data->coll_utils.draw_start_y < 0)
		data->coll_utils.draw_start_y = 0;


	data->coll_utils.draw_end_y = data->coll_utils.sprite_height / 2 + IMG_HEIGHT / 2;

	if (data->coll_utils.draw_end_y >= IMG_HEIGHT)
		data->coll_utils.draw_end_y = IMG_HEIGHT - 1;

	data->coll_utils.sprite_width = abs_value((int)(IMG_HEIGHT / data->coll_utils.transform[1]));
	
	int	draw_start_x;
	draw_start_x = -1 * data->coll_utils.sprite_width / 2 + data->coll_utils.sprite_screen;
	if (draw_start_x < 0)
		draw_start_x = 0;
	
	int	draw_end_x;
	draw_end_x = data->coll_utils.sprite_width / 2 + data->coll_utils.sprite_screen;

	if (draw_end_x >= IMG_WIDTH)
		draw_end_x = IMG_WIDTH - 1;
	display_coll(data, draw_start_x, draw_end_x);
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

// void	draw_collectible(t_data *data, int x, int end, int i)
// {
// 	int			color;
// 	int			tex_y;

// 	while (i <= end && i < IMG_HEIGHT)
// 	{
// 		tex_y = (int)data->tex_pos & (128 - 1);
// 		data->tex_pos += data->step_all;
// 		color = data->mushroom.addr[tex_y * 128 + data->tex_x];
// 		if (!(color & 0xff000000))
// 			ft_my_put_pixel(data, i, x, color);
// 		i++;
// 	}
// }

// // void	draw_protagonist(t_data *data)
// // {
	
// // }

// void	draw_someone(t_data *data, int col)
// {
// 	int	pos_someone_x;
// 	int	pos_someone_y;

// 	pos_someone_x = data->map_x - (data->side == NORTH) + (data->side == SOUTH);
// 	pos_someone_y = data->map_y - (data->side == EAST) + (data->side == WEST);
// 	if (data->map[pos_someone_x][pos_someone_y] == 'C')
// 	{
// 		draw_collectible(data, col, data->draw_end, data->draw_start);
// 	}
// 	// else if (data->map[pos_someone_x][pos_someone_y] == 'P')
// 	// {
// 	// 	// draw_protagonist();
// 	// }
// }
