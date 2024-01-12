/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_delete_before_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:40:44 by kquerel           #+#    #+#             */
/*   Updated: 2024/01/12 10:05:08 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//A SUPPRIMER AVANT DE PUSH
void	put_v2f(t_v2f vecteur)
{
	printf("vecteur <%f|%f>\n", vecteur[0], vecteur[1]);
}

//A SUPPRIMER AVANT DE PUSH
void	put_strs(char **strs)
{
	while (*strs)
	{
		printf("<%s>\n", *strs);
		strs++;
	}
}
