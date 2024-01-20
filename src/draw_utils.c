/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:18:46 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/20 11:30:30 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_my_put_pixel(t_data *data, int x, int y, int color)
{
	// int	*dst;

	// dst = (int *)data->img.addr + (x * IMG_WIDTH + y);
	// *(unsigned int *)dst[] = color;
	((int *)data->img.addr)[x * IMG_WIDTH + y] = color;
}
