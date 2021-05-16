#include "get_next_line.h"

int	check_new_line(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (-1);
}

char	**line_new_line(char *buf, char **line)
{
	while (*buf != '\n')
	{
		**line = *buf;
		line++;
		buf++;
	}
	**line = '\0';
	return (line);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

char	**else_new_line(char *buf, char **line)
{
	while (*buf)
	{
		**line = *buf;
		line++;
		buf++;
	}
	**line = '\0';
	return (line);
}
