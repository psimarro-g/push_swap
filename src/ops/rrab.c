/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:30:51 by psimarro          #+#    #+#             */
/*   Updated: 2023/08/15 12:44:55 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../Libft/inc/libft.h"

static void	rr(t_item *stack)
{
	int	num;
	int	index;

	if (!stack)
		return ;
	stack = ps_lstlast(stack);
	num = stack->val;
	index = stack->ind;
	while (stack)
	{
		if (stack->pre == NULL)
		{
			stack->val = num;
			stack->ind = index;
		}
		else
		{
			stack->val = stack->pre->val;
			stack->ind = stack->pre->ind;
		}
		stack = stack->pre;
	}
}

void	rra(t_pswap *data)
{
	rr(data->stack_a);
	if (data->print_ops)
		ft_putstr_fd("rra\n", 1);
}
