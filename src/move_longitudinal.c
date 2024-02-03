/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_longitudinal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:11:38 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/24 10:14:39 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_straight_ahead(t_data *data)
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

static void	move_behind(t_data *data)
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

void	move_longitudinal(t_data *data)
{
	if (data->controls.w)
		move_straight_ahead(data);
	if (data->controls.s)
		move_behind(data);
}
