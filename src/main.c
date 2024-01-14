/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:06:48 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/14 12:33:30 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	make_data_null(t_data *data)
{
	data->north.img = NULL;
	data->east.img = NULL;
	data->south.img = NULL;
	data->west.img = NULL;
	data->map = NULL;
}

void	unleekGnl(int fd)
{
	char	*line;

	while ("jusqu'ici tout va bien")
	{
		line = ft_get_next_line(fd);
		if (!line)
			return ;
		free(line);
	}
}

int	update_display(t_data *data)
{
	move(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_print_fd(2, "Error\nYou must specified a name map.\n"), 1);
	if (!setup_mlx(&data))
		return (1);
	make_data_null(&data);
	data.nb_side_parsed = 0;
	if (!setup_world(&data, argv[1]))
		return (data_clear(&data), 1);
	if (!checkup_map(data.map))
		return (data_clear(&data), 1);
	if (!find_player(&data))
		return (data_clear(&data), 1);
	init_values(&data);
	render(&data);
	mlx_hook(data.win, EXIT, 0, data_clear, &data);
	mlx_hook(data.win, 02, KeyPressMask, key_event, &data);
	mlx_hook(data.win, 03, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, update_display, (void *)&data);
	mlx_loop(data.mlx);
	return (0);
}
