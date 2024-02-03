/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:17:21 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/27 17:17:58 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	open_doors(t_data *data)
{
	int	x;
	int	y;

	x = data->player_pos[0];
	y = data->player_pos[1];
	if (data->map[x + 1][y] == DOOR_CLOSED)
		data->map[x + 1][y] = DOOR_OPENED;
	if (data->map[x - 1][y] == DOOR_CLOSED)
		data->map[x - 1][y] = DOOR_OPENED;
	if (data->map[x][y + 1] == DOOR_CLOSED)
		data->map[x][y + 1] = DOOR_OPENED;
	if (data->map[x][y - 1] == DOOR_CLOSED)
		data->map[x][y - 1] = DOOR_OPENED;
}

static bool	can_i_close_the_door(t_data *data, int x, int y)
{
	int	v;
	int	w;

	v = data->player_pos[0];
	w = data->player_pos[1];
	return (!((x == v && -1 <= y - w && y - w <= 1) || \
	(y == w && -1 <= x - v && x - v <= 1)));
}

void	close_doors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == DOOR_OPENED && \
			can_i_close_the_door(data, i, j))
				data->map[i][j] = DOOR_CLOSED;
			j++;
		}
		i++;
	}
}
