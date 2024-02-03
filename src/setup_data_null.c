/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:47:41 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/03 10:08:52 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	make_bonus_null(t_data *data)
{
	data->drogue = false;
	data->drogue_timer = 0;
	data->display_catterpilar = false;
}

static void	setup_img_null(t_data *data)
{
	int	i;

	i = 0;
	while (i < 18)
	{
		if (i < 8)
			data->dialog[i].img = NULL;
		if (i < 10)
			data->white_rabbit[i].img = NULL;
		if (i < 17) // 18 ?
			data->catterpilar[i].img = NULL;
		data->alice[i].img = NULL;
		i++;
	}
	data->north.img = NULL;
	data->east.img = NULL;
	data->south.img = NULL;
	data->west.img = NULL;
	data->door.img = NULL;
	data->dialog_box.img = NULL;
}

void	make_data_null(t_data *data)
{
	setup_img_null(data);
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
