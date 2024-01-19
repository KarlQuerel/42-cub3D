/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:36:53 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/19 17:37:13 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	setup_text(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		data->dialog[i].img = NULL;
		i++;
	}
}

void	clear_text(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (data->dialog[i].img)
			mlx_destroy_image(data->mlx, data->dialog[i].img);
		i++;
	}
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
