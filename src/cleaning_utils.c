/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:30:34 by kquerel           #+#    #+#             */
/*   Updated: 2024/02/09 19:53:14 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	err(char *s)
{
	ft_print_fd(2, "Error\n%s\n", s);
}

int	quit_game(t_data *data)
{
	data_clear(data);
	exit(0);
	return (0);
}
