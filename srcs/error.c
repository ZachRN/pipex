#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int ft_strlen(const char *str)
{
    unsigned int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

void error_out(const char *str)
{
	if (str)
    	write(STDERR_FILENO, str, ft_strlen(str));
	else
		perror("Error: ");
    exit(EXIT_SUCCESS);
}
