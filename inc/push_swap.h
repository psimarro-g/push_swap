/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:37:55 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/12 20:51:49 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_pswap
{
	int     stack_size;
}	t_pswap;

/* PTR_ATOI.C */
int	    *ft_ptr_atoi(const char *str);

/* PARSE:C */
int	    **fill_stack (char *s, t_pswap *t);
void	ft_mem_error(void);

/* UTILS.C */
void    ft_free_stack(char **stack);
void    ft_free_int_stack(int **stack);

#endif
