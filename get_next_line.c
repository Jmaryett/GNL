#include "get_next_line.h"

char	**what_left(char *ostatok, char **line)
{
	int	i = 0;

	while(ostatok[i])
	{
		line[i] = ostatok[i];
		i++;
	}
	i = 0;
	while(ostatok[i])
	{
		free(ostatok[i]);
		i++;
	}
	return (line);
}

char	**check_new_line(char *ostatok, char **line)
{
	int		i = 0;
	int		j = 0;

	while (ostatok[i])
	{
		if (ostatok[i] == '/n')
		{
			while (ostatok[j++] != '/n')
				line[j] = ostatok[j];
			j = 0;
			while (ostatok[j] != '/n')
			{
				free(ostatok[j]);
				j++;
			}
		}
		i++;
	}
	return (line);
}

int get_next_line(int fd, char **line)
{
	static	char	*ostatok;
	int		n_read;
	size_t	line_len;

	if (fd == -1 || !line)
		return (-1);
	ostatok = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ostatok)
		return (-1);
	n_read = read(fd, ostatok, BUFFER_SIZE);
	if (line == check_new_line(ostatok, line))
		return (1);
	else
	{
		line = what_left(ostatok, line);
		return (0);
	}
	ostatok[n_read] = '\0';
}
