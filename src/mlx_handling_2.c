/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:59:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/18 19:50:07 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_right_arrow(t_data *data, t_v2f old_dir)
{
	t_v2f	old_plane;

	data->camera_dir[0] = data->camera_dir[0] * cos(-ROT_SPEED) \
	- data->camera_dir[1] * sin(-ROT_SPEED);
	data->camera_dir[1] = old_dir[0] * sin(-ROT_SPEED) \
	+ data->camera_dir[1] * cos(-ROT_SPEED);
	old_plane[0] = data->plane[0];
	data->plane[0] = data->plane[0] * cos(-ROT_SPEED) \
	- data->plane[1] * sin(-ROT_SPEED);
	data->plane[1] = old_plane[0] * sin(-ROT_SPEED) \
	+ data->plane[1] * cos(-ROT_SPEED);
}

static void	move_left_arrow(t_data *data, t_v2f old_dir)
{
	t_v2f	old_plane;

	data->camera_dir[0] = data->camera_dir[0] \
	* cos(ROT_SPEED) - data->camera_dir[1] * sin(ROT_SPEED);
	data->camera_dir[1] = old_dir[0] * sin(ROT_SPEED) \
	+ data->camera_dir[1] * cos(ROT_SPEED);
	old_plane[0] = data->plane[0];
	data->plane[0] = data->plane[0] * cos(ROT_SPEED) \
	- data->plane[1] * sin(ROT_SPEED);
	data->plane[1] = old_plane[0] * sin(ROT_SPEED) \
	+ data->plane[1] * cos(ROT_SPEED);
}

void	rotate_camera(t_data *data)
{
	t_v2f	old_dir;

	old_dir = data->camera_dir;
	if (data->controls.right_arrow)
		move_right_arrow(data, old_dir);
	else if (data->controls.left_arrow)
	{
		move_left_arrow(data, old_dir);
	}
}

void	move_w(t_data *data)
{
	if (data->map[(int)(data->player_pos[0] + data->camera_dir[0] \
	* (float)MOVE_SPEED)][(int)data->player_pos[1]] != '1'
	&& data->map[(int)(data->player_pos[0] + data->camera_dir[0] \
	* (float)MOVE_SPEED)][(int)data->player_pos[1]] != 'D')
		data->player_pos[0] += data->camera_dir[0] * (float)MOVE_SPEED;
	if (data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] \
	+ data->camera_dir[1] * (float)MOVE_SPEED)] != '1'
	&& data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] \
	+ data->camera_dir[1] * (float)MOVE_SPEED)] != 'D')
		data->player_pos[1] += data->camera_dir[1] * (float)MOVE_SPEED;
}

void	move_longitudinal(t_data *data)
{
	if (data->controls.w)
		move_w(data);
	if (data->controls.s)
	{
		if (data->map[(int)(data->player_pos[0] - data->camera_dir[0] \
		* (float)MOVE_SPEED)][(int)data->player_pos[1]] != '1'
		&& data->map[(int)(data->player_pos[0] - data->camera_dir[0] \
		* (float)MOVE_SPEED)][(int)data->player_pos[1]] != 'D')
			data->player_pos[0] -= data->camera_dir[0] * (float)MOVE_SPEED;
		if (data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] \
		- data->camera_dir[1] * (float)MOVE_SPEED)] != '1'
		&& data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] \
		- data->camera_dir[1] * (float)MOVE_SPEED)] != 'D')
			data->player_pos[1] -= data->camera_dir[1] * (float)MOVE_SPEED;
	}
}
