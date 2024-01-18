/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:06:48 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/18 14:35:23 by pcheron          ###   ########.fr       */
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

void	unleek_gnl(int fd)
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

bool	is_cub_file(char *line)
{
	int	i;

	i = 0;
	while (!is_a_white_space(line[i]) && line[i])
		i++;
	return (!(i < 5 || ft_strncmp(line + i - 4, ".cub", 3)));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	return (err("You must specify a map name, and only a map name."), 1);
	if (!is_cub_file(argv[1]))
		return (err("Your map have to be a cub file."), 1);
	if (!setup_mlx(&data))
		return (1);
	make_data_null(&data);
	data.nb_side_parsed = 0;
	if (!setup_world(&data, argv[1]))
		return (data_clear_le_2(&data), 1);
	if (!checkup_map(data.map))
		return (data_clear_le_2(&data), 1);
	if (!find_player(&data))
		return (data_clear_le_2(&data), 1);
	if (!get_characters(&data))
		return (1);	//
	init_values(&data);
	
	render(&data);
	mlx_hook(data.win, EXIT, 0, data_clear, &data);
	mlx_hook(data.win, 02, KeyPressMask, key_event, &data);
	mlx_hook(data.win, 03, 1L << 1, key_release, &data);
	mlx_hook(data.win, 7, 1L << 4, enter_win, &data);
	mlx_hook(data.win, 8, 1L << 5, leave_win, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_handler, &data);
	mlx_loop_hook(data.mlx, update_display, &data);
	mlx_loop(data.mlx);
	return (0);
}
