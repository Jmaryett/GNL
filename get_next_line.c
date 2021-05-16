#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char	*buf;
	static	char	*ostatok;
	int		n_read = 0;
	int		i;
	int len;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || read(fd, buf, 0) < 0)
		return (-1);
	if (ostatok && ((i = check_new_line(ostatok)) != -1))
	{
		free(buf);
		line = line_new_line(ostatok, line);
		len = ft_strlen(ostatok + i) + 1;
		ostatok = ft_memmove(ostatok, ostatok + i, len);
		return (1);
	}
	while ((n_read = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[n_read] = '\0';
			ostatok = buf;
		}
	return (1);
}