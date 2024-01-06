/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:44:49 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/06 13:49:14 by kquerel          ###   ########.fr       */
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
	// delta_dist[0] = (!ray[0]) ? 1e30 : abs_value(1 / ray[0]);
	// delta_dist[1] = (!ray[1]) ? 1e30 : abs_value(1 / ray[1]);
	//Norminette a dit :
	//Ternaries are forbidden -> du coup code du pauvre sans panache
	if (!ray[0])
		delta_dist[0] = 1e30;
	else
		delta_dist[0] = abs_value(1 / ray[0]);
	if (!ray[1])
		delta_dist[1] = 1e30;
	else
		delta_dist[1] = abs_value(1 / ray[1]);
	// delta_dist[0] = sqrt(1 + (ray[1] * ray[1]) / (ray[0] * ray[0]));
	// delta_dist[1] = sqrt(1 + (ray[0] * ray[0]) / (ray[1] * ray[1]));


	t_v2f	step;
	t_v2f	side_dist;
	bool	hit = false;
	int		side;


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
				side = NORTH;
			else
				side = SOUTH;
		}
		else
		{
			side_dist[1] += delta_dist[1];
			map_y += step[1];
			if (map_y > data->player_pos[1])
				side = WEST;
			else
				side = EAST;
		}

		if (data->map[map_x][map_y] == '1')
			hit = true;
	}

	float	perp_wall_dist;
	perp_wall_dist = side_dist[side / 3] - delta_dist[side / 3];
	
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
	if (!(side / 3))
		wall_x = data->player_pos[1] + perp_wall_dist * ray[1];
	else
		wall_x = data->player_pos[0] + perp_wall_dist * ray[0];
	wall_x -= (int)wall_x;

	int	tex_x = (int)(wall_x * (float)TEX_WIDTH);
	if (!(side / 3) && ray[0] > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (side / 3 && ray[1] < 0)
		tex_x = TEX_WIDTH - tex_x - 1;

	float	step_all = 1.0 * TEX_HEIGHT / line_height;
	float	tex_pos = (draw_start - IMG_HEIGHT / 2 + line_height / 2) * step_all;

	int	it = 0;
	//FLOOR + PLAFOND
	while (it <= draw_start && it < IMG_HEIGHT)
	{
		ft_my_put_pixel(data, it, x, 0x00223240);
		it++;
	}
	// //while test pour le sol
	// data->floor.img = mlx_xpm_file_to_image(data->mlx, "img/XPM/Floor_and_ceiling/FLOOR.xpm", &data->img_width, &data->img_height);
	// if (!data->floor.img)
	// {
	// 	write(2, "xpm to img: floor error\n", 24);
	// 	exit(1);
	// }
	//LE CODE CI DESSUS FREEZE L'ORDINATEUR
	
	// while (it <= draw_start && it < IMG_HEIGHT)
	// {
	// 	float rayDirX0 = data->camera_dir[0] - data->plane[0];
	// 	float rayDirY0 = data->camera_dir[1] - data->plane[1];
	// 	float rayDirX1 = data->camera_dir[0] + data->plane[0];
	// 	float rayDirY1 = data->camera_dir[1] + data->plane[1];

	// 	int	p = it - IMG_HEIGHT / 2;
	// 	float posZ = 0.5 * IMG_HEIGHT;

	// 	float rowDistance = posZ / p;

	// 	float floorStepx = rowDistance * (rayDirX1 - rayDirX0) / IMG_HEIGHT;
	// 	float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / IMG_HEIGHT;

	// 	float floorX = data->player_pos[0] + rowDistance * rayDirX0;
	// 	float floorY = data->player_pos[1] + rowDistance * rayDirY0;

	// 	int	x = 0;
	// 	while (x < IMG_HEIGHT)
	// 	{
	// 		int	cellX = (int)(floorX);
	// 		int	cellY = (int)(floorY);

	// 		int	tx = (int)(TEX_WIDTH * (floorX - cellX)) & (TEX_WIDTH - 1);
	// 		int	ty = (int)(TEX_HEIGHT * (floorY - cellY)) & (TEX_HEIGHT - 1);

	// 		floorX += floorStepx;
	// 		floorY += floorStepY;
			
	// 		//DRAW TEXTURES - Maitre Pablo
	// 		/*
	// 		// choose texture and draw the pixel
	// 		int floorTexture = 3;
	// 		int ceilingTexture = 6;
	// 		Uint32 color;

	// 		// floor
	// 		color = texture[floorTexture][texWidth * ty + tx];
	// 		color = (color >> 1) & 8355711; // make a bit darker
	// 		buffer[y][x] = color;

	// 		//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
	// 		color = texture[ceilingTexture][texWidth * ty + tx];
	// 		color = (color >> 1) & 8355711; // make a bit darker
	// 		buffer[screenHeight - y - 1][x] = color; */
	// 		x++;
	// 	}
	// }

	//WALLS
	while (it <= draw_end && it < IMG_HEIGHT)
	{
		int	tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step_all;
		int color;
		if (side == NORTH)
			color = ((int *)data->north.addr)[tex_y * TEX_HEIGHT + tex_x];
		else if (side == SOUTH)
			color = ((int *)data->south.addr)[tex_y * TEX_HEIGHT + tex_x];
		else if (side == WEST)
			color = ((int *)data->west.addr)[tex_y * TEX_HEIGHT + tex_x];
		else
			color = ((int *)data->east.addr)[tex_y * TEX_HEIGHT + tex_x];
		
		// pour assombrir certains murs
		if (side - 2)
			color = (color >> 1) & 8355711;
		ft_my_put_pixel(data, it, x, color);
		it++;
	}
	//CEILING -> ne sera plus necessaire une fois les textures implementees
	while (it < IMG_HEIGHT)
	{
		ft_my_put_pixel(data, it, x, 0x00353535);
		it++;
	}
	
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
	draw_minimap(data);
}
