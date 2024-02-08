/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:47:32 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/08 09:44:24 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	err(char *s)
{
	ft_print_fd(2, "Error\n%s\n", s);
}

void	free_strs(char ***strs)
{
	int	i;

	i = 0;
	if (strs && *strs)
	{
		while ((*strs)[i])
		{
			free((*strs)[i]);
			i++;
		}
		free(*strs);
		*strs = NULL;
	}
}

int	data_clear(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	if (data->north.img)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->east.img)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.img)
		mlx_destroy_image(data->mlx, data->west.img);
	// clear_characters(data);
	// clear_text(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_strs(&data->map);
	free(data->mlx);
	return (0);
}

int quit_game(t_data *data)
{
	data_clear(data);
	exit(0);
	return (0);
}
