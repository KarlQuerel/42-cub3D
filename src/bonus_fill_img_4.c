/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fill_img_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:39:47 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 11:41:58 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool	get_mushroom(t_data *data)
{
	if (!upload_img(data, &data->mushroom, "./img/XPM/mushroom.xpm"))
		return (err(strerror(errno)), false);
	return (true);
}
