/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:02:28 by psimarro          #+#    #+#             */
/*   Updated: 2023/05/30 21:00:21 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t		i;
	size_t		rtn;

	i = 1;
	rtn = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		rtn++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			rtn++;
		i++;
	}
	return (rtn);
    //asignar variable al size del stack
}

static int  get_word(char const *s, size_t *pos, char c)
{
	int         *rtn;
	size_t		beg;
	size_t		end;

	beg = *pos;
	while (s[beg] == c)
		beg++;
	end = beg;
	while (s[end] != c && s[end] != '\0')
		end++;
	if (beg == end)
		return (NULL);
    *pos = end;
    rtn = ft_atoi(s[*pos]);
	return (rtn);
}

int	**ft_int_split(char const *s, char c)
{
	int		**rtn;
	size_t	nb_word;
	size_t	cur_word;
	size_t	j;

	if (s == (char *) NULL)
		return ((int **) NULL);
	nb_word = count_word(s, c);
	rtn = (int **)malloc(sizeof(int *) * (nb_word + 1));
	if (rtn == NULL)
		return ((int **) NULL);
	rtn[nb_word] = NULL;
	cur_word = 0;
	j = 0;
	while (cur_word < nb_word)
	{
		rtn[cur_word] = get_word(s, &j, c);
		if (rtn[cur_word] == NULL)
		{
			//free_stack(rtn);
			return (NULL);
		}
		cur_word++;
	}
	return (rtn);
}
