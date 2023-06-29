/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:14:18 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/29 18:22:27 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../Libft/inc/libft.h"

int	ps_lst_is_sorted(t_item *first)
{
    t_item  *elem;
    
	if (!first)
		return (1);
    elem = first;
	while (elem->next)
	{
		if (elem->val >= elem->next->val)
			return (0);
        elem = elem->next;
	}
    return (1);
}

int	ps_lstsize(t_item *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ps_lstindex(t_item *stack)
{
    int		index;
	t_item	*top;
	t_item	*temp;

	index = 0;
	top = stack;
	while (stack)
	{
		temp = top;
		while (temp)
		{
			if (temp->val < stack->val)
				index++;
			temp = temp->next;
		}
		stack->ind = index;
		stack = stack->next;
		index = 0;
	}
}

void	ps_lstclear(t_item **lst)
{
	t_item		*item;
    t_item		*temp;

	if (!lst)
		return ;
    item = *lst;
	while (item)
	{
		temp = item->next;
		free(item);
        item = temp;
	}
    *lst = NULL;
}
