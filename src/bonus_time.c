/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:14:27 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 18:40:09 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

// void	debug_time_state(int state)
// {
// 	printf("Je passe a : ");
// 	if (state == DIALOG_FINISH_2)
// 		printf("DIALOG_FINISH_2");
// 	if (state == DIALOG_FINISH_1)
// 		printf("DIALOG_FINISH_1");
// 	if (state == ALICE_1)
// 		printf("ALICE_1");
// 	if (state == ALICE_2)
// 		printf("ALICE_2");
// 	if (state == ALICE_3)
// 		printf("ALICE_3");
// 	if (state == ALICE_4)
// 		printf("ALICE_4");
// 	if (state == ALICE_5)
// 		printf("ALICE_5");
// 	if (state == ALICE_6)
// 		printf("ALICE_6");
// 	if (state == ALICE_7)
// 		printf("ALICE_7");
// 	if (state == WHITE_RABBIT_1)
// 		printf("WHITE_RABBIT_1");
// 	if (state == WHITE_RABBIT_2)
// 		printf("WHITE_RABBIT_2");
// 	if (state == WHITE_RABBIT_3)
// 		printf("WHITE_RABBIT_3");
// 	if (state == CHESHIRE_CAT_1)
// 		printf("CHESHIRE_CAT_1");
// 	if (state == CHESHIRE_CAT_2)
// 		printf("CHESHIRE_CAT_2");
// 	if (state == CHESHIRE_CAT_3)
// 		printf("CHESHIRE_CAT_3");
// 	printf("\n");
// }

void	update_time_rabbit(t_data *data)
{
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

void	cat_1(t_data *data)
{
	if (data->dialog_stage != CHESHIRE_CAT_3)
		summon_cheshire_cat(data, 1);
	data->dialog_stage = CHESHIRE_CAT_3;
}

void	cat_2(t_data *data)
{
	if (data->dialog_stage != CHESHIRE_CAT_2)
		summon_cheshire_cat(data, 3);
	data->dialog_stage = CHESHIRE_CAT_2;
}

void	cat_3(t_data *data)
{
	if (data->dialog_stage != CHESHIRE_CAT_1)
		summon_cheshire_cat(data, 5);
	data->dialog_stage = CHESHIRE_CAT_1;
}

void	update_time(t_data *data)
{
	if (data->dialog_stage < DIALOG_FINISH_2)
		data->time_2_le_retour++;
	if (data->time_2_le_retour > 36000)
	{
		if (data->dialog_stage != DIALOG_FINISH_2)
			cheshire_cat_disapear(data);
		data->dialog_stage = DIALOG_FINISH_2;
	}
	else if (data->time_2_le_retour > 33500)
		data->dialog_stage = ALICE_7;
	else if (data->time_2_le_retour > 31000)
		cat_1(data);
	else if (data->time_2_le_retour > 28500)
		data->dialog_stage = ALICE_6;
	else if (data->time_2_le_retour > 26000)
		cat_2(data);
	else if (data->time_2_le_retour > 23500)
		data->dialog_stage = ALICE_5;
	else if (data->time_2_le_retour > 21000)
		cat_3(data);
	else
		update_time_rabbit(data);
}

// else
// 	return ;
// debug_time_state(data->dialog_stage);
