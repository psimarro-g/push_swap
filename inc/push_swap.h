/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:37:55 by psimarro          #+#    #+#             */
/*   Updated: 2023/08/15 13:52:25 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

# define MIN_CHUNK_SIZE  25
# define MAX_CHUNK_SIZE  62

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
	int			stack_size;
	int			print_ops;
	int			hold_rb;
	int			hold_sb;
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
void	ss(t_pswap *data);
void	sa_ra(t_pswap *data, int reverse);

/* OPS/RAB.C */
void	ra(t_pswap *data);
void	r_or_rr(t_pswap *data, int chunk);

/* OPS/RRAB.C */
void	rra(t_pswap *data);

/* OPS/PAB.C */
void	pa(t_pswap *data);
void	pb(t_pswap *data);

/* PUSH_SWAP.C */
void	sort(t_pswap *data);

/* SORT.C */
void	ft_quick_sort(t_pswap *data);

/* SORT_UTILS.C */
int		ft_get_min(t_item *stack);
int		ft_get_max(t_item *stack);
int		find_values(t_pswap *data, int chunk);
int		are_values(t_item *stack, int chunk);

#endif
