/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:01:48 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/28 14:31:34 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_item	*ps_lstnew(int elem)
{
	t_item	*new;

	new = (t_item *)ft_calloc(sizeof(t_item *), 1);
	if (!new)
		return (0);
	new->val = elem;
	new->ind = 0;
	new->next = NULL;
	new->pre = NULL;
	return (new);
}

t_item	*ps_lstlast(t_item *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_back(t_item **lst, t_item *new)
{
	t_item  *last;

	if (!lst || !new)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
        new->pre = last;
	}
}

void	ps_lstadd_front(t_item **lst, t_item *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
