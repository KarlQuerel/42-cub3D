/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:44:49 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/20 12:15:47 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_v2f	get_ray(t_data *data, int x)
{
	t_v2f	ray;
	float	cam;

	cam = 2.0f * (float)x / (float)IMG_WIDTH - 1;
	ray[0] = data->camera_dir[0] + data->plane[0] * cam;
	ray[1] = data->camera_dir[1] + data->plane[1] * cam;
	return (ray);
}

void	wall_calc(t_data *data, t_v2f ray, float perp_wall_dist)
{
	int		line_height;
	float	wall_x;

	line_height = (int)(IMG_HEIGHT / perp_wall_dist);
	data->draw_start = -line_height / 2 + IMG_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_start >= IMG_HEIGHT)
		data->draw_start = IMG_HEIGHT - 1;
	data->draw_end = line_height / 2 + IMG_HEIGHT / 2;
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

static t_v2f	delta_dist_calc(t_data *data, t_v2f *ray)
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
	return (delta_dist);
}

static void	update_time(t_data *data)
{
	if (data->dialog_stage != DIALOG_FINISH)
		data->time_2_le_retour++;
	if (data->time_2_le_retour > 16000)
		data->dialog_stage = DIALOG_FINISH;
	else if (data->time_2_le_retour > 13500)
		data->dialog_stage = ALICE_4;
	else if (data->time_2_le_retour > 11000)
		data->dialog_stage = WHITE_RABBIT_3;
	else if (data->time_2_le_retour > 8500)
		data->dialog_stage = ALICE_3;
	else if (data->time_2_le_retour > 12500)
		data->dialog_stage = WHITE_RABBIT_2;
	else if (data->time_2_le_retour > 6000)
		data->dialog_stage = ALICE_2;
	else if (data->time_2_le_retour > 3500)
		data->dialog_stage = WHITE_RABBIT_1;
	else if (data->time_2_le_retour > 1000)
		data->dialog_stage = ALICE_1;
}

void	render(t_data *data)
{
	t_v2f	ray;
	int		i;

	i = 0;
	data->time++;
	if (data->time / 100 > 16)
		data->time = 0;
	close_doors(data);
	if (data->controls.door)
		open_doors(data);
	update_time(data);
	while (i < IMG_WIDTH)
	{
		ray = get_ray(data, i);
		next_cube(data, ray, i, delta_dist_calc(data, &ray));
		i++;
	}
	draw_all(data);
}
