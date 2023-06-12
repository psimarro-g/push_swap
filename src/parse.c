/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:45:42 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/12 20:52:11 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../inc/push_swap.h"

void	ft_mem_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
}

static int	**fill_stack_aux(char **p, t_pswap *t)
{
	int     **stack;
	int		i;
	
	i = 0;
	t->stack_size = 0;
    while (p[t->stack_size])
        t->stack_size++;
	t->stack_size++;
	stack = calloc(t->stack_size, sizeof(int*));
	if (stack == NULL)
		return (NULL);
	while (p[i])
	{
		stack[i] = ft_ptr_atoi(p[i]);
		if (stack[i++] == NULL)
		{
			ft_free_int_stack(stack);
            return (NULL);
        }
	}
	return (stack);
}

int	**fill_stack (char *s, t_pswap *t)
{
	char    **arr;
    int     **stack;

	arr = ft_split(s, ' ');
	if (arr == NULL)
		ft_mem_error();
	stack = fill_stack_aux(arr, t);
	if (stack == NULL)
	{
		ft_free_stack(arr);
		ft_mem_error();
	}
	ft_free_stack(arr);
	return (stack);
}
