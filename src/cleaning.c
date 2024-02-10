/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:47:32 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 21:07:34 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_strs(char ***strs)
{
	int	i;

	i = 0;
	if (strs && *strs)
	{
		while ((*strs)[i])
		{
			free((*strs)[i]);
			i++;
		}
		free(*strs);
		*strs = NULL;
	}
}

void	clear_walls_col_text(t_data *data)
{
	if (data->north.img)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->west.img)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->east.img)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->floor.img)
		mlx_destroy_image(data->mlx, data->floor.img);
	if (data->ceiling.img)
		mlx_destroy_image(data->mlx, data->ceiling.img);
	if (data->door.img)
		mlx_destroy_image(data->mlx, data->door.img);
	if (data->mushroom.img)
		mlx_destroy_image(data->mlx, data->mushroom.img);
	if (data->dialog_box.img)
		mlx_destroy_image(data->mlx, data->dialog_box.img);
}

void	clear_characters(t_data *data)
{
	int	i;

	i = 0;
	while (i < 18)
	{
		if (i < 18 && data->alice[i].img)
			mlx_destroy_image(data->mlx, data->alice[i].img);
		if (i < 10 && data->white_rabbit[i].img)
			mlx_destroy_image(data->mlx, data->white_rabbit[i].img);
		if (i < 2 && data->white_rabbit_door[i].img)
			mlx_destroy_image(data->mlx, data->white_rabbit_door[i].img);
		if (i < 17 && data->catterpilar[i].img)
			mlx_destroy_image(data->mlx, data->catterpilar[i].img);
		if (i < 6 && data->wall_cat[i].img)
			mlx_destroy_image(data->mlx, data->wall_cat[i].img);
		if (i < 6 && data->dialog_cat[i].img)
			mlx_destroy_image(data->mlx, data->dialog_cat[i].img);
		if (i < 15 && data->dialog[i].img)
			mlx_destroy_image(data->mlx, data->dialog[i].img);
		i++;
	}
}

int	data_clear(t_data *data)
{
	clear_walls_col_text(data);
	clear_characters(data);
	mlx_destroy_window(data->mlx, data->win);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_strs(&data->map);
	coll_clear(&data->coll);
	return (0);
}
