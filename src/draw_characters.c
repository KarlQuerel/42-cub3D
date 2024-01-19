/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:15:00 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/19 17:48:04 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_put_img_to_img_2(t_data *data, t_img_info *src, int x, int y)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			pixel = ((int *)src->addr)[i * 128 + 127 - j];
			if (pixel > 0)
				ft_my_put_pixel(data, x + i, y + j, pixel);
			j++;
		}
		i++;
	}
}

void	my_put_img_to_img(t_data *data, t_img_info *src, int x, int y)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			pixel = ((int *)src->addr)[i * 128 + j];
			if (pixel > 0)
				ft_my_put_pixel(data, x + i, y + j, pixel);
			j++;
		}
		i++;
	}
}

void	draw_alice(t_data *data, int x, int y)
{
	static int	anim = 0;

	if (ALICE_1 <= data->dialog_stage && data->dialog_stage <= ALICE_4)
	{
		my_put_img_to_img_2(data, &data->alice[anim / 75], x, y);
		anim++;
		if (anim / 75 > 16)
			anim = 0;
	}
	else
		my_put_img_to_img_2(data, &data->alice[0], x, y);
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
