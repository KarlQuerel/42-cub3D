/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:59:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/12 12:05:25 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_right(t_data *data, t_v2f old_dir)
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

static void	move_left(t_data *data, t_v2f old_dir)
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

void	move_sideways(t_data *data)
{
	t_v2f	old_dir;

	old_dir = data->camera_dir;
	if (data->controls.d)
		move_right(data, old_dir);
	else if (data->controls.a)
	{
		move_left(data, old_dir);
	}
}
