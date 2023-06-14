/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:37:55 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/14 19:18:39 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int     size;
	int		**val;
}	t_stack;

/* PTR_ATOI.C */
int	    *ft_ptr_atoi(const char *str);

/* PARSE:C */
void	fill_stack (char *s, t_stack *t);
void	ft_mem_error(void);

/* UTILS.C */
void    ft_free_stack(char **stack);
void    ft_free_int_stack(int **stack);

#endif
