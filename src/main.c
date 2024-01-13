/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:06:48 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/13 17:22:11 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	update_display(t_data *data)
{
	move(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	if (!setup_mlx(&data))
		return (1);
	data.map = NULL;
	data.nb_side_parsed = 0;
	if (!setup_world(&data, argv[1]))
		return (1);
	if (!checkup_map(data.map))
		return (1);
	if (!find_player(&data))
		return (1);
	init_values(&data);
	render(&data);
	mlx_hook(data.win, EXIT, 0, data_clear, &data);
	mlx_hook(data.win, 02, KeyPressMask, key_event, &data);
	mlx_hook(data.win, 03, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, update_display, (void *)&data);
	mlx_loop(data.mlx);
	return (0);
}
