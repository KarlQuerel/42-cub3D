/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:02:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/06 17:44:53 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	fill_ceiling(t_data *data, char *line)
{
	static int	nb_ceiling = 0;
	int			i;

	if (nb_ceiling)
		return (write(2, "too many ceiling\n", 10), false);
	i = 1;
	while (is_a_white_space(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	data->ceiling.img = mlx_xpm_file_to_image(data->mlx, line + i, \
	&data->img_width, &data->img_height);
	if (!data->ceiling.img)
	{
		if (!atocolor(line + i, &data->ceiling_color))
			return (write(2, "invalid ceiling\n", 14), false);
		data->nb_side_parsed++;
		return (true);
	}
	data->ceiling.addr = mlx_get_data_addr(data->ceiling.img, \
	&data->ceiling.bpp, &data->ceiling.ll, &data->ceiling.endian);
	if (!data->ceiling.addr)
		return (write(2, "get addr error\n", 10), false);
	nb_ceiling++;
	data->nb_side_parsed++;
	return (true);
}

bool	fill_floor(t_data *data, char *line)
{
	static int	nb_floor = 0;
	int			i;

	if (nb_floor)
		return (write(2, "too many floor\n", 10), false);
	i = 1;
	while (is_a_white_space(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	data->floor.img = mlx_xpm_file_to_image(data->mlx, line + i, \
	&data->img_width, &data->img_height);
	if (!data->floor.img)
	{
		if (!atocolor(line + i, &data->floor_color))
			return (write(2, "invalid floor\n", 14), false);
		data->nb_side_parsed++;
		return (true);
	}
	data->floor.addr = mlx_get_data_addr(data->floor.img, \
	&data->floor.bpp, &data->floor.ll, &data->floor.endian);
	if (!data->floor.addr)
		return (write(2, "get addr error\n", 10), false);
	nb_floor++;
	data->nb_side_parsed++;
	return (true);
}

bool	fill_north(t_data *data, char *line)
{
	static int	nb_north = 0;
	int			i;

	nb_north++;
	if (nb_north > 1)
		return (write(2, "too many north\n", 10), false);
	i = 2;
	while (is_a_white_space(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	data->north.img = mlx_xpm_file_to_image(data->mlx, line + i, \
	&data->img_width, &data->img_height);
	if (!data->north.img)
		return (write(2, "xpm to img error\n", 17), false);
	data->north.addr = mlx_get_data_addr(data->north.img, \
	&data->north.bpp, &data->north.ll, &data->north.endian);
	if (!data->north.addr)
		return (write(2, "get addr error\n", 10), false);
	data->nb_side_parsed++;
	return (true);
}

bool	fill_south(t_data *data, char *line)
{
	static int	nb_south = 0;
	int			i;

	nb_south++;
	if (nb_south > 1)
		return (false);
	i = 2;
	while (is_a_white_space(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	data->south.img = mlx_xpm_file_to_image(data->mlx, line + i, \
	&data->img_width, &data->img_height);
	if (!data->south.img)
		return (false);
	data->south.addr = mlx_get_data_addr(data->south.img, \
	&data->south.bpp, &data->south.ll, &data->south.endian);
	if (!data->south.addr)
		return (false);
	data->nb_side_parsed++;
	return (true);
}

bool	fill_west(t_data *data, char *line)
{
	static int	nb_west = 0;
	int			i;

	nb_west++;
	if (nb_west > 1)
		return (false);
	i = 2;
	while (is_a_white_space(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	data->west.img = mlx_xpm_file_to_image(data->mlx, line + i, \
	&data->img_width, &data->img_height);
	if (!data->west.img)
		return (false);
	data->west.addr = mlx_get_data_addr(data->west.img, \
	&data->west.bpp, &data->west.ll, &data->west.endian);
	if (!data->west.addr)
		return (false);
	data->nb_side_parsed++;
	return (true);
}

bool	fill_east(t_data *data, char *line)
{
	static int	nb_east = 0;
	int			i;

	nb_east++;
	if (nb_east > 1)
		return (false);
	i = 2;
	while (is_a_white_space(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	data->east.img = mlx_xpm_file_to_image(data->mlx, line + i, \
	&data->img_width, &data->img_height);
	if (!data->east.img)
		return (false);
	data->east.addr = mlx_get_data_addr(data->east.img, \
	&data->east.bpp, &data->east.ll, &data->east.endian);
	if (!data->east.addr)
		return (false);
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
		return (false);
	map[0] = 0;
	while (*line)
	{
		free_strs(&data->map);
		if (!ft_strjoin(&map, map, *line, 3))
			return (false);
		data->map = ft_split(map, '\n');
		if (!data->map)
			return (free(map), false);
		*line = ft_get_next_line(fd);
		data->width++;
	}
	free(map);
	data->nb_side_parsed++;
	return (true);
}
