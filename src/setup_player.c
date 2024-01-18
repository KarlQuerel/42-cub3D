/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:11:12 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/18 13:44:37 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_right_arrow(t_data *data, t_v2f old_dir, float angle)
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

void	good_dir(t_data *data, int x, int y)
{
	float	angle;

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
	{
		angle = 1.57;
	}
	move_right_arrow(data, data->camera_dir, angle);
}

bool	check_size_wall(t_data *data)
{
	int	size;

	size = ft_strlen(data->north.addr);
	if (size / 4 / TEX_WIDTH < TEX_HEIGHT)
		return (false);//msg
	size = ft_strlen(data->south.addr);
	if (size / 4 / TEX_WIDTH < TEX_HEIGHT)
		return (false);//msg
	size = ft_strlen(data->west.addr);
	if (size / 4 / TEX_WIDTH < TEX_HEIGHT)
		return (false);//msg
	size = ft_strlen(data->east.addr);
	if (size / 4 / TEX_WIDTH < TEX_HEIGHT)
		return (false);//msg
	return (true);
}

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
			if (data->map[x][y] == 'N' || data->map[x][y] == 'S' \
				|| data->map[x][y] == 'W' || data->map[x][y] == 'E')
			{
				data->player_pos[0] = x + 0.5f;
				data->player_pos[1] = y + 0.5f;
				data->plane[0] = 0.0f;
				data->plane[1] = 0.57f;
				good_dir(data, x, y);
				return (true);
			}
			y++;
		}
		x++;
	}
	return (false);
}
