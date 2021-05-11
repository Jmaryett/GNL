#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int		i = 0; int j = 0;
	char	*buf;
	int		n_read;
	size_t	line_len;
	static char	*ostatok;

	if (fd == -1 || !line)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	n_read = read(fd, buf, BUFFER_SIZE);
	while (buf[i])
	{
		if (buf[i] == '/n')
		{
			while (buf[j] != '/n')
				line[j++] = buf[j++];
		}
		i++;
	}
	
	buf[n_read] = '\0';

	/* if (.. == '/n')
		return (1);
	else
		return (0);

	free (fd); */
}