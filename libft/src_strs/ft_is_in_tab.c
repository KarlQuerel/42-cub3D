/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:19:13 by atardif           #+#    #+#             */
/*   Updated: 2023/07/19 19:19:21 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_is_in_tab(char **tab, char *str)
{
	int	i;

	i = 0;
	if (!tab[i])
		return (0);
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], str))
			return (1);
		i++;
	}
	return (0);
}
