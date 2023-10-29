/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:18:19 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/29 18:37:19 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
mientras el index no llegue a 0, comprobar si el elemento i 
esta arriba o abajo del stack b para hacer rb o rrb.
comprobar si en algun momento el elemento i - 1 
esta arriba del stack b y hacer pa para cachearlo.
actualizar hold_sa mientras se encuentra el elemento i.
una vez encontrado el elemento i, hacer pa y si hold_sa = 1 hacer sa.
*/

static int	ft_check_ssa(t_pswap *data, int *i)
{
	if (data->hold_sa == 0)
	{
		*i -= 1;
		return (0);
	}
	else
	{
		*i -= 2;
		data->hold_sa = 0;
		if (data->stack_b && data->stack_b->next \
			&& data->stack_b->ind < data->stack_b->next->ind)
			ss(data);
		else
			sa(data);
	}
	return (1);
}

static void	ft_do_ra(t_pswap *data, int top, int *i)
{
	while (top-- > 1)
	{
		if (data->stack_b->ind == *i - 1)
		{
			data->hold_sa = 1;
			pa(data);
		}
		else
			rb(data);
	}
}

static void	ft_do_rra(t_pswap *data, int bot, int *i)
{
	while (bot--)
	{
		if (data->stack_b->ind == *i - 1)
		{
			data->hold_sa = 1;
			pa(data);
			rrb(data);
		}
		else
			rrb(data);
	}
}

static void	find_push(t_pswap *data, int *i)
{
	int		mid;
	int		top;
	int		bot;
	t_item	*stack;

	stack = data->stack_b;
	mid = (ps_lstsize(stack) / 2) + (ps_lstsize(stack) & 1);
	top = 0;
	bot = 0;
	while (top++ < mid && stack->ind != *i)
		stack = stack->next;
	stack = ps_lstlast(stack);
	while (bot++ < mid && stack->ind != *i)
		stack = stack->pre;
	if (top <= bot)
		ft_do_ra(data, top, i);
	else
		ft_do_rra(data, bot, i);
	pa(data);
	ft_check_ssa(data, i);
}

void	sort_a(t_pswap *data)
{
	int	i;

	i = data->stack_size - 6;
	while (data->stack_b && data->stack_b->next)
	{
		find_push(data, &i);
		if (data->hold_sa)
		{
			sa(data);
			data->hold_sa = 0;
		}
	}
	pa(data);
	if (data->hold_sa)
	{
		sa(data);
		data->hold_sa = 0;
	}
}
