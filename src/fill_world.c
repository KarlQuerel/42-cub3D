/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:02:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/12 18:14:41 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	fill_ceiling(t_data *data, char *line)
{
	static int	nb_ceiling = 0;
	int			i;

	if (nb_ceiling)
		return (false);
	i = 1;
	while (is_a_white_space(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	data->ceiling.img = mlx_xpm_file_to_image(data->mlx, line + i, \
	&data->img_width, &data->img_height);
	if (!data->ceiling.img)
	{
		if (!atocolor(line + i, &data->ceiling_color))
			return (false);
		data->nb_side_parsed++;
		return (true);
	}
	data->ceiling.addr = mlx_get_data_addr(data->ceiling.img, \
	&data->ceiling.bpp, &data->ceiling.ll, &data->ceiling.endian);
	if (!data->ceiling.addr)
		return (false);
	nb_ceiling++;
	data->nb_side_parsed++;
	return (true);
}

bool	fill_floor(t_data *data, char *line)
{
	static int	nb_floor = 0;
	int			i;

	if (nb_floor)
		return (false);
	i = 1;
	while (is_a_white_space(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	data->floor.img = mlx_xpm_file_to_image(data->mlx, line + i, \
	&data->img_width, &data->img_height);
	if (!data->floor.img)
	{
		if (!atocolor(line + i, &data->floor_color))
			return (false);
		data->nb_side_parsed++;
		return (true);
	}
	data->floor.addr = mlx_get_data_addr(data->floor.img, \
	&data->floor.bpp, &data->floor.ll, &data->floor.endian);
	if (!data->floor.addr)
		return (false);
	nb_floor++;
	data->nb_side_parsed++;
	return (true);
}

bool	fill_map(t_data *data, char **line, int fd)
{
	char	*map;

	data->map = NULL;
	data->width = 1;
	data->height = ft_strlen(*line) - 1;
	map = malloc(1);
	if (!map)
		return (unleekGnl(fd), false);
	map[0] = 0;
	while (*line)
	{
		free_strs(&data->map);
		if (!ft_strjoin(&map, map, *line, 3))
			return (unleekGnl(fd), false);
		data->map = ft_split(map, '\n');
		if (!data->map)
			return (free(map), unleekGnl(fd), false);
		*line = ft_get_next_line(fd);
		data->width++;
	}
	free(map);
	data->nb_side_parsed++;
	return (true);
}
