/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:07:47 by zaboumei          #+#    #+#             */
/*   Updated: 2024/10/29 10:16:48 by zaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
		if ((nptr[i] == '-') || (nptr[i] == '+'))
			return (0);
	}
	while (ft_isdigit((nptr[i])))
	{
		num *= (10);
		num += (nptr[i] - 48);
		i++;
	}
	return (num * sign);
}
