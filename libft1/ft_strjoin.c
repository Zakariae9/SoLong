/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:20:02 by zaboumei          #+#    #+#             */
/*   Updated: 2024/10/31 10:20:10 by zaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_str(char const *str1, char const *str2, char *buffer)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		*buffer = str1[i];
		i++;
		buffer++;
	}
	i = 0;
	while (str2[i])
	{
		*buffer = str2[i];
		buffer++;
		i++;
	}
	*buffer = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(len);
	if (new_str == NULL)
		return (NULL);
	fill_str(s1, s2, new_str);
	return (new_str);
}
