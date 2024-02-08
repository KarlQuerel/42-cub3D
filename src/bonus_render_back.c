/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_render_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:15:29 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/05 16:31:57 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	collectible_calc(t_data *data, t_v2f ray)
{
	int		line_height;
	float	perp_coll_dist;
	
	perp_coll_dist = abs_value(data->player_pos[0] - data->map_x + 0.5 + data->player_pos[1] - data->map_y + 0.5);
	(void)ray;
	line_height = (int)(IMG_HEIGHT / perp_coll_dist);
	data->draw_start = (IMG_HEIGHT - line_height) / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_start >= IMG_HEIGHT)
		data->draw_start = IMG_HEIGHT - 1;
	data->draw_end = (line_height + IMG_HEIGHT) / 2;
	if (data->draw_end >= IMG_HEIGHT)
		data->draw_end = IMG_HEIGHT - 1;
}

static void	back_side_calc(t_data *data, t_v2f ray, t_v2f delta_dist)
{
	if (ray[0] < 0)
	{
		data->step[0] = 1;
		data->side_dist[0] = (data->map_x + 1.0 - data->player_pos[0]) \
		* delta_dist[0];
	}
	else
	{
		data->step[0] = -1;
		data->side_dist[0] = (data->player_pos[0] - data->map_x) \
		* delta_dist[0];
	}
	if (ray[1] < 0)
	{
		data->step[1] = 1;
		data->side_dist[1] = (data->map_y + 1.0 - data->player_pos[1]) * \
		delta_dist[1];
	}
	else
	{
		data->step[1] = -1;
		data->side_dist[1] = (data->player_pos[1] - data->map_y) * \
		delta_dist[1];
	}
}

// mettre a jour le data sid_dist avant cette fonction
static void	go_back_to_last_cube(t_data *data, t_v2f ray, t_v2f delta_dist)
{
	(void)ray;
	if (data->side_dist[0] < data->side_dist[1])
	{
		data->side_dist[0] += delta_dist[0];
		data->map_x += data->step[0];
		data->side = 2 - (data->map_x > data->player_pos[0]);
	}
	else
	{
		data->side_dist[1] += delta_dist[1];
		data->map_y += data->step[1];
		data->side = EAST - (data->map_y > data->player_pos[1]);
	}
}

void	last_cube(t_data *data, t_v2f ray, int i, t_v2f delta_dist)
{
	(void)i;
	while (data->map_y != (int)data->player_pos[1] && data->map_x != (int)data->player_pos[0])
	{
		go_back_to_last_cube(data, ray, delta_dist);
		back_side_calc(data, ray, delta_dist);
		data->side_dist[data->side / 3] -= delta_dist[data->side / 3];
		collectible_calc(data, ray);
	// 	data->side_dist[data->side / 3] \
	// - delta_dist[data->side / 3]
		draw_someone(data, i);
	}
}
