/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:53:29 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/20 13:20:52 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	data_clear_2(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	if (data->north.img)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->east.img)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.img)
		mlx_destroy_image(data->mlx, data->west.img);
	clear_characters(data);
	clear_text(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_strs(&data->map);
	exit(0);
	return (0);
}

int	data_clear(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	if (data->north.img)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->east.img)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.img)
		mlx_destroy_image(data->mlx, data->west.img);
	clear_characters(data);
	clear_text(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_strs(&data->map);
	free(data->mlx);
	return (0);
}
