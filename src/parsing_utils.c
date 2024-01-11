/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:45:32 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/11 17:41:05 by kquerel          ###   ########.fr       */
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
		return (write(1, "north\n", 6), NORTH);
	if (!ft_strncmp(str, "SO", 2) && is_a_white_space(str[2]))
		return (write(1, "south\n", 6), SOUTH);
	if (!ft_strncmp(str, "WE", 2) && is_a_white_space(str[2]))
		return (write(1, "west\n", 5), WEST);
	if (!ft_strncmp(str, "EA", 2) && is_a_white_space(str[2]))
		return (write(1, "east\n", 5), EAST);
	if (!ft_strncmp(str, "F", 1) && is_a_white_space(str[1]))
		return (FLOOR);
	if (!ft_strncmp(str, "C", 1) && is_a_white_space(str[1]))
		return (CEILING);
	while (is_a_white_space(*str))
		str++;
	if (*str == '1' || *str == '0')
		return (write(1, "map\n", 4), MAP);
	write(1, "error\n", 6);
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

void	jump_int(char **str)
{
	while (is_a_white_space(**str))
		(*str)++;
	while (**str >= '0' && **str <= '9')
		(*str)++;
}

bool	atocolor(char *str, t_color *color)
{
	char	*tmp;
	int		color_tmp;

	tmp = str;
	while (is_a_white_space(*str))
		(*str)++;
	ft_atoi(&color_tmp, str);
	jump_int(&str);
	(*color)[0] = color_tmp;
	if (*str == ',')
		str++;
	else
		return (false);
	ft_atoi(&color_tmp, str);
	jump_int(&str);
	(*color)[1] = color_tmp;
	if (*str == ',')
		str++;
	else
		return (false);
	ft_atoi(&color_tmp, str);
	(*color)[2] = color_tmp;
	str = tmp;
	if ((*color)[0] < 0 || (*color)[0] > 255 || (*color)[1] < 0 || \
		(*color)[1] > 255 || (*color)[2] < 0 || (*color)[2] > 255)
		return (false);
	return (true);
}
