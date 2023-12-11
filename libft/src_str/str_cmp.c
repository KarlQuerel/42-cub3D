/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:28:33 by pcheron           #+#    #+#             */
/*   Updated: 2023/11/13 03:23:10 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// used in minishell
int	ft_is_str_in_strs(char *str, char **strs, int option)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (option)
		{
			if (!ft_strncmp(str, strs[i], ft_strlen(strs[i])))
				return (i + 1);
		}
		else
		{
			if (!ft_strncmp(str, strs[i], ft_strlen(str)))
				return (i + 1);
		}
		i++;
	}
	return (0);
}

bool	ft_endswith(char *str, char *end)
{
	const size_t	str_len = ft_strlen(str);
	const size_t	end_len = ft_strlen(end);

	return (str_len >= end_len && ft_strcomp(str + str_len - end_len, end));
}

bool	ft_strcomp(char *s1, char *s2)
{
	const int	s1_len = ft_strlen(s1);
	const int	s2_len = ft_strlen(s2);

	return (s1_len == s2_len && ft_strncmp(s1, s2, s1_len) == 0);
}
