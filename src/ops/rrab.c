/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <psimarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:30:51 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/27 19:51:05 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../libft/inc/libft.h"

static void	rrt(t_item *stack)
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
	rrt(data->stack_a);
	if (data->print_ops)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_pswap *data)
{
	rrt(data->stack_b);
	if (data->print_ops)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_pswap *data)
{
	rrt(data->stack_a);
	rrt(data->stack_b);
	if (data->print_ops)
		ft_putstr_fd("rrr\n", 1);
}
