/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:36:39 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/14 16:36:19 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}

static int	ft_countw(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		if (j > 0)
			k++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (k);
}

static int	ft_lenw(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static char	**ft_split2(char const *s, char **strs, char c, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < ft_countw(s, c))
	{
		strs[j] = malloc(sizeof(char) * (ft_lenw(s, c, i) + 1));
		if (strs[j] == NULL)
			return (ft_free_strs(strs), NULL);
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			strs[j][k] = s[i];
			i++;
			k++;
		}
		strs[j][k] = '\0';
		j++;
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;

	if (s == NULL)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_countw(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	return (ft_split2(s, strs, c, i));
}
