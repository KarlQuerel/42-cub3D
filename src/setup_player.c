/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:11:12 by pcheron           #+#    #+#             */
/*   Updated: 2023/12/11 12:42:28 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	find_player(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'N')
			{
				data->player_pos[0] = x + 0.5f;
				data->player_pos[1] = y + 0.5f;
				data->camera_dir[0] = 0; // a changer en fonction
				data->camera_dir[1] = 1; // de N S W E
				data->plane[0] = 0.0f;
				data->plane[1] = 0.66f;
				data->time = 0;
				data->old_time = 0;
				return (true);
			}
			y++;
		}
		x++;
	}
	return (false);
}
