/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:45:42 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/14 19:18:45 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../inc/push_swap.h"

void	ft_mem_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
}

static int	fill_stack_aux(char **p, t_stack *stack)
{
	int		i;
	
	i = 0;
	stack->size = 0;
    while (p[stack->size])
        stack->size++;
	stack->size++;
	stack->val = calloc(stack->size, sizeof(int*));
	if (stack->val == NULL)
		return (0);
	while (p[i])
	{
		stack->val[i] = ft_ptr_atoi(p[i]);
		if (stack->val[i++] == NULL)
		{
			ft_free_int_stack(stack->val);
            stack->val = NULL;
        }
	}
	return (1);
}

void	fill_stack(char *s, t_stack *stack)
{
	char    **arr;

	arr = ft_split(s, ' ');
	if (arr == NULL)
		ft_mem_error();
	fill_stack_aux(arr, stack);
	if (stack->val == NULL)
	{
		ft_free_stack(arr);
		ft_mem_error();
	}
	ft_free_stack(arr);
}
