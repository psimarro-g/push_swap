/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:18 by psimarro          #+#    #+#             */
/*   Updated: 2023/08/15 13:40:27 by psimarro         ###   ########.fr       */
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
}

/*
si hay elementos del chunk ver si sb_hold = 1 y si los dos primeros elementos de a estan desordenados hacer ss, si no hacer sb
mirar si el elemento mas cercano del chunk esta mas cerca con ra o rra
si hay que hacer ra y rb esta en hold hacer rr
cuando el elemento este en top de a pushear a b
mirar si el elemento tiene que ir a top o bottom de b y modificar hold rb
si se queda en top mirar si hay que hacer sb y modificar sb_hold
*/

static void	ft_sort_chunck(t_pswap *data, int chunk_size, int chunk)
{
	int	i;

	i = are_values(data, chunk_size * chunk);
	while (i)
	{
		if (data->stack_a->ind < (chunk_size * chunk))
			pb(data);
		else
			ra_or_rr(data);
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
		ft_sort_chunck(data, chunk_size, i++);
	sort_a(data);
}
