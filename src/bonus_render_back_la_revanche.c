/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_render_back_la_revanche.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:15:42 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 16:52:42 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

// une fonction qui calcule le rayon	-> pas besoin, valeur qui ne bouge pas
// une fonction qui calcule le sidecalc -> pas besoin, valeur qui ne bouge pas

t_v2f	reverse_ray(t_v2f ray)
{
	ray[0] *= -1;
	ray[1] *= -1;
	if (ray[0] < 0)
	{
		data->step[0] = -1;
		data->side_dist[0] = (data->player_pos[0] - data->map_x) \
		* delta_dist[0];
	}
	else
	{
		data->step[0] = 1;
		data->side_dist[0] = (data->map_x + 1.0 - data->player_pos[0]) \
		* delta_dist[0];
	}
	if (ray[1] < 0)
	{
		data->step[1] = -1;
		data->side_dist[1] = (data->player_pos[1] - data->map_y) * \
		delta_dist[1];
	}
	else
	{
		data->step[1] = 1;
		data->side_dist[1] = (data->map_y + 1.0 - data->player_pos[1]) * \
		delta_dist[1];
	}
}

// une fonction qui calcule la distance
float	collectible_dist(t_data *data, t_v2f ray)
{
	t_v2f	dist;

	dist[0] = data->map_x + (ray[0] > 0) * 0.5 - (ray[0] < 0) * 0.5
}

// une fonction qui calcule l'endroit dans l'image ou on va chercher le pixel
void	find_right_pixel(t_data *data)
{	

}

// une fonction qui affiche une tranche de collectible
void	draw_slice_coll(t_data *data, char *addr, int x)
{


}

// une fonction qui reviens en arriere -> dans une boucle
bool	back_to_player(t_data *data, int i, t_v2f delta_dist)
{
	if (data->side_dist[0] < data->side_dist[1])
	{
		data->side_dist[0] += delta_dist[0];
		data->map_x += data->step[0];
		data->side = 2 - (data->map_x > data->player_pos[0]);
		if (data->map[data->map_x][data->map_y] == 'D')
			return (data->side = DOOR, true);
	}
	else
	{
		data->side_dist[1] += delta_dist[1];
		data->map_y += data->step[1];
		data->side = EAST - (data->map_y > data->player_pos[1]);
		if (data->map[data->map_x][data->map_y] == 'D')
			return (data->side = DOOR_2, true);
	}
	if (data->map[data->map_x][data->map_y] == 'C' || data->map[data->map_x][data->map_y] == 'P')
	{
		// draw slice of a collectible (use i)
	}
	if (data->map_x == (int)data->player_pos[0] && data->map_y == (int)data->player_pos[1])
		return (true);
	return (false);
}



// une fonction qui determine que


// ca va chier
void	last_cube(t_data *data, t_v2f ray, int i)
{
	t_v2f	ray_reversed;

	ray_reversed = reverse_ray(ray);
	while (!back_to_player(data, i, ray_reversed))
		;
}
