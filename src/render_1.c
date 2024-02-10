/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:23:17 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 13:35:07 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_v2f	get_ray(t_data *data, int x)
{
	t_v2f	ray;
	float	cam;

	cam = 2.0f * (float)x / (float)IMG_WIDTH - 1;
	ray[0] = data->camera_dir[0] + data->plane[0] * cam;
	ray[1] = data->camera_dir[1] + data->plane[1] * cam;
	return (ray);
}

static void	side_calc(t_data *data, t_v2f ray, t_v2f delta_dist)
{
	if (ray[0] < 0)
	{
		data->step[0] = -1;
		data->side_dist[0] = (data->player_pos[0] - data->map_x) \
		* delta_dist[0];
	}
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
}

static bool	side_assignment(t_data *data, t_v2f delta_dist)
{
	if (data->side_dist[0] < data->side_dist[1])
	{
		data->side_dist[0] += delta_dist[0];
		data->map_x += data->step[0];
		data->side = 2 - (data->map_x > data->player_pos[0]);
		if (data->map[data->map_x][data->map_y] == 'D')
			return (data->side = DOOR, true);
	}
	else
	{
		data->side_dist[1] += delta_dist[1];
		data->map_y += data->step[1];
		data->side = EAST - (data->map_y > data->player_pos[1]);
		if (data->map[data->map_x][data->map_y] == 'D')
			return (data->side = DOOR_2, true);
	}
	if (data->map[data->map_x][data->map_y] == '1')
	{
		if (data->map_x == 0 && data->map_y == 10)
			data->display_catterpilar = true;
		else
			data->display_catterpilar = false;
		return (true);
	}
	return (false);
}

void	next_cube(t_data *data, t_v2f ray, int x, t_v2f delta_dist)
{
	side_calc(data, ray, delta_dist);
	while (!side_assignment(data, delta_dist))
		;
	wall_calc(data, ray, data->side_dist[data->side / 3] \
	- delta_dist[data->side / 3]);
	draw_slice(data, x);
}

void	render(t_data *data)
{
	t_v2f	ray;
	int		i;

	i = 0;
	while (i < IMG_WIDTH)
	{
		ray = get_ray(data, i);
		next_cube(data, ray, i, delta_dist_calc(data, &ray));
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
