/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:01:12 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/18 13:16:08 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_print_fd(1, "<%s>\n", strs[i]);
		i++;
	}
}
