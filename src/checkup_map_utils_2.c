/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup_map_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:57:44 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/18 20:07:08 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_cub_file(char *line)
{
	int	i;

	i = 0;
	while (!is_a_white_space(line[i]) && line[i])
		i++;
	return (!(i < 5 || ft_strncmp(line + i - 4, ".cub", 3)));
}
