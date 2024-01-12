/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:58:53 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/12 12:17:35 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	fill_new_line(t_data *data, char **line, int fd)
{
	int				type;
	static bool		(*fill_functions[])() = {NULL, fill_north, fill_east,
		fill_west, fill_south, fill_ceiling, fill_floor};

	type = identify_line(*line);
	if (!type)
		return (write(2, "spurious line in file\n", 22), false);
	if (NORTH <= type && type <= CEILING)
	{
		printf("je vais par ici\n");
		return (fill_functions[type](data, *line));
	}
	if (type == MAP)
	{
		printf("je vais par ici\n");
		return (fill_map(data, line, fd));
	}
	return (true);
}

bool	setup_world(t_data *data, char *map)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (write(2, "cub3D : open error\n", 19), false);
	while ("jusqu'ici tout va bien")
	{
		line = ft_get_next_line(fd);
		if (!line)
		{
			write(1, "fin de lecture\n", 15);
			break ;
		}
		if (line[0] != '#' && line[0] && !is_a_white_space(line[0]))
		{
			if (!fill_new_line(data, &line, fd))
				return (free(line), false);
		}
		free(line);
	}
	close(fd);
	if (data->nb_side_parsed != 7)
		return (write(2, "pas suffisament de trucs\n", 25), false);
	return (true);
}
