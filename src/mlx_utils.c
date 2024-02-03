/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:12:51 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/02 10:30:25 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	data_clear(t_data *data)
// {
// 	mlx_destroy_image(data->mlx, data->img.img);
// 	if (data->north.img)
// 		mlx_destroy_image(data->mlx, data->north.img);
// 	if (data->south.img)
// 		mlx_destroy_image(data->mlx, data->south.img);
// 	if (data->east.img)
// 		mlx_destroy_image(data->mlx, data->east.img);
// 	if (data->west.img)
// 		mlx_destroy_image(data->mlx, data->west.img);
// 	// clear_characters(data);
// 	// clear_text(data);
// 	mlx_destroy_window(data->mlx, data->win);
// 	mlx_destroy_display(data->mlx);
// 	free_strs(&data->map);
// 	free(data->mlx);
// 	return (0);
// }

void	ft_my_put_pixel(t_data *data, int x, int y, int color)
{
	((int *)data->img.addr)[x * (IMG_WIDTH * !data->drogue + IMG_HEIGHT * data->drogue) + y] = color;
	// (IMG_WIDTH * !data->drogue + IMG_HEIGHT * data->drogue)
	// ((int *)data->img.addr)[x * IMG_HEIGHT  + y + IMG_WIDTH * ((IMG_WIDTH - IMG_HEIGHT) / 2) ] = color;
}
