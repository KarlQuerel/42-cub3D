/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:04:19 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/27 17:15:36 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	draw_msg(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 58)
	{
		j = 0;
		while (j < 400)
		{
			pixel = ((int *)data->dialog[data->dialog_stage].addr)[i * 400 + j];
			if (pixel > 0)
				ft_my_put_pixel(data, x + i, y + j, pixel);
			j++;
		}
		i++;
	}
}

void	draw_catterpilar(t_data *data, int x, int end, int i)
{
	int	color;
	int	tex_y;

	while (i <= end && i < IMG_HEIGHT)
	{
		tex_y = (int)data->tex_pos_tmp & (128 - 1);
		data->tex_pos_tmp += data->step_all;
		color = ((int *)data->catterpilar[data->time / 100].addr) \
			[tex_y * 128 + data->tex_x];
		if (color > 0)
			ft_my_put_pixel(data, i, x, color);
		(i)++;
	}
}

void	draw_alice(t_data *data, int x, int y)
{
	static int	anim = 0;

	if (ALICE_1 <= data->dialog_stage && data->dialog_stage <= ALICE_4)
	{
		my_put_img_to_img_reverse(data, &data->alice[anim / 75], x, y);
		anim++;
		if (anim / 75 > 16)
			anim = 0;
	}
	else
		my_put_img_to_img_reverse(data, &data->alice[0], x, y);
}

void	draw_white_rabbit(t_data *data, int x, int y)
{
	static int	anim = 0;

	if (WHITE_RABBIT_1 <= data->dialog_stage && \
		data->dialog_stage <= WHITE_RABBIT_3)
	{
		my_put_img_to_img(data, &data->white_rabbit[anim / 75], \
			x, y);
		anim++;
		if (anim / 75 > 9)
			anim = 0;
	}
	else if (ALICE_2 <= data->dialog_stage && data->dialog_stage <= ALICE_3)
		my_put_img_to_img(data, &data->white_rabbit[0], x, y);
}
