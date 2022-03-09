#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int	rd;
	int	i = 0;
	char	c;
	char	*buffer = malloc(9999);

	while ((rd = read(fd, &c, 1) > 0))
	{
		buffer[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	buffer[i] = '\0';
	return (buffer);
}

int main()
{
    int fd;
    fd = open("foo.txt",O_RDONLY);
    char *t;
    t = get_next_line(fd);
    while (t != NULL)
    {
        printf("%s",t);
        t = get_next_line(fd);
    }
    free(t);
    close(fd);

}
