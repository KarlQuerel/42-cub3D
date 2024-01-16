/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:45:32 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/14 22:11:14 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	jump_int(char **str)
{
	while (is_a_white_space(**str))
		(*str)++;
	while (**str >= '0' && **str <= '9')
		(*str)++;
}

bool	is_alpha(char c)
{
	return (c >= '0' && c <= '9');
}

bool	atocolor(char *str, t_color *color)
{
	char	*tmp;
	int		color_tmp;

	tmp = str;
	while (is_a_white_space(*str))
		(*str)++;
	if (!is_alpha(*str) && *str != '+' && *str != '-')
		return (false);
	(ft_atoi(&color_tmp, str), jump_int(&str));
	(*color)[0] = color_tmp;
	if (*str == ',')
		str++;
	else
		return (false);
	if (!is_alpha(*str) && *str != '+' && *str != '-')
		return (false);
	(ft_atoi(&color_tmp, str), jump_int(&str));
	(*color)[1] = color_tmp;
	if (*str == ',')
		str++;
	else
		return (false);
	if (!is_alpha(*str) && *str != '+' && *str != '-')
		return (false);
	ft_atoi(&color_tmp, str);
	// printf("error6\n");
	while (is_alpha(*str) || *str == '+' || *str == '-')
		str++;
	(*color)[2] = color_tmp;
	if ((*color)[0] < 0 || (*color)[0] > 255 || (*color)[1] < 0 || \
		(*color)[1] > 255 || (*color)[2] < 0 || (*color)[2] > 255 || *str)
		return (false);
	str = tmp;
	// printf("error12\n");
	return (true);
}
