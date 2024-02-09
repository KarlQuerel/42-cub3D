/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw_protagonists.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:42:18 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 12:39:08 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	draw_collectible(t_data *data, int x, int end, int i)
{
	int			color;
	int			tex_y;

	while (i <= end && i < IMG_HEIGHT)
	{
		tex_y = (int)data->tex_pos & (128 - 1);
		data->tex_pos += data->step_all;
		color = data->mushroom.addr[tex_y * 128 + data->tex_x];
		if (!(color & 0xff000000))
			ft_my_put_pixel(data, i, x, color);
		i++;
	}
}

// void	draw_protagonist(t_data *data)
// {
	
// }

void	draw_someone(t_data *data, int col)
{
	int	pos_someone_x;
	int	pos_someone_y;

	pos_someone_x = data->map_x - (data->side == NORTH) + (data->side == SOUTH);
	pos_someone_y = data->map_y - (data->side == EAST) + (data->side == WEST);
	if (data->map[pos_someone_x][pos_someone_y] == 'C')
	{
		draw_collectible(data, col, data->draw_end, data->draw_start);
	}
	// else if (data->map[pos_someone_x][pos_someone_y] == 'P')
	// {
	// 	// draw_protagonist();
	// }
}
