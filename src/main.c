/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:06:48 by pcheron           #+#    #+#             */
/*   Updated: 2023/12/21 17:52:39 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	if (!setup_mlx(&data))
		return (1);
	data.map = NULL;
	if (!setup_world(&data, argv[1]))
		return (1);
	if (!checkup_map(data.map))
		return (1);
	if (!find_player(&data))
		return (1);
	put_strs(data.map);
	data.camera_dir[0] = -1.0;
	data.camera_dir[1] = 0.0;
	render(&data);
	mlx_hook(data.win, EXIT, 0, data_clear, &data);
	mlx_hook(data.win, 02, KeyPressMask, key_event, &data);
	mlx_loop(data.mlx);
	return (0);
}
