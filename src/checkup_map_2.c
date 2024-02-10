/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:53:06 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 09:46:22 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_char_in_map(char c, char **map)
{
	int	count;

	count = 0;
	if (map)
	{
		while (*map)
		{
			count += count_char_in_str(c, *map);
			map++;
		}
	}
	return (count);
}

bool	is_char_in_map_are_normal(char **map)
{
	int	i;

	while (map && *map)
	{
		i = 0;
		while ((*map)[i])
		{
			if ((*map)[i] && (*map)[i] != '1' && (*map)[i] != '0' && \
			(*map)[i] != 'N' && (*map)[i] != 'S' && (*map)[i] != 'W' && \
			(*map)[i] != 'E' && (*map)[i] != 'D' \
			&& !is_a_white_space((*map)[i]))
			{
				// printf("wtf<%c>\n", (*map)[i]);
				return (false);
			}
			i++;
		}	
		map++;
	}
	return (true);
}

bool	is_char_valid_in_map(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || \
	c == 'W' || c == 'E');
}

bool	is_a_zero_next_to_wrong(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map && map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0')
			{
				if (!is_char_valid_in_map((map[j][i + 1])) || \
				(i - 1 < 0) ||!is_char_valid_in_map((map[j][i - 1])) || \
				(j - 1 < 0) || !is_char_valid_in_map((map[j - 1][i])) || \
				!map[j + 1] || !is_char_valid_in_map((map[j + 1][i])))
					return (false);
			}
			i++;
		}	
		j++;
	}
	return (true);
}

void	setup_dir(t_data *data, int x, int y)
{
	float	angle;
	t_v2f	old_dir;

	(void)x;
	(void)y;
	data->camera_dir[0] = -1.0;
	data->camera_dir[1] = 0.0;
	angle = 0.0;
	if (data->map[x][y] == 'S')
		angle = PI;
	else if (data->map[x][y] == 'W')
		angle = PI + 1.57;
	else if (data->map[x][y] == 'E')
		angle = 1.57;
	old_dir = data->camera_dir;
	rotate(data, (-angle), old_dir);
	rotate(data, (-angle), old_dir);
}
