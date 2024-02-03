/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:42:26 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/03 10:03:57 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool	setup_bonus(t_data *data)
{
	data->dialog_stage = 0;
	if (!get_characters(data))	// bonus
		return (data_clear(data), false);
	return (true);
}
