# ifndef	GET_NEXT_LINE_H

# define	GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
int	check_new_line(char *buf);
char	**line_new_line(char *buf, char **line);
char	*ostatok_new_line(char *ostatok);
char	**else_new_line(char *buf, char **line);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *str);

# endif