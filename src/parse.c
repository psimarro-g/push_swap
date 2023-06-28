/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:45:42 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/28 16:01:14 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../inc/push_swap.h"

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
	int		val;
	t_item	*new;
	char    **arr;

	data->stack_a = NULL;
	data->stack_b = NULL;
	i = 0;
	while (*input)
	{
		while (i != -1)
		{
			i = ft_ptr_atoi(*input, &val, i);
			if (i == 0)
				return (0);
			new = stack_lstnew(val);
			stack_lstadd_back(&data->stack_a, new);
		}
		*input++;
	}
	if (check_duplicates(data->stack_a))
		return (0);
	get_values(data);
	return (1);
}
