/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:49:05 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/03 10:03:42 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	find_player(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'N' || data->map[x][y] == 'S' \
				|| data->map[x][y] == 'W' || data->map[x][y] == 'E')
			{
				data->player_pos[0] = x + 0.5f;
				data->player_pos[1] = y + 0.5f;
				data->plane[0] = 0.0f;
				data->plane[1] = 0.57f;
				setup_dir(data, x, y);
				return (true);
			}
			y++;
		}
		x++;
	}
	return (false);
}

static void	restore_floor_player(t_data *data)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				c = data->map[i][j];
				if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
					data->map[i][j] = '0';
				j++;
			}
			i++;
		}
	}
}

bool	setup_game(t_data *data)	// + msg
{
	if (!checkup_map(data->map))
		return (data_clear(data), false);
	if (!find_player(data))
		return (data_clear(data), false);
	restore_floor_player(data);
	return (true);
}
