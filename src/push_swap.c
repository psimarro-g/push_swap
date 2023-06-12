/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:53:30 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/12 20:50:18 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../inc/push_swap.h"

void	show_leaks(void)
{
	system("leaks -q push_swap");
}

int main(int argc, char **argv)
{
	t_pswap	t;
	int     **stack;
	int		i;
    
    atexit(show_leaks);
	i = 0;
    if (argc > 1)
    {
		stack = fill_stack(argv[1], &t);
        while (stack[i])
			ft_printf("%i\n", *stack[i++]);
		ft_free_int_stack(stack);
    }
    return (0);
}
