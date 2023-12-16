/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:55:51 by pcheron           #+#    #+#             */
/*   Updated: 2023/12/16 15:57:17 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_atof_utils(float *val, char **arr, bool *afterdot, int *sign)
{
	if (sign)
	{
		if (**arr == '-')
		{
			*sign = -1;
			(*arr)++;
		}
		else if (**arr == '+')
			(*arr)++;
	}
	else if (afterdot)
	{
		if (**arr == '.')
			*afterdot = true;
		else
			*val = *val * 10.0 + (**arr - '0');
	}
}

bool	ft_atof_bool(float *val, char **arr)
{
	bool	afterdot;
	float	scale;
	int		sign;

	afterdot = false;
	scale = 1.0;
	sign = 1;
	ft_atof_utils(val, arr, NULL, &sign);
	while (**arr)
	{
		if (!isdigit(**arr) && **arr != '.' || (**arr == '.' && afterdot))
			return (false);
		if (afterdot)
		{
			scale /= 10.0;
			*val = *val + (**arr - '0') * scale;
		}
		else
			ft_atof_utils(val, arr, &afterdot, NULL);
		++(*arr);
	}
	*val = sign * *val;
	return (true);
}

float	ft_atof(char **arr)
{
	bool	afterdot;
	float	scale;
	int		sign;
	float	val;

	afterdot = false;
	scale = 1.0;
	sign = 1;
	val = 0;
	ft_atof_utils(&val, arr, NULL, &sign);
	while (**arr)
	{
		if (!isdigit(**arr) && **arr != '.' || (**arr == '.' && afterdot))
			return (val * sign);
		if (afterdot)
		{
			scale /= 10.0;
			val = val + (**arr - '0') * scale;
		}
		else
			ft_atof_utils(&val, arr, &afterdot, NULL);
		++(*arr);
	}
	return (sign * val);
}
