/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:12:51 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 21:07:44 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_my_put_pixel(t_data *data, int x, int y, int color)
{
	((int *)data->img.addr)[x * (IMG_WIDTH * !data->drug + IMG_HEIGHT * \
	data->drug) + ((IMG_WIDTH - IMG_HEIGHT) / 2 * \
	IMG_HEIGHT * data->drug) + y] = color;
}

	// (IMG_WIDTH * !data->drug + IMG_HEIGHT * data->drug)
	// ((int *)data->img.addr)[x * IMG_HEIGHT  + y + IMG_WIDTH *
	//	((IMG_WIDTH - IMG_HEIGHT) / 2) ] = color;