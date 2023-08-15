/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:51:50 by psimarro          #+#    #+#             */
/*   Updated: 2023/08/15 12:51:23 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/inc/libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	is_sign(const char *str, int *i)
{
	int	neg;

	neg = 1;
	if (str[*i] == '-')
		neg *= -1;
	if (str[*i] == '-' || str[*i] == '+')
		*i += 1;
	return (neg);
}

static int	trim_end(const char *str, int i)
{
	if (!str[i])
		return (-1);
	if (!is_space(str[i]))
		return (0);
	while (is_space(str[i]))
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

static int	ft_checknb(long int nb, int neg)
{
	long int	nl;

	nl = INT_MAX;
	if (nb > nl && neg > 0)
		return (0);
	if (nb > nl + 1 && neg < 0)
		return (0);
	return (1);
}

int	ft_ptr_atoi(const char *str, int *value, int i)
{
	int		neg;
	long	val;

	val = 0;
	while (is_space(str[i]))
		i++;
	if (!str[i])
		return (-1);
	neg = is_sign(str, &i);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		val = (val * 10) + (str[i++] - '0');
	if (!ft_checknb(val, neg))
		return (0);
	*value = neg * (int)val;
	i = trim_end(str, i);
	return (i);
}
