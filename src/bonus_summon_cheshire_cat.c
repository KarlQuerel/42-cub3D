/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_summon_cheshire_cat.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:48:12 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 20:53:20 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	cheshire_cat_disapear(t_data *data)
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
			{
				data->map[x][y] = '0';
				coll_delete(&data->coll, (t_v2f){x + 0.5, y + 0.5});
			}
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
	while (--j)
	{
		x = (int)data->player_pos[0] - j;
		y = (int)data->player_pos[1] - j;
		while (++x && x < (int)data->player_pos[0] + j && data->map[x])
		{
			while (y && y < (int)data->player_pos[1] + j && data->map[x][y])
			{
				if (data->map[x][y] == '0')
				{
					data->map[x][y] = 'P';
					coll_add_back(&data->coll, \
					coll_new((t_v2f){x + 0.5, y + 0.5}, true));
					return ;
				}
				y++;
			}
		}
	}
}
