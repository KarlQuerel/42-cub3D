/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_coll_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:33:01 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/10 15:51:28 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

t_coll	*coll_new(t_v2f pos, bool type)
{
	t_coll	*coll;

	coll = malloc(sizeof(t_coll));
	if (coll == NULL)
		return (NULL);
	coll->pos = pos;
	coll->type = type;
	coll->next = NULL;
	return (coll);
}

t_coll	*coll_last(t_coll *coll)
{
	while (coll && coll->next)
		coll = coll->next;
	return (coll);
}

void	coll_clear(t_coll **coll)
{
	t_coll	*tmp;

	while (coll && *coll)
	{
		tmp = (*coll)->next;
		free(*coll);
		*coll = tmp;
	}
}

void	coll_add_back(t_coll **coll, t_coll *new)
{
	t_coll	*temp;

	if (coll && !*coll)
		*coll = new;
	else if (coll && *coll)
	{
		temp = coll_last(*coll);
		temp->next = new;
	}
}

void	coll_delete(t_coll **coll, t_v2f pos)
{
	t_coll	*tmp;
	t_coll	*tmp_2;

	tmp_2 = NULL;
	if (coll)
	{
		tmp = *coll;
		while (tmp)
		{
			if (pos[0] == tmp->pos[0] && pos[1] == tmp->pos[1])
			{
				if (!tmp_2)
					*coll = tmp->next;
				else
					tmp_2->next = tmp->next;
				free(tmp);
				return ;
			}
			tmp_2 = tmp;
			tmp = tmp->next;
		}
	}
}
