/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:18 by psimarro          #+#    #+#             */
/*   Updated: 2023/08/09 14:53:21 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	search_chunk(t_pswap *data, int chunk)
{
	int		mid;
	int		top;
	int		bot;
	t_item	*stack;

	stack = data->stack_a;
	mid = (data->stack_size / 2) + (data->stack_size & 1);
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


static void	ft_sort_chunck(t_pswap *data, int chunk_size, int chunk)
{
	int		chunk_number;

	chunk_number = data->stack_size / chunk_size;
	while (are_values(data->stack_a, chunk_size))
	{
		if (data->stack_a->ind < chunk_size)
			pb(data);
		else
			ra(data);
	}
}

void    ft_quick_sort(t_pswap *data)
{
    int chunk_size;
	int chunks;
	int i;

	i = 1;
    chunk_size = MIN_CHUNK_SIZE;
    if (data->stack_size > 250)
        chunk_size = MAX_CHUNK_SIZE;
	chunks = data->stack_size / chunk_size;
	if (data->stack_size % chunk_size)
		chunks++;
	while (chunks--)
		ft_sort_chunck(data, chunk_size, i++);
	sort_a(data);
}
