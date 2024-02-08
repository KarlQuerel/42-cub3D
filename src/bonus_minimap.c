/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:27:33 by kquerel           #+#    #+#             */
/*   Updated: 2024/02/05 14:27:44 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
			ft_my_put_pixel(data, x * TILE_SIZE + i, y * TILE_SIZE \
				+ j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *data, int x, int y)
{
	data->it_x = 0;
	while (data->it_x < MINIMAP_HEIGHT)
	{
		data->it_y = 0;
		while (data->it_y < MINIMAP_WIDTH)
		{
			if (x + data->it_x > data->width - 2 || \
				y + data->it_y > data->height - 1 || \
				data->map[x + data->it_x][y + data->it_y] == '1' || \
				data->map[x + data->it_x][y + data->it_y] == 0 || \
				is_a_white_space(data->map[x + data->it_x][y + data->it_y]) || \
				y + data->it_y > ft_strlen(data->map[x + data->it_x]))
				draw_map_components(data, data->it_x, data->it_y, 0x000000);
			else if (data->map[x + data->it_x][y + data->it_y] == 'D' || \
				data->map[x + data->it_x][y + data->it_y] == 'O')
				draw_map_components(data, data->it_x, data->it_y, 0x00F6BE00);
			else if (data->map[x + data->it_x][y + data->it_y] == '0')
				draw_map_components(data, data->it_x, data->it_y, 0x003722);
			if ((x + data->it_x) == (int)data->player_pos[0] && \
				(y + data->it_y) == (int)data->player_pos[1])
				draw_map_components(data, data->it_x, data->it_y, 0x00ffffff);
			data->it_y++;
		}
		data->it_x++;
	}
}
