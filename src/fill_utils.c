/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:41:44 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/18 18:55:23 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	while (!is_a_white_space(str[i]) && str[i])
		i++;
	*dest = ft_strndup(str, i);
	if (!*dest)
		return (false);
	return (true);
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
