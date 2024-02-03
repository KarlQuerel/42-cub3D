/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_file_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:19:33 by pcheron           #+#    #+#             */
/*   Updated: 2024/01/27 11:11:22 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	fill_north(t_data *data, char *line)
{
	static int	nb_north = 0;
	char		*new_line;

	nb_north++;
	if (nb_north > 1)
		return (false);
	if (!dup_next_world(line + 2, &new_line))
		return (false);
	// printf("<%s>\n", new_line);
	data->north.img = mlx_xpm_file_to_image(data->mlx, new_line, \
	&data->img_width, &data->img_height);
	if (!data->north.img)
		return (free(new_line), false);
	data->north.addr = mlx_get_data_addr(data->north.img, \
	&data->north.bpp, &data->north.ll, &data->north.endian);
	if (!data->north.addr)
		return (free(new_line), false);
	data->nb_side_parsed++;
	line += 2;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	jump_word(&line);
	if (*line)
		return (free(new_line), fill_new_line(data, &line));
	return (free(new_line), true);
}

bool	fill_south(t_data *data, char *line)
{
	static int	nb_south = 0;
	char		*new_line;

	nb_south++;
	if (nb_south > 1)
		return (false);
	if (!dup_next_world(line + 2, &new_line))
		return (false);
	data->south.img = mlx_xpm_file_to_image(data->mlx, new_line, \
	&data->img_width, &data->img_height);
	if (!data->south.img)
		return (free(new_line), false);
	data->south.addr = mlx_get_data_addr(data->south.img, \
	&data->south.bpp, &data->south.ll, &data->south.endian);
	if (!data->south.addr)
		return (free(new_line), false);
	data->nb_side_parsed++;
	line += 2;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	jump_word(&line);
	if (*line)
		return (free(new_line), fill_new_line(data, &line));
	return (free(new_line), true);
}

bool	fill_west(t_data *data, char *line)
{
	static int	nb_west = 0;
	char		*new_line;

	nb_west++;
	if (nb_west > 1)
		return (false);
	if (!dup_next_world(line + 2, &new_line))
		return (false);
	data->west.img = mlx_xpm_file_to_image(data->mlx, new_line, \
	&data->img_width, &data->img_height);
	if (!data->west.img)
		return (free(new_line), false);
	data->west.addr = mlx_get_data_addr(data->west.img, \
	&data->west.bpp, &data->west.ll, &data->west.endian);
	if (!data->west.addr)
		return (free(new_line), false);
	data->nb_side_parsed++;
	line += 2;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	jump_word(&line);
	if (*line)
		return (free(new_line), fill_new_line(data, &line));
	return (free(new_line), true);
}

bool	fill_east(t_data *data, char *line)
{
	static int	nb_east = 0;
	char		*new_line;

	nb_east++;
	if (nb_east > 1)
		return (false);
	if (!dup_next_world(line + 2, &new_line))
		return (false);
	data->east.img = mlx_xpm_file_to_image(data->mlx, new_line, \
	&data->img_width, &data->img_height);
	if (!data->east.img)
		return (free(new_line), false);
	data->east.addr = mlx_get_data_addr(data->east.img, \
	&data->east.bpp, &data->east.ll, &data->east.endian);
	if (!data->east.addr)
		return (free(new_line), false);
	data->nb_side_parsed++;
	line += 2;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	jump_word(&line);
	if (*line)
		return (free(new_line), fill_new_line(data, &line));
	return (free(new_line), true);
}
