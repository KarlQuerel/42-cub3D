/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fill_img_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:42:11 by kquerel           #+#    #+#             */
/*   Updated: 2024/02/08 15:23:01 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool	get_alice_dialog(t_data *data)
{
	static char	file[] = "img/XPM/Dialog/ALICE_x.xpm";
	int			i;

	i = 1;
	while (i < 8)
	{
		file[21] = '0' + i;
		if (!upload_img(data, &((data->dialog)[i - 1 + (i > 4) * 3]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	return (true);
}

bool	get_rabbit_dialog(t_data *data)
{
	static char	file[] = "img/XPM/Dialog/RABBIT_x.xpm";
	int			i;

	i = 1;
	while (i < 4)
	{
		file[22] = '0' + i;
		if (!upload_img(data, &((data->dialog)[i - 1]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	return (true);
}

bool	get_cat_dialog(t_data *data)
{
	static char	file[] = "img/XPM/Dialog/CAT_x.xpm";
	int			i;

	i = 1;
	while (i < 4)
	{
		file[19] = '0' + i;
		if (!upload_img(data, &((data->dialog)[i + 10]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	return (true);
}

bool	get_all_dialog(t_data *data)
{
	if (!get_alice_dialog(data) || !get_rabbit_dialog(data) \
		|| !get_cat_dialog(data))
		return (false);
	return (true);
}
