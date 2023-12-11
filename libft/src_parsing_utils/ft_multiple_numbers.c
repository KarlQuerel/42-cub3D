/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:47:08 by atardif           #+#    #+#             */
/*   Updated: 2023/05/18 17:50:49 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_multiple_numbers(char *str)
{
	int	i;
	int	count;
	int	end;

	i = 0;
	count = 0;
	end = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			count++;
		if (ft_isspace(str[i]) && count > 0)
			end++;
		if (!ft_isspace(str[i]) && end > 0)
			return (false);
		i++;
	}
	return (true);
}
