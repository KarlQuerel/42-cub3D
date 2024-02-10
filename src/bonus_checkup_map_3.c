/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checkup_map_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:11 by kquerel           #+#    #+#             */
/*   Updated: 2024/02/10 18:22:10 by kquerel          ###   ########.fr       */
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
			(*map)[i] != 'E' && (*map)[i] != 'D' && (*map)[i] != 'C'\
			&& !is_a_white_space((*map)[i]))
				return (false);
			i++;
		}	
		map++;
	}
	return (true);
}

bool	is_char_valid_in_map(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || \
	c == 'W' || c == 'E' || c == 'D' || c == 'C');
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
			if (map[j][i] == '0' || map[j][i] == 'D')
			{
				if (!is_char_valid_in_map((map[j][i + 1])) || \
				(i - 1 < 0) || !is_char_valid_in_map((map[j][i - 1])) || \
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
