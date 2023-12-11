/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:18:06 by pcheron           #+#    #+#             */
/*   Updated: 2023/10/18 12:21:50 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_atoi(int *result, char *str)
{
	int	sign;

	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!*str)
			return (false);
	}
	*result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (*result > *result * 10 - 48 + *str && !(*result == INT_MAX / 10
				&& *str == '8' && !str[1] && sign < 0))
			return (false);
		*result = *result * 10 - 48 + *str;
		str++;
	}
	return (*result *= sign, true);
}
