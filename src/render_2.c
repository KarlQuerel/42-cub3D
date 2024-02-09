/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:26:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 15:10:34 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	abs_value(float x)
{
	return ((x < 0) * -x + x * (x >= 0));
}

void	wall_calc(t_data *data, t_v2f ray, float perp_wall_dist)
{
	int		line_height;
	float	wall_x;

	line_height = (int)(IMG_HEIGHT / perp_wall_dist);
	data->draw_start = (IMG_HEIGHT - line_height) / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_start >= IMG_HEIGHT)
		data->draw_start = IMG_HEIGHT - 1;
	data->draw_end = (line_height + IMG_HEIGHT) / 2;
	if (data->draw_end >= IMG_HEIGHT)
		data->draw_end = IMG_HEIGHT - 1;
	if (!(data->side / 3))
		wall_x = data->player_pos[1] + perp_wall_dist * ray[1];
	else
		wall_x = data->player_pos[0] + perp_wall_dist * ray[0];
	wall_x -= (int)wall_x;
	data->tex_x = (int)(wall_x * (float)TEX_WIDTH);
	if (!(data->side / 3) && ray[0] > 0)
		data->tex_x = TEX_WIDTH - data->tex_x - 1;
	if (data->side / 3 && ray[1] < 0)
		data->tex_x = TEX_WIDTH - data->tex_x - 1;
	data->step_all = 1.0 * TEX_HEIGHT / line_height;
	data->tex_pos = (data->draw_start - IMG_HEIGHT / 2 + line_height / 2) \
	* data->step_all;
}

t_v2f	delta_dist_calc(t_data *data, t_v2f *ray)
{
	t_v2f	delta_dist;

	data->map_x = (int)data->player_pos[0];
	data->map_y = (int)data->player_pos[1];
	if (!(*ray)[0])
		delta_dist[0] = 1e30;
	else
		delta_dist[0] = abs_value(1 / (*ray)[0]);
	if (!(*ray)[1])
		delta_dist[1] = 1e30;
	else
		delta_dist[1] = abs_value(1 / (*ray)[1]);
	// printf("delta_dist<%f/%f>\n",delta_dist[0], delta_dist[1]);
	// printf("delta_dist<%f/%f>\n",delta_dist[0], delta_dist[1]);
	return (delta_dist);
}
