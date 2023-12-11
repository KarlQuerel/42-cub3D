/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:35:39 by pcheron           #+#    #+#             */
/*   Updated: 2023/12/10 13:06:37 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// option syntax
// 0 no free
// 1 free only left
// 2 free only right
// 3 free both
bool	ft_strjoin(char **dest, char *left, char *right, int option)
{
	char	*new;

	if (!left || !right || !dest)
		return (false);
	new = malloc(ft_strlen(left) + ft_strlen(right) + 1);
	if (!new)
		return (false);
	ft_memcpy(new, left, ft_strlen(left));
	ft_memcpy(new + ft_strlen(left), right, ft_strlen(right));
	new[ft_strlen(left) + ft_strlen(right)] = 0;
	*dest = new;
	if (option & 1)
		free(left);
	if (option & 2)
		free(right);
	return (true);
}
