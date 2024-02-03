/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:11:44 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/27 10:30:30 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_a_white_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	unleek_gnl(int fd)
{
	char	*line;

	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			return ;
		free(line);
	}
}

void	jump_word(char **str)
{
	while (is_a_white_space(**str))
		(*str)++;
	while (!is_a_white_space(**str) && **str)
		(*str)++;
	while (is_a_white_space(**str))
		(*str)++;
}

char	*ft_strndup(char *s, int size)
{
	char	*str;
	int		i;

	if (size < 0)
		return (malloc(1));
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[size] = 0;
	return (str);
}

bool	dup_next_world(char *str, char **dest)
{
	int	i;

	while (is_a_white_space(*str))
		str++;
	i = 0;
	while (!is_a_white_space(str[i]) && str[i] && str[i] != '\n')
		i++;
	*dest = ft_strndup(str, i);
	if (!*dest)
		return (false);
	return (true);
}
