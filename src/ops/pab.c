/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <psimarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:17:30 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/27 19:51:46 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../libft/inc/libft.h"

void	pa(t_pswap *data)
{
	t_item	*top;
	t_item	**org;
	t_item	**dest;

	org = &data->stack_b;
	dest = &data->stack_a;
	if (*org == NULL)
		return ;
	top = (*org)->next;
	if (*dest == NULL)
		(*org)->next = NULL;
	else
	{
		(*org)->next = *dest;
		(*dest)->pre = (*org);
	}
	*dest = *org;
	*org = top;
	if (*org)
		(*org)->pre = NULL;
	if (data->print_ops)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_pswap *data)
{
	t_item	*top;
	t_item	**org;
	t_item	**dest;

	org = &data->stack_a;
	dest = &data->stack_b;
	if (*org == NULL)
		return ;
	top = (*org)->next;
	if (*dest == NULL)
		(*org)->next = NULL;
	else
	{
		(*org)->next = *dest;
		(*dest)->pre = (*org);
	}
	*dest = *org;
	*org = top;
	if (*org)
		(*org)->pre = NULL;
	if (data->print_ops)
		ft_putstr_fd("pb\n", 1);
}
