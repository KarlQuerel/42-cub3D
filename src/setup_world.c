/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:58:53 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/18 09:04:54 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	fill_new_line(t_data *data, char **line)
{
	int				type;
	static bool		(*fill_functions[])() = {NULL, fill_north, fill_south,
		fill_west, fill_east, fill_ceiling, fill_floor};

	type = identify_line(*line);
	if (!type)
		return (false);
	if (NORTH <= type && type <= CEILING)
	{
		return (fill_functions[type](data, *line));
	}
	if (type == MAP)
	{
		return (fill_map(data, line));
	}
	return (true);
}

bool	setup_world(t_data *data, char *map)
{
	char	*line;

	data->fd = open(map, O_RDONLY);
	if (data->fd < 0)
		return (err("Map file: open error"), false);
	while (1)
	{
		line = ft_get_next_line(data->fd);
		if (!line)
			break ;
		if (line[0] != '#' && line[0] && !is_a_white_space(line[0]))
		{
			if (!fill_new_line(data, &line))
			{
				err("Map file: spurious line in file");
				free(line);
				return (unleek_gnl(data->fd), close(data->fd), false);
			}
		}
		free(line);
	}
	close(data->fd);
	if (data->nb_side_parsed != 7)
		return (err("Map file: incomplete file"), false);
	return (true);
}
