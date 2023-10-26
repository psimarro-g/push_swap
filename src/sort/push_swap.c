/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <psimarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:21:52 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/26 12:47:54 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	sort_three(t_pswap *data, int ind)
{
	t_item	*stack;

	stack = data->stack_a;
	if (stack->ind == ind + 2 && stack->next->ind == ind)
		ra(data);
	else if (stack->ind == ind + 1 && stack->next->ind == ind + 2)
		rra(data);
	else if (stack->ind == ind && stack->next->ind == ind + 2)
		sa_ra(data, 0);
	else if (stack->ind == ind + 2 && stack->next->ind == ind + 1)
		sa_ra(data, 1);
	else if (stack->ind == ind + 1 && stack->next->ind == ind)
		sa(data);
}

static void	check_ss(t_pswap *data, int ind)
{
	t_item	*stack;

	stack = data->stack_a;
	if (stack->ind == ind && stack->next->ind == ind + 2)
		ss(data);
	else if (stack->ind == ind + 2 && stack->next->ind == ind + 1)
		ss(data);
	else if (stack->ind == ind + 1 && stack->next->ind == ind)
		ss(data);
	else
		sb(data);
}

void	sort_five(t_pswap *data)
{
	int		ind;
	t_item	*stack;

	stack = data->stack_a;
	ind = ps_lstsize(stack) - 3;
	while (ind--)
		r_or_rr(data, data->stack_size - 4);
	if (data->stack_b->ind < data->stack_b->next->ind && data->stack_b->next)
		check_ss(data, data->stack_size - 3);
	sort_three(data, data->stack_size - 3);
	pa(data);
	pa(data);
}

void	sort_last_a(t_pswap *data)
{
	int i;

	if (!ps_lst_is_sorted(data->stack_a))
	{
		i = ps_lstsize(data->stack_a);
		if (i < 3)
			sa(data);
		else if (i < 4)
			sort_three(data, data->stack_size - 3);
		else
			sort_five(data);
	}
}

void	sort(t_pswap *data)
{
	if (data->stack_size < 3)
		sa(data);
	else if (data->stack_size < 4)
		sort_three(data, 0);
	else if (data->stack_size < 6)
		sort_five(data);
	else
		ft_quick_sort(data);
}
