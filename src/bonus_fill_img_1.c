/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fill_img_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:26:47 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/05 20:14:11 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool	get_dialog_box(t_data *data)
{
	if (!upload_img(data, &data->dialog_box, "./img/XPM/Dialog_box.xpm\0"))
		return (err(strerror(errno)), false);
	return (true);
}

bool	get_door(t_data *data)
{
	if (!upload_img(data, &data->door, "./img/XPM/Walls/DOOR.xpm\0"))
		return (err(strerror(errno)), false);
	return (true);
}

bool	get_catterpilar(t_data *data)
{
	static char	file[] = "img/Catterpillar/xx.xpm\0";
	int			i;

	i = 1;
	while (i - 1 < 18)
	{
		file[17] = i / 10 + '0';
		file[18] = i % 10 + '0';
		if (!upload_img(data, &((data->catterpilar)[i - 1]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	return (true);
}

bool	get_white_rabbit(t_data *data)
{
	static char	file[] = "img/White_rabbit/xx.xpm\0";
	int			i;

	i = 1;
	while (i - 1 < 10)
	{
		file[17] = i / 10 + '0';
		file[18] = i % 10 + '0';
		if (!upload_img(data, &((data->white_rabbit)[i - 1]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	return (true);
}

bool	get_characters(t_data *data)
{
	if (!get_alice(data) || !get_catterpilar(data) || \
			!get_white_rabbit(data) || \
			!get_door(data) || \
			!get_dialog_box(data) || \
			!get_text(data) || !get_wall_cat(data) || \
			!get_dialog_cat(data))
		return (false);
	return (true);
}
