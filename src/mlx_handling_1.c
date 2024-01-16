/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:59:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/16 06:40:52 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_handle_key_arrow(int key, t_data *data)
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
}

void	move(t_data *data)
{
	move_longitudinal(data);
	move_sideways(data);
	move_mouse(data);
	rotate_camera(data);
	render(data);
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
		return (data_clear(data), 0);
	ft_handle_key_arrow(keycode, data);
	return (0);
}
