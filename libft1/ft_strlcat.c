/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:45:24 by zaboumei          #+#    #+#             */
/*   Updated: 2024/10/29 13:18:11 by zaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_of_dst;
	size_t	len_of_src;
	size_t	i;

	len_of_src = ft_strlen(src);
	if (size == 0)
		return (len_of_src);
	len_of_dst = ft_strlen(dst);
	if (size <= len_of_dst)
		return (len_of_src + size);
	i = len_of_dst;
	while (src[i - len_of_dst] && (i < size - 1))
	{
		dst[i] = src[i - len_of_dst];
		i++;
	}
	dst[i] = 0;
	return (len_of_src + len_of_dst);
}
