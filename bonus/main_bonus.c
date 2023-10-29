/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:59:13 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/29 17:59:49 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "./checker.h"

void	show_leaks(void)
{
	system("leaks -q checker");
}

static void	init_data(t_pswap *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->print_ops = 0;
}

void check_sort(t_pswap *data)
{
	char *line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "pb\n") == 0)
			pb(data);
		else if (ft_strcmp(line, "pa\n") == 0)
			pa(data);
		else if (ft_strcmp(line, "ra\n") == 0)
			ra(data);
		else if (ft_strcmp(line, "rra\n") == 0)
			rra(data);
		else if (ft_strcmp(line, "rb\n") == 0)
			rb(data);
		else if (ft_strcmp(line, "rrb\n") == 0)
			rrb(data);
		else if (ft_strcmp(line, "sa\n") == 0)
			sa(data);
		else if (ft_strcmp(line, "sb\n") == 0)
			sb(data);
		else if (ft_strcmp(line, "rr\n") == 0)
			rr(data);
		else if (ft_strcmp(line, "ss\n") == 0)
			ss(data);
		else if (ft_strcmp(line, "rrr\n") == 0)
			rrr(data);
		else
			ft_mem_error();
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_pswap	data;

	//atexit(show_leaks);
	init_data(&data);
	if (argc == 2 && argv)
	{
		if (fill_stack(&data, argv) == 0)
		{
			ps_lstclear(&data.stack_a);
			ft_mem_error();
		}
		check_sort(&data);
		if (!ps_lst_is_sorted(data.stack_a))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		ps_lstclear(&data.stack_b);
		ps_lstclear(&data.stack_a);
	}
	return (0);
}
