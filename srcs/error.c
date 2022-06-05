#include <unistd.h>
#include <stdlib.h>

int arguement_error()
{
    write(1, "Not Enough Arguements\n", 22);
    return (-1);
}

char    error_paths()
{
    write(1, "Error something has gone wrong with the paths\n", 46);
    return (NULL);
}

int pipe_error()
{
    write(1, "Error setting up the Pipes\n", 27);
    return (-1);
}

int command_error()
{
    write(1, "Error splitting the command arguements\n", 39);
    return (-1);
}
