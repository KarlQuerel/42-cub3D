/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:03:59 by pcheron           #+#    #+#             */
/*   Updated: 2023/05/30 17:20:04 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_lst	*ft_lstnew(char *content)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_lst **lst)
{
	t_lst	*tmp;

	while (lst && *lst)
	{
		if ((*lst)->content)
			free((*lst)->content);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*temp;

	if (lst && !*lst)
		*lst = new;
	else if (lst && *lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
