/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:33:29 by pcheron           #+#    #+#             */
/*   Updated: 2023/07/17 12:47:11 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_pow(int x, int n)
{
	if (n == 0)
		return (1);
	if (n > 0)
		return (x * ft_pow(x, n - 1));
	return (0);
}

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*sp_ca(int n)
{
	char	*r;

	if (n == -2147483648)
		r = ft_strdup("-2147483648");
	else
	{
		r = malloc(sizeof(char) * 2);
		if (r == NULL)
			return (NULL);
		r[0] = '0';
		r[1] = 0;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	if (n == 0 || n == -2147483648)
		return (sp_ca(n));
	str = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		j++;
	}
	while (i < ft_intlen(n))
	{
		str[i + j] = n / ft_pow(10, ft_intlen(n) - 1 - i) % 10 + 48;
		i++;
	}
	str[i + j] = '\0';
	return (str);
}
