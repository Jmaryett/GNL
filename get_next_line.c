#include "get_next_line.h"

static int	ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == (char)ch)
			return (i);
		i++;
	}
	return (-1);
}

static int	error_case(char *buf)
{
	if (buf)
		free(buf);
	return (-1);
}

static int	line_new_line(char *ostatok, int i, char **line)
{
	size_t	len;

	*line = ft_substr(ostatok, 0, i);
	i++;
	len = ft_strlen(ostatok + i) + 1;
	ostatok = ft_memmove(ostatok, ostatok + i, len);
	return (1);
}

static char	*join_from_buf(char *ostatok, char *buf)
{
	char	*res;
	int		i;
	int		len1;

	i = 0;
	if (!ostatok)
		return (ft_strdup(buf));
	if (!buf)
		return (NULL);
	len1 = ft_strlen(ostatok);
	res = (char *)malloc(sizeof(char) * (len1 + ft_strlen(buf) + 1));
	if (!res)
		return (NULL);
	while (ostatok[i])
	{
		res[i] = ostatok[i];
		i++;
	}
	free (ostatok);
	i = -1;
	while (buf[++i])
		res[len1 + i] = buf[i];
	res[len1 + i] = '\0';
	return (res);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*ostatok;
	int		i;
	size_t n_read;

	i = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || read(fd, buf, 0) < 0)
		return (error_case(buf));
	if (ostatok && (i = ft_strchr(ostatok, '\n')) != -1)
	{
		free(buf);
		return(line_new_line(ostatok, i, line));
	}
	while ((n_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n_read] = '\0';
		ostatok = join_from_buf(ostatok, buf);
		if (ostatok && (i = ft_strchr(ostatok, '\n')) != -1)
		{
			free(buf);
			return(line_new_line(ostatok, i, line));
		}
	}
	end_case(&buf, &ostatok, line);
	return (0);
}