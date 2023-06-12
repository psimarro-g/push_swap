/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:37:06 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/12 18:00:12 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"

void    ft_free_stack(char **stack)
{
    int i;

    i = 0;
    while (stack[i])
        free(stack[i++]);
    free(stack);
}

void    ft_free_int_stack(int **stack)
{
    int i;

    i = 0;
    while (stack[i])
        free(stack[i++]);
    free(stack);
}
