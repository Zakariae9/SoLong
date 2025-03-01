#include "so_long.h"

char	*join(char **s)
{
	int (len) = 0;
	int (i) = -1;
	int (j) = 0;
	int (k) = 0;
	while (s[++i])
	{
		j = 0;
		while (s[i][j++])
			len++;
	}
	char *(str) = malloc(len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		j = 0;
		while (s[i][j])
			str[k++] = s[i][j++];
	}
	str[k] = '\0';
	return (str);
}