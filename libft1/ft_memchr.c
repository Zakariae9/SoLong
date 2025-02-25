/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:39:10 by zaboumei          #+#    #+#             */
/*   Updated: 2024/10/28 17:15:11 by zaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_equal(char s, int c)
{
	return (s == c);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*helper;
	size_t			i;

	helper = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (is_equal(helper[i], c))
			return (helper + i);
		i++;
	}
	return (NULL);
}
