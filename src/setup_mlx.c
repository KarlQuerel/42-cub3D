/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:10:52 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/19 18:25:25 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	restore_floor_player(t_data *data)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				data->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	opti(t_data *data)
{
	data->ceiling_color_2 = data->ceiling_color[0];
	data->ceiling_color_2 <<= 8;
	data->ceiling_color_2 += data->ceiling_color[1];
	data->ceiling_color_2 <<= 8;
	data->ceiling_color_2 += data->ceiling_color[2];
	data->floor_color_2 = data->floor_color[0];
	data->floor_color_2 <<= 8;
	data->floor_color_2 += data->floor_color[1];
	data->floor_color_2 <<= 8;
	data->floor_color_2 += data->floor_color[2];
}

void	init_values(t_data *data)
{
	data->controls.w = false;
	data->controls.s = false;
	data->controls.a = false;
	data->controls.d = false;
	data->controls.left_arrow = false;
	data->controls.right_arrow = false;
	data->controls.door = true;
	data->in_win = false;
	data->controls.left_mouse = false;
	data->controls.right_mouse = false;
	data->time = 0;
	data->still_run = true;
	restore_floor_player(data);
	ft_print_strs(data->map);
	data->time_2_le_retour = 0;
	data->dialog_stage = DIALOG_NOT_STARTED;
	setup_text(data);
	opti(data);
}

void	mini_mlx_clear(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

bool	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (err("Mlx: error on new ptr"), false);
	data->win = mlx_new_window(data->mlx, IMG_WIDTH, IMG_HEIGHT, "cub3D");
	if (!data->win)
		return (err("Mlx: error on new img"),
			mlx_destroy_image(data->mlx, data->img.img),
			mlx_destroy_display(data->mlx), free(data->mlx), false);
	data->img.img = mlx_new_image(data->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!data->img.img)
		return (err("Mlx: error on new img"),
			mlx_destroy_display(data->mlx), free(data->mlx), false);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.ll, &data->img.endian);
	if (!data->img.addr)
		return (err("Mlx: error on get addr"),
			mlx_destroy_image(data->mlx, data->img.img),
			mlx_destroy_display(data->mlx), free(data->mlx), false);
	data->img.bpp /= 8;
	return (true);
}
