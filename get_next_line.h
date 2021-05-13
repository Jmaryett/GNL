# ifndef	GET_NEXT_LINE_H

# define	GET_NEXT_LINE_H


typedef size_t BUFFER_SIZE;

# define BUFFER_SIZE 32

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>

int get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);


# endif