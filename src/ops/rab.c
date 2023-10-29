/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:48:26 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/29 19:05:27 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../libft/inc/libft.h"

static void	r(t_item *stack)
{
	int	num;
	int	index;

	if (!stack || !stack->next)
		return ;
	num = stack->val;
	index = stack->ind;
	while (stack)
	{
		if (stack->next == NULL)
		{
			stack->val = num;
			stack->ind = index;
		}
		else
		{
			stack->val = stack->next->val;
			stack->ind = stack->next->ind;
		}
		stack = stack->next;
	}
}

void	rb(t_pswap *data)
{
	r(data->stack_b);
	if (data->print_ops)
		ft_putstr_fd("rb\n", 1);
}

void	ra(t_pswap *data)
{
	r(data->stack_a);
	if (data->print_ops)
		ft_putstr_fd("ra\n", 1);
}

void	rr(t_pswap *data)
{
	r(data->stack_a);
	r(data->stack_b);
	if (data->print_ops)
		ft_putstr_fd("rr\n", 1);
}

void	r_or_rr(t_pswap *data, int chunk)
{
	int		mid;
	int		top;
	int		bot;
	int		size;
	t_item	*stack;

	stack = data->stack_a;
	mid = (data->stack_size / 2) + (data->stack_size & 1);
	size = ps_lstsize(stack);
	mid = (size / 2) + (size & 1);
	top = 0;
	bot = 0;
	while (top++ < mid && stack->ind > chunk)
		stack = stack->next;
	stack = ps_lstlast(stack);
	while (bot++ < mid && stack->ind > chunk)
		stack = stack->pre;
	if (top <= bot)
		while (--top)
			ra(data);
	else
		while (bot--)
			rra(data);
	pb(data);
}
