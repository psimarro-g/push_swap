/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:51:50 by psimarro          #+#    #+#             */
/*   Updated: 2023/05/30 21:05:46 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"

long int	ft_checknb(long int nb, int neg)
{
	long int	nl;

	nl = 9223372036854775807;
	if (nb > nl && neg > 0)
		return (-1); //esto creo que es para el overflow
	if (nb > nl + 1 && neg < 0)
		return (0);
	return (nb);
}

int	*ft_ptr_atoi(const char *str)
{
	int						i;
	int						neg;
	long int			    val;
    int                     *rtn;

	i = 0;
	neg = 1;
	val = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
    if (!(str[i] >= '0' && str[i] <= '9'))
        return (NULL);
	while (str[i] >= '0' && str[i] <= '9')
		val = (val * 10) + (str[i++] - '0');
	val = ft_checknb(val, neg);
    rtn = ft_calloc(1, sizeof(int));
    *rtn = neg * (int)val; //aqui revisar numero positivo o negativo, si hace falta multiplicar o no
	return (rtn);
}

/*
arreglar signos por el unsigned que habia
checkear max y min int  y devolver null
*/