/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw_protagonists.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:42:18 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/03 09:12:30 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"


// void	draw_collectible(t_data *data)
// {

// }

// void	draw_protagonist(t_data *data)
// {
	
// }

void	draw_someone(t_data *data)
{
	int	pos_someone_x;
	int	pos_someone_y;

	pos_someone_x = data->map_x - (data->side == NORTH) + (data->side == SOUTH);
	pos_someone_y = data->map_y - (data->side == EAST) + (data->side == WEST);
	if (data->map[pos_someone_x][pos_someone_y] == 'C')
	{
		// draw_collectible();
	}
	else if (data->map[pos_someone_x][pos_someone_y] == 'P')
	{
		// draw_protagonist();
	}
}
