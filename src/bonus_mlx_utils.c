/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:12:52 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/27 17:13:42 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	my_put_img_to_img_reverse(t_data *data, t_img_info *src, int x, int y)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			pixel = ((int *)src->addr)[i * 128 + 127 - j];
			if (pixel > 0)
				ft_my_put_pixel(data, x + i, y + j, pixel);
			j++;
		}
		i++;
	}
}

void	my_put_img_to_img(t_data *data, t_img_info *src, int x, int y)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			pixel = ((int *)src->addr)[i * 128 + j];
			if (pixel > 0)
				ft_my_put_pixel(data, x + i, y + j, pixel);
			j++;
		}
		i++;
	}
}
