/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:41:07 by zaboumei          #+#    #+#             */
/*   Updated: 2024/10/28 11:42:42 by zaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_there_here(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strchr(const char *s, int c)
{
	int	is_there;

	is_there = is_there_here(s, c);
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	if (is_there == -1)
		return (NULL);
	return ((char *)(s + is_there));
}
