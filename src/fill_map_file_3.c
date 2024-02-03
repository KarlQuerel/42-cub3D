/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_file_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:56:04 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/26 09:44:23 by pcheron          ###   ########.fr       */
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

bool	fill_map(t_data *data, char **line)
{
	char	*map;

	data->map = NULL;
	data->width = 0;
	data->height = ft_strlen(*line) - 1;
	map = malloc(1);
	if (!map)
		return (unleek_gnl(data->fd), false);
	map[0] = 0;
	while (*line && count_char_in_str('1', *line))
	{
		data->width++;
		free_strs(&data->map);
		if (!ft_strjoin(&map, map, *line, 3))
			return (unleek_gnl(data->fd), false);
		data->map = ft_split(map, '\n');
		if (!data->map)
			return (free(map), unleek_gnl(data->fd), false);
		*line = ft_get_next_line(data->fd);
	}
	unleek_gnl(data->fd);
	free(map);
	data->nb_side_parsed++;
	return (true);
}
