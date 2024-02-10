/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:42:26 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 20:53:59 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool	build_lst_coll(t_data *data)
{
	t_coll	*new;
	int		x;
	int		y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'C' || data->map[x][y] == 'P')
			{
				new = coll_new((t_v2f){x + 0.5, y + 0.5}, \
					data->map[x][y] == 'P');
				if (!new)
					return (false);
				coll_add_back(&data->coll, new);
			}
			y++;
		}
		x++;
	}
	return (true);
}

bool	setup_bonus(t_data *data)
{
	data->dialog_stage = 0;
	if (!get_characters(data))
		return (data_clear(data), false);
	if (!build_lst_coll(data))
		return (data_clear(data), false);
	return (true);
}
