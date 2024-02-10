/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:49:05 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 19:55:14 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_player_next_to_good(char **map, int j, int i)
{
	if (!is_char_valid_in_map((map[j][i + 1])) || \
	(i - 1 < 0) || !is_char_valid_in_map((map[j][i - 1])) || \
	(j - 1 < 0) || !is_char_valid_in_map((map[j - 1][i])) || \
	!map[j + 1] || !is_char_valid_in_map((map[j + 1][i])))
		return (false);
	return (true);
}

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
				return (is_player_next_to_good(data->map, x, y));
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

bool	setup_game(t_data *data)
{
	if (!checkup_map(data->map))
		return (err(ERROR), data_clear(data), false);
	if (!find_player(data))
		return (err(ERROR), data_clear(data), false);
	restore_floor_player(data);
	return (true);
}
