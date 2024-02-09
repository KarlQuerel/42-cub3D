/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_file_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:03:43 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 16:41:14 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	identify_line(char *str)
{
	if (!ft_strncmp(str, "NO", 2) && is_a_white_space(str[2]))
		return (NORTH);
	if (!ft_strncmp(str, "SO", 2) && is_a_white_space(str[2]))
		return (SOUTH);
	if (!ft_strncmp(str, "WE", 2) && is_a_white_space(str[2]))
		return (WEST);
	if (!ft_strncmp(str, "EA", 2) && is_a_white_space(str[2]))
		return (EAST);
	if (!ft_strncmp(str, "F", 1) && is_a_white_space(str[1]))
		return (FLOOR);
	if (!ft_strncmp(str, "C", 1) && is_a_white_space(str[1]))
		return (CEILING);
	while (is_a_white_space(*str))
		str++;
	if (*str == '1' || *str == '0')
		return (MAP);
	return (0);
}

bool	fill_new_line(t_data *data, char **line)
{
	int				type;
	static bool		(*fill_functions[])() = {NULL, fill_north, fill_south,
		fill_west, fill_east, NULL, fill_ceiling, fill_floor};

	type = identify_line(*line);
	if (!type)
		return (false);
	if ((NORTH <= type && type < DOOR_2) || (FLOOR <= type && type <= CEILING))
		return (fill_functions[type](data, *line));
	if (type == MAP)
		return (fill_map(data, line));
	return (true);
}

static void	fill_better_colors(t_data *data)
{
	data->ceiling_color_2 = data->ceiling_color[0];
	data->ceiling_color_2 <<= 8;
	data->ceiling_color_2 += data->ceiling_color[1];
	data->ceiling_color_2 <<= 8;
	data->ceiling_color_2 += data->ceiling_color[2];
	data->floor_color_2 = data->floor_color[0];
	data->floor_color_2 <<= 8;
	data->floor_color_2 += data->floor_color[1];
	data->floor_color_2 <<= 8;
	data->floor_color_2 += data->floor_color[2];
}

void	fill_map_file_cont(t_data *data, char *line)
{
	err("Map file: spurious line in file");
	free(line);
	unleek_gnl(data->fd);
	close(data->fd);
}

bool	fill_map_file(t_data *data, char *map)
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
				return (fill_map_file_cont(data, line), false);
		}
		free(line);
	}
	close(data->fd);
	if (data->nb_side_parsed != 7)
		return (err("Map file: incomplete file"), false);
	fill_better_colors(data);
	return (true);
}
