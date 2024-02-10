/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:47:41 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 21:01:38 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	make_bonus_null(t_data *data)
{
	data->drug = false;
	data->drug_timer = 0;
	data->display_catterpilar = false;
	data->coll = NULL;
}

static void	setup_img_null(t_data *data)
{
	int	i;

	i = 0;
	while (i < 18)
	{
		if (i < 18)
			data->alice[i].img = NULL;
		if (i < 10)
			data->white_rabbit[i].img = NULL;
		if (i < 2)
			data->white_rabbit_door[i].img = NULL;
		if (i < 17)
			data->catterpilar[i].img = NULL;
		if (i < 6)
			data->wall_cat[i].img = NULL;
		if (i < 6)
			data->dialog_cat[i].img = NULL;
		if (i < 15)
			data->dialog[i].img = NULL;
		i++;
	}
}

static void	setup_wall_null(t_data *data)
{
	data->north.img = NULL;
	data->south.img = NULL;
	data->west.img = NULL;
	data->east.img = NULL;
	data->floor.img = NULL;
	data->ceiling.img = NULL;
	data->mushroom.img = NULL;
	data->door.img = NULL;
	data->dialog_box.img = NULL;
	data->img.img = NULL;
}

void	make_data_null(t_data *data)
{
	setup_img_null(data);
	setup_wall_null(data);
	data->map = NULL;
	data->nb_side_parsed = 0;
	data->controls.w = false;
	data->controls.s = false;
	data->controls.a = false;
	data->controls.d = false;
	data->controls.left_arrow = false;
	data->controls.right_arrow = false;
	data->controls.door = true;
	data->in_win = false;
	data->controls.left_mouse = false;
	data->controls.right_mouse = false;
	data->time = 0;
	data->time_2_le_retour = 0;
	make_bonus_null(data);
}
