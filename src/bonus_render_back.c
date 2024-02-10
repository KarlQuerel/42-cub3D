/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_render_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:15:42 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 20:49:01 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	hi_norminette(t_data *data, t_v2f delta_dist)
{
	data->step[0] = -1;
	data->side_dist[0] = (data->player_pos[0] - data->map_x) \
	* delta_dist[0];
}

t_v2f	reverse_ray(t_data *data, t_v2f ray, t_v2f delta_dist)
{
	ray[0] *= -1;
	ray[1] *= -1;
	if (ray[0] < 0)
		hi_norminette(data, delta_dist);
	else
	{
		data->step[0] = 1;
		data->side_dist[0] = (data->map_x + 1.0 - data->player_pos[0]) \
		* delta_dist[0];
	}
	if (ray[1] < 0)
	{
		data->step[1] = -1;
		data->side_dist[1] = (data->player_pos[1] - data->map_y) * \
		delta_dist[1];
	}
	else
	{
		data->step[1] = 1;
		data->side_dist[1] = (data->map_y + 1.0 - data->player_pos[1]) * \
		delta_dist[1];
	}
	return (ray);
}

void	draw_slice_coll(t_data *data, int x)
{
	int	i;

	i = 0;
	while (i < IMG_HEIGHT - 1)
	{
		ft_my_put_pixel(data, i, x, 0x00404040);
		i++;
	}
}

bool	back_to_player(t_data *data, int i, t_v2f delta_dist)
{
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
	if (data->map[data->map_x][data->map_y] == 'C' || \
		data->map[data->map_x][data->map_y] == 'P')
		draw_slice_coll(data, i);
	if (data->map_x == (int)data->player_pos[0] && \
		data->map_y == (int)data->player_pos[1])
		return (true);
	return (false);
}

void	last_cube(t_data *data, t_v2f ray, int i, t_v2f dist)
{
	t_v2f	ray_reversed;

	ray_reversed = reverse_ray(data, ray, dist);
	while (!back_to_player(data, i, ray_reversed))
		;
}
