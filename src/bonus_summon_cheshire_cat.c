/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_summon_cheshire_cat.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:48:12 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/03 09:24:15 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	cheshire_cat_disapear(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
				data->map[x][y] = '0';
			y++;
		}
		x++;
	}
}

void	summon_cheshire_cat(t_data *data, int i)
{
	int	x;
	int	y;
	int	j;

	cheshire_cat_disapear(data);
	j = i;
	while (j)
	{
		x = (int)data->player_pos[0] - j;
		y = (int)data->player_pos[1] - j;
		while (x && x < (int)data->player_pos[0] + j && data->map[x])
		{
			while (y && y < (int)data->player_pos[1] + j && data->map[x][y])
			{
				if (data->map[x][y] == '0')
				{
					data->map[x][y] = 'P';
					return ;
				}
				y++;
			}
			x++;
		}
		j--;
	}
}
