/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:45:42 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/29 17:38:50 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft.h"
#include "../../inc/push_swap.h"

void	ft_mem_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
}

static int	check_duplicates(t_item *stack)
{
	t_item	*stack_loop;

	while (stack)
	{
		stack_loop = stack->next;
		while (stack_loop)
		{
			if (stack->val == stack_loop->val)
				return (1);
			stack_loop = stack_loop->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	fill_stack(t_pswap *data, char **input)
{
	int		i;
	int		j;
	int		val;
	t_item	*new;

	j = 0;
	if (input[1][0] == '\0')
		return (0);
	while (input[++j])
	{
		i = 0;
		while (i != -1)
		{
			i = ft_ptr_atoi(input[j], &val, i);
			if (i == 0)
				return (0);
			new = ps_lstnew(val);
			ps_lstadd_back(&data->stack_a, new);
		}
	}
	if (check_duplicates(data->stack_a))
		return (0);
	return (1);
}
