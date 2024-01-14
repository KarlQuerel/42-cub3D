/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:10:52 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/14 18:16:25 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_values(t_data *data)
{
	data->controls.w = false;
	data->controls.s = false;
	data->controls.a = false;
	data->controls.d = false;
	data->controls.left_arrow = false;
	data->controls.right_arrow = false;
}

void	mini_mlx_clear(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	data_clear(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	if (data->north.img)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->east.img)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.img)
		mlx_destroy_image(data->mlx, data->west.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_strs(&data->map);
	exit(0);
	return (0);
}

bool	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_print_fd(2, "Error\nmlx : error on new ptr"), false);
	data->win = mlx_new_window(data->mlx, IMG_WIDTH, IMG_HEIGHT, "cub3D");
	if (!data->win)
		return (ft_print_fd(2, "Error\nmlx : error on new window\n"),
			mlx_destroy_image(data->mlx, data->img.img),
			mlx_destroy_display(data->mlx), free(data->mlx), false);
	data->img.img = mlx_new_image(data->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!data->img.img)
		return (ft_print_fd(2, "Error\nmlx : error on new img\n"),
			mlx_destroy_display(data->mlx), free(data->mlx), false);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.ll, &data->img.endian);
	if (!data->img.addr)
		return (ft_print_fd(2, "Error\nmlx : error on get addr\n"),
			mlx_destroy_image(data->mlx, data->img.img),
			mlx_destroy_display(data->mlx), free(data->mlx), false);
	data->img.bpp /= 8;
	return (true);
}
