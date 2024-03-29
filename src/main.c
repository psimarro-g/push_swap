/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:53:30 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/29 17:03:23 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../inc/push_swap.h"

void	show_leaks(void)
{
	system("leaks -q push_swap");
}

static void	init_data(t_pswap *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->stack_size = 0;
	data->print_ops = 0;
	data->hold_rb = 0;
	data->hold_ra = 0;
	data->hold_sa = 0;
}

int	main(int argc, char **argv)
{
	t_pswap	data;

	//atexit(show_leaks);
	init_data(&data);
	if (argc > 1 && argv)
	{
		if (fill_stack(&data, argv) == 0)
		{
			ps_lstclear(&data.stack_a);
			ft_mem_error();
		}
		if (!ps_lst_is_sorted(data.stack_a))
		{
			ps_lstindex(data.stack_a);
			data.stack_size = ps_lstsize(data.stack_a);
			data.print_ops = 1;
			sort(&data);
			ps_lstclear(&data.stack_b);
		}
		ps_lstclear(&data.stack_a);
	}
	return (0);
}
