/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:19:27 by zaboumei          #+#    #+#             */
/*   Updated: 2024/11/18 18:14:58 by zaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_array_revesd(unsigned char *d, unsigned char *s, size_t n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		d[i] = s[i];
		i--;
	}
}

static void	fill_array(unsigned char *d, unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	if (d < s)
		fill_array(d, s, n);
	else
		fill_array_revesd(d, s, n);
	return (dest);
}
