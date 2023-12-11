/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:14:41 by pcheron           #+#    #+#             */
/*   Updated: 2023/07/27 19:15:33 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_arg_len(char c, va_list args)
{
	if (c == 's')
		return (ft_strlen(va_arg(args, char *)));
	else if (c == 'c')
		return (1);
	return (-1);
}
