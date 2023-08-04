/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:23:19 by psimarro          #+#    #+#             */
/*   Updated: 2023/07/13 21:00:34 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../Libft/inc/libft.h"

static void	s(t_item *stack)
{
	int	num;
	int	index;

	if (!stack)
		return ;
	num = stack->next->val;
	index = stack->next->ind;
	stack->next->val = stack->val;
	stack->next->ind = stack->ind;
	stack->val = num;
	stack->ind = index;
}

void	sa(t_pswap *data)
{
	s(data->stack_a);
	if (data->print_ops)
		ft_putstr_fd("sa\n", 1);
}

void	ss(t_pswap *data)
{
	s(data->stack_a);
	s(data->stack_b);
	if (data->print_ops)
		ft_putstr_fd("ss\n", 1);
}

void	sa_ra(t_pswap *data, int reverse)
{
	sa(data);
	if (reverse)
		rra(data);
	else
		ra(data);
}
