/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:37:55 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/29 17:50:25 by psimarro         ###   ########.fr       */
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

/* LIST_FUNC.C */
t_item	*ps_lstnew(int elem);
t_item	*ps_lstlast(t_item *lst);
void	ps_lstadd_back(t_item **lst, t_item *new);
void	ps_lstadd_front(t_item **lst, t_item *new);

/* LIST_FUNC2.C */
int	ps_lst_is_sorted(t_item *first);
int	ps_lstsize(t_item *lst);
void	ps_lstindex(t_item *stack);
void	ps_lstclear(t_item **lst);

/* PTR_ATOI.C */
int	    ft_ptr_atoi(const char *str, int *value, int i);

/* PARSE:C */
void	ft_mem_error(void);
int		fill_stack(t_pswap *data, char **input);

/* UTILS.C */
void    ft_free_stack(char **stack);
void    ft_free_int_stack(int **stack);

#endif
