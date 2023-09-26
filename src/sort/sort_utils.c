/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:57:10 by psimarro          #+#    #+#             */
/*   Updated: 2023/08/15 14:09:18 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_get_min(t_item *stack)
{
	int	min;

	min = stack->val;
	while (stack)
	{
		if (stack->val < min)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

int	ft_get_max(t_item *stack)
{
	int	max;

	max = stack->val;
	while (stack)
	{
		if (stack->val > max)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

int	find_values(t_pswap *data, int chunk)
{
	int		mid;
	int		top;
	int		bot;
	t_item	*stack;

	stack = data->stack_a;
	mid = (ps_lstsize(stack) / 2) + (ps_lstsize(stack) & 1);
	top = 0;
	bot = 0;
	while (top++ < mid && stack->ind > chunk)
		stack = stack->next;
	stack = ps_lstlast(stack);
	while (bot++ < mid && stack->ind > chunk)
		stack = stack->pre;
	if (top <= bot)
		return (top);
	else
		while (bot--)
			rra(data);
	return (0);
}

int		are_values(t_item *stack, int chunk)
{
	t_item	*a_stack;

	a_stack = stack;
	while (a_stack)
	{
		if (a_stack->ind < chunk)
			return (1);
		a_stack = a_stack->next;
	}
	return (0);
}
