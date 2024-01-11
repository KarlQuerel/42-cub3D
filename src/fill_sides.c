/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:28:25 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/11 17:29:38 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
