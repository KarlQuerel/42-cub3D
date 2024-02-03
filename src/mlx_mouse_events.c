/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:30 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/26 09:17:42 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	enter_win(t_data *data)
{
	data->in_win = true;
	return (0);
}

int	leave_win(t_data *data)
{
	data->in_win = false;
	data->controls.left_mouse = false;
	data->controls.right_mouse = false;
	return (0);
}

int	mouse_handler(int x, int y, t_data *data)
{
	(void)y;
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
