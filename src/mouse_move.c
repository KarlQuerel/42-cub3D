/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 06:41:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/17 09:55:23 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate(t_v2f *v2f, float angle)
{
	t_v2f	new_v2f;

	new_v2f[0] = (*v2f)[0] * cos(angle) - (*v2f)[1] * sin(angle);
	new_v2f[1] = (*v2f)[0] * sin(angle) - (*v2f)[1] * cos(angle);
	*v2f = new_v2f;
}

void	move_mouse(t_data *data)
{
	if (data->controls.right_mouse)
	{
		rotate(&data->camera_dir, (-ROT_SPEED));
		rotate(&data->plane, (-ROT_SPEED));
	}
	if (data->controls.left_mouse)
	{
		rotate(&data->camera_dir, (ROT_SPEED));
		rotate(&data->plane, (ROT_SPEED));
	}
}
