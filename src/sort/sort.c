/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <psimarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:18 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/25 14:53:02 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h> //esto hay que quitarlo

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
	while (top++ < mid && stack->ind > chunk)
		stack = stack->next;
	stack = ps_lstlast(stack);
	while (bot++ < mid && stack->ind > chunk)
		stack = stack->pre;
	if (top <= bot)
	{
		if (data->hold_rb && top)
		{
			data->hold_rb = 0;
			rr(data);
			top--;
		}
		while (--top)
			ra(data);
	}
	else
	{
		while (bot--)
			rra(data);
	}
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
	int	half_chunk;

	i = chunk_size * (chunk - 1);
	if (chunk_size * chunk >= data->stack_size)
	{
		half_chunk = data->stack_size - 5;
		while (i++ < half_chunk)
		{
			search_chunk(data, half_chunk - 1); 
			pb(data);
		}
		printf("\ndone\n\n"); //esto hay que quitarlo
		sort_five(data);
	}
	else
	{
		half_chunk = chunk_size * chunk - (chunk_size / 2);
		while (1)
		{
			if (!are_values(data->stack_a, chunk_size * chunk))
				break ;
			search_chunk(data, chunk_size * chunk);
			if (data->hold_rb)
				rb(data);
			pb(data);
			if (data->stack_b->val < half_chunk)
				data->hold_rb = 1;
		}
	}
}

/*
mientras el index no llegue a 0, comprobar si el elemento i esta arriba o abajo del stack b para hacer rb o rrb.
comprobar si en algun momento el elemento i - 1 esta arriba del stack b y hacer pa para cachearlo.
actualizar hold_sa mientras se encuentra el elemento i.
una vez encontrado el elemento i, hacer pa y si hold_sa = 1 hacer sa.
*/

static int	ft_check_ssa(t_pswap *data, int *i)
{

}

static void	find_push(t_pswap *data, int *i, int next)
{
	
	
	if (ft_check_ssa(data, &i))
			data->hold_sa = 0;
}

static void	sort_a(t_pswap *data, int chunk_size)
{
	int	i;

	i = data->stack_size - 6;
	while (data->stack_b->next)
	{
		find_push(data, &i, 1);
		if (data->hold_sa)
		{
			sa(data);
			data->hold_sa = 0;
		}
	}
	pa(data);
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
	//sort_a(data, chunk_size);
}
