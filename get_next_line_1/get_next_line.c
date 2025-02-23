/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:25:29 by zaboumei          #+#    #+#             */
/*   Updated: 2024/12/04 20:57:56 by zaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	pos_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (ft_strchr(str, '\n') == NULL)
		i = -1;
	return (i);
}

static char	*fill_buffer(int fd, char *what_is_left, char *buffer)
{
	ssize_t	num_byt;
	char	*helper;

	while (1)
	{
		num_byt = read(fd, buffer, BUFFER_SIZE);
		if (num_byt < 0)
			return (free(what_is_left), NULL);
		if (num_byt == 0)
			break ;
		buffer[num_byt] = 0;
		if (what_is_left == NULL)
			what_is_left = ft_strdup("");
		helper = ft_strjoin(what_is_left, buffer);
		if (!helper)
			return (free(what_is_left), what_is_left = NULL, NULL);
		free(what_is_left);
		what_is_left = helper;
		helper = NULL;
		if (ft_strchr(what_is_left, '\n'))
			return (what_is_left);
	}
	return (what_is_left);
}

static char	*line(char **words)
{
	int		pos;
	char	*a_line;
	char	*tmp;

	pos = pos_newline(*words);
	if (pos == -1)
	{
		a_line = ft_substr(*words, 0, ft_strlen(*words));
		free(*words);
		*words = NULL;
		return (a_line);
	}
	a_line = ft_substr(*words, 0, pos + 1);
	tmp = ft_substr(*words, pos + 1, ft_strlen(*words));
	free(*words);
	if (ft_strlen(tmp) == 0)
	{
		free(tmp);
		tmp = NULL;
	}
	*words = tmp;
	return (a_line);
}

char	*get_next_line(int fd)
{
	static char	*what_is_left;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		if (what_is_left != NULL)
			free(what_is_left);
		return (NULL);
	}
	what_is_left = fill_buffer(fd, what_is_left, buffer);
	free(buffer);
	if (what_is_left == NULL)
		return (NULL);
	return (line(&what_is_left));
}
