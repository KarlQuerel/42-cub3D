/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:59:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/12 10:06:30 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_handle_key_arrow(int key, t_data *data)
{
	if (key == UP || key == UP_W)
		data->controls.w = true;
	else if (key == DOWN || key == DOWN_S)
		data->controls.s = true;
	if (key == RIGHT || key == RIGHT_D)
		data->controls.d = true;
	else if (key == LEFT || key == LEFT_A)
		data->controls.a = true;
}

void	move(t_data *data)
{
	move_longitudinal(data);
	move_sideways(data);
	render(data);
}

int	key_release(int key, t_data *data)
{
	if (key == UP || key == UP_W)
		data->controls.w = false;
	else if (key == DOWN || key == DOWN_S)
		data->controls.s = false;
	else if (key == LEFT || key == LEFT_A)
		data->controls.a = false;
	else if (key == RIGHT || key == RIGHT_D)
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

void	move_longitudinal(t_data *data)
{
	if (data->controls.w)
	{
		if (data->map[(int)(data->player_pos[0] + data->camera_dir[0] \
		* (float)MOVE_SPEED)][(int)data->player_pos[1]] != '1')
			data->player_pos[0] += data->camera_dir[0] * (float)MOVE_SPEED;
		if (data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] \
		+ data->camera_dir[1] * (float)MOVE_SPEED)] != '1')
			data->player_pos[1] += data->camera_dir[1] * (float)MOVE_SPEED;
	}
	else if (data->controls.s)
	{
		if (data->map[(int)(data->player_pos[0] - data->camera_dir[0] \
		* (float)MOVE_SPEED)][(int)data->player_pos[1]] != '1')
			data->player_pos[0] -= data->camera_dir[0] * (float)MOVE_SPEED;
		if (data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] \
		- data->camera_dir[1] * (float)MOVE_SPEED)] != '1')
			data->player_pos[1] -= data->camera_dir[1] * (float)MOVE_SPEED;
	}
}
