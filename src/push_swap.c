/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:53:30 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/14 19:22:46 by psimarro         ###   ########.fr       */
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
	t_stack	stack;
	int		i;
    
    atexit(show_leaks);
	i = 0;
    if (argc > 1)
    {
		fill_stack(argv[1], &stack);
        /*while (stack.val[i])
			ft_printf("%i\n", *stack.val[i++]);*/
		ft_free_int_stack(stack.val);
    }
    return (0);
}
