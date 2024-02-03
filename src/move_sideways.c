/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sideways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:10:41 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/24 10:11:10 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_left(t_data *data)
{
	t_v2f	new_dir;

	new_dir[0] = -data->camera_dir[1];
	new_dir[1] = data->camera_dir[0];
	if (data->map[(int)(data->player_pos[0] + new_dir[0] * \
	(float)MOVE_SPEED)][(int)data->player_pos[1]] != '1'
	&& data->map[(int)(data->player_pos[0] + new_dir[0] * \
	(float)MOVE_SPEED)][(int)data->player_pos[1]] != 'D')
		data->player_pos[0] += new_dir[0] * (float)MOVE_SPEED;
	if (data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] + \
	new_dir[1] * (float)MOVE_SPEED)] != '1'
	&& data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] + \
	new_dir[1] * (float)MOVE_SPEED)] != 'D')
		data->player_pos[1] += new_dir[1] * (float)MOVE_SPEED;
}

static void	move_right(t_data *data)
{
	t_v2f	new_dir;

	new_dir[0] = data->camera_dir[1];
	new_dir[1] = -data->camera_dir[0];
	if (data->map[(int)(data->player_pos[0] + new_dir[0] * \
	(float)MOVE_SPEED)][(int)data->player_pos[1]] != '1'
	&& data->map[(int)(data->player_pos[0] + new_dir[0] * \
	(float)MOVE_SPEED)][(int)data->player_pos[1]] != 'D')
		data->player_pos[0] += new_dir[0] * (float)MOVE_SPEED;
	if (data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] + \
	new_dir[1] * (float)MOVE_SPEED)] != '1'
	&& data->map[(int)data->player_pos[0]][(int)(data->player_pos[1] + \
	new_dir[1] * (float)MOVE_SPEED)] != 'D')
		data->player_pos[1] += new_dir[1] * (float)MOVE_SPEED;
}

void	move_sideways(t_data *data)
{
	if (data->controls.a)
		move_left(data);
	if (data->controls.d)
		move_right(data);
}
