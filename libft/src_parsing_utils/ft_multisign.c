/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multisign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:02 by atardif           #+#    #+#             */
/*   Updated: 2023/05/18 17:51:53 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_multisign(char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isdigit(str[i]))
		sign++;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			sign++;
		if (sign > 1)
			return (false);
		i++;
	}
	return (true);
}
