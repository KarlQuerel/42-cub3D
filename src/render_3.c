/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:08:22 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/18 21:17:58 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_all(t_data *data)
{
	int	x;
	int	y;

	x = (int)data->player_pos[0] / MINIMAP_HEIGHT * MINIMAP_HEIGHT;
	y = (int)data->player_pos[1] / MINIMAP_WIDTH * MINIMAP_WIDTH;
	draw_minimap(data, x, y);
	draw_alice(data, IMG_HEIGHT - IMG_HEIGHT / 20 - 128, IMG_WIDTH / 20);
	if (data->dialog_stage != DIALOG_NOT_STARTED && \
		data->dialog_stage != DIALOG_FINISH)
	{
		draw_white_rabbit(data, IMG_HEIGHT - IMG_HEIGHT / 20 - 128, \
			IMG_WIDTH - IMG_WIDTH / 20 - 128);
		draw_dialog_box(data, IMG_HEIGHT - IMG_HEIGHT / 20 - 128, \
			IMG_WIDTH / 20 + 192);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
