/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:29:45 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/06 17:51:55 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_minimap(t_data *data)
{
	// int	minimap_x = ;
	// int	minimap_y = ;
	// int	minimap_ width = ;
	// int	minimap_height = ;

	mlx_set_font(data->mlx, data->win, "10x20");
	mlx_string_put(data->mlx, data->win, 10, 20, 0x00BFFF, "LA JUNGLE");
	//mlx_pixel_put(data->mlx, data->win, 50, 50, 0xbad129);
	
}

void	draw_ray(t_data *data)
{
	data->camera_dir[0] = 10;
}
