/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checkup_map_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:32:54 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 18:16:27 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	new_camera(t_data *data, t_v2f old_dir, float angle)
{
	t_v2f	old_plane;

	data->camera_dir[0] = data->camera_dir[0] * cos(-angle) \
	- data->camera_dir[1] * sin(-angle);
	data->camera_dir[1] = old_dir[0] * sin(-angle) \
	+ data->camera_dir[1] * cos(-angle);
	old_plane[0] = data->plane[0];
	data->plane[0] = data->plane[0] * cos(-angle) \
	- data->plane[1] * sin(-angle);
	data->plane[1] = old_plane[0] * sin(-angle) \
	+ data->plane[1] * cos(-angle);
}

void	setup_dir(t_data *data, int x, int y)
{
	float	angle;
	t_v2f	old_dir;

	(void)x;
	(void)y;
	data->camera_dir[0] = -1.0;
	data->camera_dir[1] = 0.0;
	angle = 0.0;
	if (data->map[x][y] == 'S')
		angle = PI;
	else if (data->map[x][y] == 'W')
		angle = PI + 1.57;
	else if (data->map[x][y] == 'E')
		angle = 1.57;
	old_dir = data->camera_dir;
	new_camera(data, old_dir, angle);
}
