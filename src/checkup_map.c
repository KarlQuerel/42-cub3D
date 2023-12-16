/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:18:43 by pcheron           #+#    #+#             */
/*   Updated: 2023/12/12 11:16:07 by pcheron          ###   ########.fr       */
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
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(*map) - 1;
	// printf("RIGHT :\n");
	while (*map)
	{
		// printf("nouvelle ligne :\n");
		i = ft_strlen(*map) - 1;
		while (is_a_white_space((*map)[i]))
			i--;
		if ((*map)[i] != '1' || i < start - 1 || i > end + 1)
			return (false);
		end = i;
		while (i >= 0 && (*map)[i] == '1')
		{
			// printf("j'en suis la : %s\n", (*map) + i);
			i--;
		}
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

bool	is_char_in_map_are_normal(char **map)
{
	int	i;

	while (map && *map)
	{
		i = 0;
		while ((*map)[i])
		{
			if ((*map)[i] && (*map)[i] != '1' && (*map)[i] != '0' && (*map)[i] != 'N' && (*map)[i] != 'S' && (*map)[i] != 'W' && (*map)[i] != 'E' && !is_a_white_space((*map)[i]))
				return (false);
			i++;
		}	
		map++;
	}
	return (true);
}

bool	is_char_valid_in_map(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E');
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
				if (!is_char_valid_in_map((map[j][i + 1])) || !is_char_valid_in_map((map[j][i - 1])) || !is_char_valid_in_map((map[j - 1][i])) || !is_char_valid_in_map((map[j + 1][i])))
					return (false);
			}
			i++;
		}	
		j++;
	}
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

// void	sauver_le_player(map, int* x, int *y)
// {
// 	*x = 0;
// 	while (map[*x])
// 	{
// 		*y = 0;
// 		while (map[*x][*y])
// 		{
// 			if (map[*x][*y] == 'N')
// 				return ;
// 			*y++;
// 		}
// 		*x++;
// 	}
// }

// bool	innondation(char **map, int x, int y)
// {
// 	if (!x || !y || !map[x] || !map[x][y])
// 		return (true);
// 	if (x < 0)
// 		sauver_le_player(map, &x, &y);
// 	if (map[x][y] == '0')
// 	{
// 		map[x][y] = '2';
// 		innondation(map, x, y - 1);
// 		innondation(map, x + 1, y);
// 		innondation(map, x, y + 1);
// 		innondation(map, x - 1, y);
// 	}
// 	// checker la map
// 	return (true);
// }
