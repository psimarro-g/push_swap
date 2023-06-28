/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:53:30 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/28 16:01:03 by psimarro         ###   ########.fr       */
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
    
    atexit(show_leaks);
    if (argc > 1)
    {
		if (fill_stack(&data, argv) == 0)
        {
            ps_lstclear(&data.stack_a);
            exit (0);
        }
        //añadir aqui el printeo y el free de la lista para ver si lo ha guardado bien
    }
    return (0);
}
