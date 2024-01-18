/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:18:46 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/18 18:19:20 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (x * IMG_WIDTH * 4 + y * 4);
	*(unsigned int *)dst = color;
}
