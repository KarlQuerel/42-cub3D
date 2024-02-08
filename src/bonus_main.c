/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:02:35 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/08 09:44:39 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static bool	is_cub_file(char *line)
{
	int	i;

	i = ft_strlen(line);
	return (!(i < 5 || ft_strncmp(line + i - 4, ".cub", 4)));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (err("You must specify a map path, and only a map path."), 1);
	if (!is_cub_file(argv[1]))
		return (err("Your map have to be a cub file."), 1);
	make_data_null(&data);
	if (!setup_mlx(&data))
		return (1);
	if (!fill_map_file(&data, argv[1]))
		return (1);
	if (!setup_game(&data))
		return (1);
	if (!setup_bonus(&data))
		return (1);
	render(&data);
	mlx_hook(data.win, EXIT, 0, quit_game, &data);
	mlx_hook(data.win, 02, KeyPressMask, key_event, &data);
	mlx_hook(data.win, 03, 1L << 1, key_release, &data);
	mlx_hook(data.win, 7, 1L << 4, enter_win, &data);
	mlx_hook(data.win, 8, 1L << 5, leave_win, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_handler, &data);
	mlx_loop_hook(data.mlx, update_display, &data);
	mlx_loop(data.mlx);
	return (0);
}
