/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fill_img_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:42:11 by kquerel           #+#    #+#             */
/*   Updated: 2024/02/09 11:16:02 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool	get_alice_dialog(t_data *data)
{
	static char	file[] = "img/XPM/Dialog/ALICE_x.xpm";
	int			i;

	i = 1;
	while (i < 5)
	{
		file[21] = '0' + i;
		if (!upload_img(data, &((data->dialog)[i]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		file[21] = '0' + i + 5;
		if (!upload_img(data, &((data->dialog)[i + 9]), file))
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
		if (!upload_img(data, &((data->dialog)[i + 4]), file))
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
		if (!upload_img(data, &((data->dialog)[i + 11]), file))
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
