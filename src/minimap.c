/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:29:45 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/14 18:16:09 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_map_components(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= TILE_SIZE)
	{
		j = 0;
		while (j <= TILE_SIZE)
		{
			ft_my_put_pixel(data, x * TILE_SIZE + i, y * TILE_SIZE + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *data, int x, int y)
{
	int	it_x;
	int	it_y;

	it_x = 0;
	while (it_x < MINIMAP_HEIGHT)
	{
		it_y = 0;
		while (it_y < MINIMAP_WIDTH)
		{
			if (x + it_x > data->width - 2 || y + it_y > data->height - 1 || \
			data->map[x + it_x][y + it_y] == '1' || \
			data->map[x + it_x][y + it_y] == 0 || \
			is_a_white_space(data->map[x + it_x][y + it_y]))
				draw_map_components(data, it_x, it_y, 0x000000);
			else if ((x + it_x) == (int)data->player_pos[0] && \
			(y + it_y) == (int)data->player_pos[1])
				draw_map_components(data, it_x, it_y, 0x00ffffff);
			else
				draw_map_components(data, it_x, it_y, 0x003722);
			it_y++;
		}
		it_x++;
	}
}
