#include <unistd.h>
#include <stdlib.h>

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
    write(STDERR_FILENO, str, ft_strlen(str));
    exit(EXIT_FAILURE);
}
