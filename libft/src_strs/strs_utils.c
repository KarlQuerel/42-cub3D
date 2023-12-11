/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:34:37 by dtelnov           #+#    #+#             */
/*   Updated: 2023/11/13 03:37:47 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strs_len(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ft_free_2d_array(void ***ptr)
{
	size_t	i;
	void	**arr;

	if (*ptr == NULL)
		return ;
	arr = *ptr;
	i = 0;
	while (arr[i])
	{
		if (*(arr + i))
		{
			free(*(arr + i));
			*(arr + i) = NULL;
		}
		++i;
	}
	if (*((void **)ptr))
	{
		free(*((void **)ptr));
		*((void **)ptr) = NULL;
	}
}
