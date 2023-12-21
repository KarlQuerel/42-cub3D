/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:11:12 by pcheron           #+#    #+#             */
/*   Updated: 2023/12/21 17:38:06 by kquerel          ###   ########.fr       */
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
				data->camera_dir[0] = 0;
				data->camera_dir[1] = 1;
				data->plane[0] = 0.0f;
				data->plane[1] = 0.66f;
				return (true);
			}
			y++;
		}
		x++;
	}
	return (false);
}
