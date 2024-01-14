/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:18:43 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/14 18:14:41 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_left_wall(char **map)
{
	int	i;
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(*map);
	while (*map)
	{
		i = 0;
		while (is_a_white_space((*map)[i]))
			i++;
		if ((*map)[i] != '1' || i < start - 1 || i > end)
			return (false);
		start = i;
		while ((*map)[i] == '1')
			i++;
		end = i;
		map++;
	}
	return (true);
}

bool	check_right_wall(char **map)
{
	int	i;
	int	j;
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(*map);
	while (*map != NULL)
	{
		j = 0;
		i = ft_strlen(*map) - 1;
		while (is_a_white_space((*map)[i]))
			i--;
		while (i + j > end + 1 && (*map)[i + j] == '1')
			j--;
		if ((*map)[i + j] != '1' || i + j < start - 1 || i + j > end + 1)
			return (false);
		end = i;
		i += j;
		while (i >= 0 && (*map)[i] == '1')
			i--;
		start = i + 1;
		map++;
	}
	return (true);
}

int	nb_player(char **map)
{
	return (count_char_in_map('N', map) + count_char_in_map('S', map) \
	+ count_char_in_map('W', map) + count_char_in_map('E', map));
}

bool	is_many_map(char **map)
{
	while (*map && count_char_in_str('1', *map))
		map++;
	while (*map && !count_char_in_str('1', *map))
		map++;
	if (*map && count_char_in_str('1', *map))
		return (false);
	return (true);
}

bool	checkup_map(char **map)
{
	if (nb_player(map) != 1)
		return (false);
	if (!check_left_wall(map))
		return (false);
	if (!check_right_wall(map))
		return (false);
	if (!is_many_map(map))
		return (false);
	if (!is_char_in_map_are_normal(map))
		return (false);
	if (!is_a_zero_next_to_wrong(map))
		return (false);
	return (true);
}
