/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:18 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/29 18:37:40 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
si hay elementos del chunk ver si sb_hold = 1 y
si los dos primeros elementos de a estan desordenados hacer ss, si no hacer sb
mirar si el elemento mas cercano del chunk esta mas cerca con ra o rra
si hay que hacer ra y rb esta en hold hacer rr
cuando el elemento este en top de a pushear a b
mirar si el elemento tiene que ir a top o bottom de b y modificar hold rb
si se queda en top mirar si hay que hacer sb y modificar sb_hold
*/

int	is_value(t_pswap *data, int value, int chunk)
{
	if (value >= chunk || value > data->stack_size - 6)
		return (1);
	return (0);
}

static void	do_top(t_pswap *data, int top)
{
	if (data->hold_rb && top > 1)
	{
		data->hold_rb = 0;
		rr(data);
		(top)--;
	}
	while ((top)-- > 1)
		ra(data);
}

static void	search_chunk(t_pswap *data, int chunk)
{
	int		mid;
	int		top;
	int		bot;
	t_item	*stack;

	stack = data->stack_a;
	mid = (ps_lstsize(stack) / 2) + (ps_lstsize(stack) & 1);
	top = 0;
	bot = 0;
	while (top++ < mid && is_value(data, stack->ind, chunk))
		stack = stack->next;
	stack = ps_lstlast(stack);
	while (bot++ < mid && is_value(data, stack->ind, chunk))
		stack = stack->pre;
	if (top <= bot)
		do_top(data, top);
	else
	{
		while (bot--)
			rra(data);
	}
}

static void	ft_sort_chunck(t_pswap *data, int chunk_size, int chunk)
{
	int	half_chunk;
	int	i;
	int	block;

	block = chunk_size * chunk;
	i = block - chunk_size;
	half_chunk = block - (chunk_size / 2);
	while (i < block && i++ < data->stack_size - 5)
	{
		search_chunk(data, block);
		if (data->hold_rb)
		{
			data->hold_rb = 0;
			rb(data);
		}
		pb(data);
		if (data->stack_b->ind < half_chunk && data->stack_size - block > 0)
			data->hold_rb = 1;
		else
			data->hold_rb = 0;
	}
}

void	ft_quick_sort(t_pswap *data)
{
	int	chunk_size;
	int	chunks;
	int	i;

	i = 1;
	chunk_size = MIN_CHUNK_SIZE;
	if (data->stack_size > 250)
		chunk_size = MAX_CHUNK_SIZE;
	chunks = data->stack_size / chunk_size;
	if (data->stack_size % chunk_size)
		chunks++;
	while (chunks--)
	{
		ft_sort_chunck(data, chunk_size, i);
		i++;
	}
	if (data->hold_rb)
		rb(data);
	sort_five(data);
	sort_a(data);
}
