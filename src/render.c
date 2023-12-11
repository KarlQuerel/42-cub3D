/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:44:49 by pcheron           #+#    #+#             */
/*   Updated: 2023/12/11 18:42:14 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_v2f	get_ray(t_data *data, int x)
{
	t_v2f	ray;
	float	cam;

	cam = 2.0f * (float)x / (float)IMG_WIDTH - 1;
	ray[0] = data->camera_dir[0] + data->plane[0] * cam;
	ray[1] = data->camera_dir[1] + data->plane[1] * cam;
	return (ray);
}

void	next_cube(t_data *data, t_v2f ray, int x)
{
	int map_x = (int)data->player_pos[0];
	int map_y = (int)data->player_pos[1];


	t_v2f	delta_dist;

	// delta_dist[0] = (!ray[0]) ? 1e30 : abs_value(1 / ray[0]);
	// delta_dist[1] = (!ray[1]) ? 1e30 : abs_value(1 / ray[1]);
	delta_dist[0] = sqrt(1 + (ray[1] * ray[1]) / (ray[0] * ray[0]));
	delta_dist[1] = sqrt(1 + (ray[0] * ray[0]) / (ray[1] * ray[1]));


	t_v2f	step;
	t_v2f	side_dist;
	bool	hit = false;
	int		side;


	step[0] = 1 - (ray[0] < 0) * 2;
	side_dist[0] = (1.0f * (ray[0] >= 0) + data->player_pos[0] - map_x) * delta_dist[0];
	// if (ray[0] < 0)
	// {
	// 	step = -1;
	// 	side_distx = (data->player_pos[0] - map_x) * delta_dist[x];
	// }
	// else
	// {
	// 	step = 1;
	// 	side_distx = (data->player_pos[0] + 1f - map_x) * delta_dist[x];
	// }
	step[1] = 1 - (ray[1] < 0) * 2;
	side_dist[1] = (1.0f * (ray[1] >= 0) + data->player_pos[1] - map_y) * delta_dist[1];

	while (!hit)
	{
		if (side_dist[0] < side_dist[1])
		{
			side_dist[0] += delta_dist[0];
			map_x += step[0];
			side = 0;
		}
		else
		{
			side_dist[1] += delta_dist[1];
			map_y += step[1];
			side = 1;
		}

		if (data->map[map_x][map_y] == '1')
		{
			hit = true;
			// printf("j'ai touche qqchose : ");
			// put_v2f(ray);
		}
	}

	float	perp_wall_dist;
	perp_wall_dist = side_dist[side] - delta_dist[side];
	
	int	line_height = (int)(IMG_HEIGHT / perp_wall_dist);
	int	draw_start = -line_height / 2 + IMG_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	int	draw_end = line_height / 2 + IMG_HEIGHT / 2;
	if (draw_end >= IMG_HEIGHT)
		draw_end = IMG_HEIGHT - 1; // pourquoi -1 ?


	int	color = 0x00FF0000;
	if (side)
		color /=2;
	put_col(data, x, draw_start, draw_end, color);

	//timing for input and FPS counter
    // oldTime = time;
    // time = getTicks();
    // double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    // print(1.0 / frameTime); //FPS counter
    // redraw();
    // cls();

    // //speed modifiers
    // double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    // double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
	
	
}

void	render(t_data *data)
{
	t_v2f	ray;
	int		i;

	i = 0;
	while (i < IMG_WIDTH)
	{
		ray = get_ray(data, i);

		next_cube(data, ray, i);

		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
