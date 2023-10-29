/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:25:19 by psimarro          #+#    #+#             */
/*   Updated: 2023/10/29 20:00:59 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

#define START_POINT 1

static int	*fill_array(int size)
{
	int	*array;
	int	i;
	int	count;

	count = 0;
	i = - (size / 2);
	array = ft_calloc(size + 1, sizeof(int));
	if (!array)
		return (NULL);
	while (count < size)
	{
		array[count++] = i++;
	}
	return (array);
}

static int	*shuffle(int *array, int size)
{
	int	i;
	int	temp;
	int	index;

	i = 0;
	srand(time(0));
	while (i < size)
	{
		temp = array[i];
		index = rand() % size;
		array[i++] = array[index];
		array[index] = temp;
	}
	return (array);
}

int	main(int argc, char **argv)
{
	int	file;
	int	i;
	int	*array;
	int	size;

	size = ft_atoi(argv[1]);
	if (argc == 3)
	{
		i = 0;
		array = fill_array(size);
		if (!argc)
			return (0);
		if (array)
		{
			file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			array = shuffle(array, size);
			dup2(file, 1);
			while (i < size)
				ft_printf("%i ", array[i++]);
			close(file);
			free(array);
		}
	}
	return (0);
}
