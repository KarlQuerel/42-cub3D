/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:56:17 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/26 09:47:07 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (err("Mlx: error on new ptr"), false);
	data->win = mlx_new_window(data->mlx, IMG_WIDTH, IMG_HEIGHT, "cub3D");
	if (!data->win)
		return (err("Mlx: error on new img"), false);
	data->img.img = mlx_new_image(data->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!data->img.img)
		return (err("Mlx: error on new img"), false);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.ll, &data->img.endian);
	if (!data->img.addr)
		return (err("Mlx: error on get addr"), false);
	data->img.bpp /= 8;
	return (true);
}
