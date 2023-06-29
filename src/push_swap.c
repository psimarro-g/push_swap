/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:53:30 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/29 18:45:12 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"
#include "../inc/push_swap.h"

void	show_leaks(void)
{
	system("leaks -q push_swap");
}

int main(int argc, char **argv)
{
	t_pswap	data;
    t_item  *elem;

    atexit(show_leaks);
    if (argc > 1 && argv)
    {
		if (fill_stack(&data, argv) == 0)
        {
            ps_lstclear(&data.stack_a);
            ft_mem_error();
        }
        elem = data.stack_a;
        while (elem)
	    {
		    ft_printf("%i\n", elem->val);
            elem = elem->next;
	    }
        ps_lstclear(&data.stack_a);
        //añadir aqui el printeo y el free de la lista para ver si lo ha guardado bien
    }
    return (0);
}
