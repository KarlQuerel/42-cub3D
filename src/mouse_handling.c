/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 06:32:48 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/16 07:12:06 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	enter_win(t_data *data)
{
	// if (data->end || data->start)
	// 	return (0);
	data->in_win = true;
	return (0);
}

int	leave_win(t_data *data)
{
	// if (data->end || data->start)
	// 	return (0);
	data->in_win = false;
	data->controls.left_mouse = false;
	data->controls.right_mouse = false;
	return (0);
}

int	mouse_handler(int x, int y, t_data *data)
{
	(void)y;
	// if (data->end || data->start)
	// 	return (0);
	if (data->in_win && (x <= IMG_WIDTH / 6 && x >= 0))
	{
		data->controls.left_arrow = true;
		data->controls.right_arrow = false;
	}
	if (data->in_win && (x <= IMG_WIDTH && x >= (IMG_WIDTH - IMG_WIDTH / 6)))
	{	
		data->controls.left_arrow = false;
		data->controls.right_arrow = true;
	}
	if (data->in_win && (x > IMG_WIDTH / 6 && x < (IMG_WIDTH - IMG_WIDTH / 6)))
	{	
		data->controls.left_arrow = false;
		data->controls.right_arrow = false;
	}
	return (0);
}
