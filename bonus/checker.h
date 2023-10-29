/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <psimarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:58:22 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/27 19:53:38 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_item
{
	struct s_item	*next;
	struct s_item	*pre;
	int				val;
	int				ind;
}	t_item;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_pswap
{
	t_item		*stack_a;
	t_item		*stack_b;	
	int			print_ops;
}	t_pswap;

/* LIST/LIST_FUNC.C */
t_item	*ps_lstnew(int elem);
t_item	*ps_lstlast(t_item *lst);
void	ps_lstadd_back(t_item **lst, t_item *new);
void	ps_lstadd_front(t_item **lst, t_item *new);

/* LIST/LIST_FUNC2.C */
int		ps_lst_is_sorted(t_item *first);
int		ps_lstsize(t_item *lst);
void	ps_lstindex(t_item *stack);
void	ps_lstclear(t_item **lst);

/* PARSE/PTR_ATOI.C */
int		ft_ptr_atoi(const char *str, int *value, int i);

/* PARSE/PARSE:C */
void	ft_mem_error(void);
int		fill_stack(t_pswap *data, char **input);

/* OPS/SAB.C */
void	sa(t_pswap *data);
void	sb(t_pswap *data);
void	ss(t_pswap *data);

/* OPS/RAB.C */
void	ra(t_pswap *data);
void	rb(t_pswap *data);
void	rr(t_pswap *data);

/* OPS/RRAB.C */
void	rra(t_pswap *data);
void	rrb(t_pswap *data);
void	rrr(t_pswap *data);

/* OPS/PAB.C */
void	pa(t_pswap *data);
void	pb(t_pswap *data);

#endif
