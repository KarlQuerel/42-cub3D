/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:21:57 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/05 20:21:04 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static bool	can_i_take_this(t_data *data, int x, int y)
{
	int		v;
	int		w;
	float	frac_v;
	float	frac_w;

	v = data->player_pos[0];
	w = data->player_pos[1];
	if (v == x && w == y)
	{
		frac_v = data->player_pos[0] - v;
		frac_w = data->player_pos[1] - w;
		if (frac_v > 0.25 && frac_v < 0.75 && frac_w > 0.25 && frac_w < 0.75)
			return (true);
	}
	return (false);
}

void	take_collectibles(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == COLLECTIBLE && \
			can_i_take_this(data, i, j))
			{
				printf("je prend la drogue\n");
				data->drogue = true;
				data->drogue_timer = 0;
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (data->drogue_timer++ > 4000)
	{
		data->drogue = false;
		data->drogue_timer = 0;
	}
}
