/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:37:55 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/28 15:45:18 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>

typedef struct s_item
{
	int     		val;
	int				ind;
	struct s_item	*next;
	struct s_item	*pre;
}	t_item;

typedef struct s_pswap
{
	t_item		*stack_a;
	t_item		*stack_b;	
	int			stack_size;
	int			max;
	int			min;
}	t_pswap;

/* DUPLICATES.C */
void	check_duplicates(int **stack);

/* PTR_ATOI.C */
int	    *ft_ptr_atoi(const char *str, int *value, int i);

/* PARSE:C */
void	ft_mem_error(void);

/* UTILS.C */
void    ft_free_stack(char **stack);
void    ft_free_int_stack(int **stack);

#endif
