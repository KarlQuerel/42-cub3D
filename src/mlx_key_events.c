/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:06:52 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/24 10:28:14 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_handle_key_arrow(int key, t_data *data)
{
	if (key == UP || key == UP_W)
		data->controls.w = true;
	else if (key == DOWN || key == DOWN_S)
		data->controls.s = true;
	else if (key == LEFT)
		data->controls.left_arrow = true;
	else if (key == RIGHT)
		data->controls.right_arrow = true;
	else if (key == LEFT_A)
		data->controls.a = true;
	else if (key == RIGHT_D)
		data->controls.d = true;
	else if (key == O_DOOR)
		data->controls.door = !data->controls.door;
}

int	key_release(int key, t_data *data)
{
	if (key == UP || key == UP_W)
		data->controls.w = false;
	else if (key == DOWN || key == DOWN_S)
		data->controls.s = false;
	else if (key == LEFT)
		data->controls.left_arrow = false;
	else if (key == RIGHT)
		data->controls.right_arrow = false;
	else if (key == LEFT_A)
		data->controls.a = false;
	else if (key == RIGHT_D)
		data->controls.d = false;
	return (0);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		return (exit(data_clear(data)), 0);
	ft_handle_key_arrow(keycode, data);
	return (0);
}
