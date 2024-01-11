/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:44:49 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/11 17:42:44 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_v2f	get_ray(t_data *data, int x)
{
	t_v2f	ray;
	float	cam;

	cam = 2.0f * (float)x / (float)IMG_HEIGHT - 1;
	ray[0] = data->camera_dir[0] + data->plane[0] * cam;
	ray[1] = data->camera_dir[1] + data->plane[1] * cam;
	return (ray);
}

void	next_cube(t_data *data, t_v2f ray, int x)
{
	int		map_x;
	int		map_y;
	t_v2f	delta_dist;

	map_x = (int)data->player_pos[0];
	map_y = (int)data->player_pos[1];
	if (!ray[0])
		delta_dist[0] = 1e30;
	else
		delta_dist[0] = abs_value(1 / ray[0]);
	if (!ray[1])
		delta_dist[1] = 1e30;
	else
		delta_dist[1] = abs_value(1 / ray[1]);
	t_v2f	step;
	t_v2f	side_dist;
	bool	hit = false;


	if (ray[0] < 0)
	{
		step[0] = -1;
		side_dist[0] = (data->player_pos[0] - map_x) * delta_dist[0];
	}
	else
	{
		step[0] = 1;
		side_dist[0] = (map_x + 1.0 - data->player_pos[0]) * delta_dist[0];
	}
	if (ray[1] < 0)
	{
		step[1] = -1;
		side_dist[1] = (data->player_pos[1] - map_y) * delta_dist[1];
	}
	else
	{
		step[1] = 1;
		side_dist[1] = (map_y + 1.0 - data->player_pos[1]) * delta_dist[1];
	}

	while (!hit)
	{
		if (side_dist[0] < side_dist[1])
		{
			side_dist[0] += delta_dist[0];
			map_x += step[0];
			if (map_x > data->player_pos[0])
				data->side = NORTH;
			else
				data->side = SOUTH;
		}
		else
		{
			side_dist[1] += delta_dist[1];
			map_y += step[1];
			if (map_y > data->player_pos[1])
				data->side = WEST;
			else
				data->side = EAST;
		}

		if (data->map[map_x][map_y] == '1')
			hit = true;
	}

	float	perp_wall_dist;
	perp_wall_dist = side_dist[data->side / 3] - delta_dist[data->side / 3];
	
	int	line_height = (int)(IMG_HEIGHT / perp_wall_dist);
	int	draw_start = -line_height / 2 + IMG_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_start >= IMG_HEIGHT)
		draw_start = IMG_HEIGHT - 1;
	int	draw_end = line_height / 2 + IMG_HEIGHT / 2;
	if (draw_end >= IMG_HEIGHT)
		draw_end = IMG_HEIGHT - 1;

	float	wall_x;
	if (!(data->side / 3))
		wall_x = data->player_pos[1] + perp_wall_dist * ray[1];
	else
		wall_x = data->player_pos[0] + perp_wall_dist * ray[0];
	wall_x -= (int)wall_x;

	data->tex_x = (int)(wall_x * (float)TEX_WIDTH);
	if (!(data->side / 3) && ray[0] > 0)
		data->tex_x = TEX_WIDTH - data->tex_x - 1;
	if (data->side / 3 && ray[1] < 0)
		data->tex_x = TEX_WIDTH - data->tex_x - 1;

	data->step_all = 1.0 * TEX_HEIGHT / line_height;
	data->tex_pos = (draw_start - IMG_HEIGHT / 2 + line_height / 2) * data->step_all;

	draw_slice(data, x, draw_start, draw_end);
}

void	render(t_data *data)
{
	t_v2f	ray;
	int		i;

	i = 0;
	while (i < IMG_HEIGHT)
	{
		ray = get_ray(data, i);

		next_cube(data, ray, i);

		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	// draw_minimap(data);
}
