/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:14:27 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/03 10:24:55 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	update_time(t_data *data)
{
	if (data->dialog_stage != DIALOG_FINISH_1)
		data->time_2_le_retour++;
	if (data->time_2_le_retour > 18500)
		data->dialog_stage = DIALOG_FINISH_1;
	else if (data->time_2_le_retour > 16000)
		data->dialog_stage = ALICE_4;
	else if (data->time_2_le_retour > 13500)
		data->dialog_stage = WHITE_RABBIT_3;
	else if (data->time_2_le_retour > 11000)
		data->dialog_stage = ALICE_3;
	else if (data->time_2_le_retour > 8500)
		data->dialog_stage = WHITE_RABBIT_2;
	else if (data->time_2_le_retour > 6000)
		data->dialog_stage = ALICE_2;
	else if (data->time_2_le_retour > 3500)
		data->dialog_stage = WHITE_RABBIT_1;
	else if (data->time_2_le_retour > 1000)
		data->dialog_stage = ALICE_1;
}
