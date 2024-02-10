/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:07:50 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 20:01:14 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate(t_data *data, float angle, t_v2f old_dir)
{
	t_v2f	old_plane;

	data->camera_dir[0] = data->camera_dir[0] \
	* cos(angle) - data->camera_dir[1] * sin(angle);
	data->camera_dir[1] = old_dir[0] * sin(angle) \
	+ data->camera_dir[1] * cos(angle);
	old_plane[0] = data->plane[0];
	data->plane[0] = data->plane[0] * cos(angle) \
	- data->plane[1] * sin(angle);
	data->plane[1] = old_plane[0] * sin(angle) \
	+ data->plane[1] * cos(angle);
}

static void	rotate_camera(t_data *data)
{
	t_v2f	old_dir;

	old_dir = data->camera_dir;
	if (data->controls.right_mouse || data->controls.right_arrow)
		rotate(data, (-ROT_SPEED), old_dir);
	if (data->controls.left_mouse || data->controls.left_arrow)
		rotate(data, (ROT_SPEED), old_dir);
}

int	update_display(t_data *data)
{
	move_longitudinal(data);
	move_sideways(data);
	rotate_camera(data);
	render(data);
	return (0);
}
