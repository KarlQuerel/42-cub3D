/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:45:32 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/17 17:48:13 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_strs(char ***strs)
{
	int	i;

	i = 0;
	if (strs && *strs)
	{
		while ((*strs)[i])
		{
			free((*strs)[i]);
			i++;
		}
		free(*strs);
		*strs = NULL;
	}
}

bool	is_a_white_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	identify_line(char *str)
{
	if (!ft_strncmp(str, "NO", 2) && is_a_white_space(str[2]))
		return (NORTH);
	if (!ft_strncmp(str, "SO", 2) && is_a_white_space(str[2]))
		return (SOUTH);
	if (!ft_strncmp(str, "WE", 2) && is_a_white_space(str[2]))
		return (WEST);
	if (!ft_strncmp(str, "EA", 2) && is_a_white_space(str[2]))
		return (EAST);
	if (!ft_strncmp(str, "F", 1) && is_a_white_space(str[1]))
		return (FLOOR);
	if (!ft_strncmp(str, "C", 1) && is_a_white_space(str[1]))
		return (CEILING);
	while (is_a_white_space(*str))
		str++;
	if (*str == '1' || *str == '0')
		return (MAP);
	err("");
	return (0);
}

int	count_char_in_str(char c, char *str)
{
	int	count;

	count = 0;
	if (str)
	{
		while (*str)
		{
			if (c == *str)
				count++;
			str++;
		}
	}
	return (count);
}

float	abs_value(float x)
{
	return ((x < 0) * -x + x * (x >= 0));
}
