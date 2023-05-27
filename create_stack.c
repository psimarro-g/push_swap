/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:25:19 by psimarro          #+#    #+#             */
/*   Updated: 2023/05/27 20:10:25 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define START_POINT 1
#define ARRAY_SIZE 45

#include "Libft/inc/libft.h"
#include <fcntl.h>
#include <stdlib.h>

int *fill_array(void)
{
    int *array;
    int i;
    int count;

    count = 0;
    i = - (ARRAY_SIZE/2);
    array = ft_calloc(ARRAY_SIZE + 1, sizeof(int));
    while (count <= ARRAY_SIZE - 1)
    {
        array[count++] = i++;
    }
    return (array);
}

int main(int argc, char **argv)
{
    int file;
    int i;
    int *array;

    i = 0;
    if (argc)
        array = fill_array();
    file = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    i = 0;
    while ( i < 7 )
    {
    int r = rand() % 45 + 1;
    int j;
    
   
    }
}