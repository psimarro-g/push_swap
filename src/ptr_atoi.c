/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:51:50 by psimarro          #+#    #+#             */
/*   Updated: 2023/06/14 19:22:32 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/inc/libft.h"

static unsigned long long int	ft_checknb(unsigned long long int nb, int neg)
{
	unsigned long long int	nl;

	nl = INT_MAX;
	if (nb > nl && neg > 0)
		return (0);
	if (nb > nl + 1 && neg < 0)
		return (0);
	return (1);
}

int	*ft_ptr_atoi(const char *str)
{
	int						i;
	int						neg;
	unsigned long long int	val;
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
	if (str[i] != '\t' && str[i] != '\n' && str[i] != '\v' && \
			str[i] != '\f' && str[i] != '\r' && str[i] != ' ')
        return (NULL);
	if (!ft_checknb(val, neg))
		return (NULL);
    rtn = ft_calloc(1, sizeof(int));
    *rtn = neg * (int)val;
	return (rtn);
}
