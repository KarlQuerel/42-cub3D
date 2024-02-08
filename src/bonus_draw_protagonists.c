/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw_protagonists.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:42:18 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/08 12:03:36 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"


void	draw_collectible(t_data *data, int x, int end, int i)
{
	// static int	*imgs[] = {NULL, NULL, NULL, NULL, NULL, NULL};
	int			color;
	int			tex_y;

	// printf("wtf : %p\n", imgs[0]);
	// if (!imgs[1])
	// {
	// 	imgs[0] = (int *)data->door.addr;
	// 	imgs[1] = (int *)data->north.addr;
	// 	imgs[2] = (int *)data->south.addr;
	// 	imgs[3] = (int *)data->west.addr;
	// 	imgs[4] = (int *)data->east.addr;
	// 	imgs[5] = (int *)data->door.addr;
	// }
	// data->tex_pos_tmp = data->tex_pos; // faire un data->tex_pos special collectible
	while (i <= end && i < IMG_HEIGHT)
	{
		tex_y = (int)data->tex_pos & (128 - 1);
		data->tex_pos += data->step_all;
		// color = data->cheshire_cat[0].addr[tex_y * 128 + data->tex_x];
		color = 0x00101010;
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
