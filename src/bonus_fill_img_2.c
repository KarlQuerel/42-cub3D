/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fill_img_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:28:53 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/08 14:31:44 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool	upload_img(t_data *data, t_img_info *img, char *file)
{
	img->img = mlx_xpm_file_to_image(data->mlx, file, \
	&img->width, &img->height);
	if (!img->img)
		return (false);
	img->addr = mlx_get_data_addr(img->img, \
	&img->bpp, &img->ll, &img->endian);
	if (!img->addr)
		return (false);
	return (true);
}

bool	get_wall_cat(t_data *data)
{
	static char	file[] = "img/CheshireCat/wall_cat/x.xpm";
	int			i;

	i = 1;
	while (i < 7)
	{
		file[25] = '0' + i;
		if (!upload_img(data, &((data->cheshire_cat)[i - 1]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	return (true);
}

bool	get_dialog_cat(t_data *data)
{
	static char	file[] = "img/CheshireCat/dialog_cat/x.xpm";
	int			i;

	i = 1;
	while (i < 7)
	{
		file[27] = '0' + i;
		if (!upload_img(data, &((data->dialog_cat)[i - 1]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	return (true);
}

bool	get_text(t_data *data)
{
	if (!upload_img(data, &((data->dialog)[1]), ALICE_D_1))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[2]), ALICE_D_2))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[3]), ALICE_D_3))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[4]), ALICE_D_4))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[5]), RABBIT_D_1))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[6]), RABBIT_D_2))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[7]), RABBIT_D_3))
		return (err(strerror(errno)), false);
	return (true);
}

bool	get_alice(t_data *data)
{
	static char	file[17] = "img/Alice/xx.xpm\0";
	int			i;

	i = 1;
	while (i - 1 < 18)
	{
		file[10] = i / 10 + '0';
		file[11] = i % 10 + '0';
		if (!upload_img(data, &((data->alice)[i - 1]), file))
			return (err(strerror(errno)), false);
		i++;
	}
	return (true);
}
