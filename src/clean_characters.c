/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:38:50 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/19 17:41:32 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clear_characters(t_data *data)
{
	int	i;

	i = 0;
	while ((i < 10))
	{
		if (data->white_rabbit[i].img)
			mlx_destroy_image(data->mlx, data->white_rabbit[i].img);
		i++;
	}
	i = 0;
	while ((i < 18))
	{
		if (data->catterpilar[i].img)
			mlx_destroy_image(data->mlx, data->catterpilar[i].img);
		if (data->alice[i].img)
			mlx_destroy_image(data->mlx, data->alice[i].img);
		i++;
	}
	mlx_destroy_image(data->mlx, data->door.img);
	mlx_destroy_image(data->mlx, data->dialog_box.img);
}

void	set_null(t_data *data)
{
	data->door.img = NULL;
	data->door.addr = NULL;
	data->dialog_box.img = NULL;
	data->dialog_box.addr = NULL;
}

void	setup_characters(t_data *data)
{
	int	i;

	i = 0;
	while ((i < 10))
	{
		data->white_rabbit[i].img = NULL;
		data->white_rabbit[i].addr = NULL;
		i++;
	}
	i = 0;
	while ((i < 18))
	{
		data->catterpilar[i].img = NULL;
		data->catterpilar[i].addr = NULL;
		i++;
	}
	i = 0;
	while ((i < 18))
	{
		data->alice[i].img = NULL;
		data->alice[i].addr = NULL;
		i++;
	}
	set_null(data);
}
