#include <unistd.h>
#include <stdlib.h>
#include <ft_split.h>
#include <ft_strjoin.h>
#include <utils.h>
#include <error.h>
#include <free.h>

static char    **get_environ_path()
{
    extern char **environ;
    char **path;

    path = NULL;
    while (*environ && !path)
    {
        if (!ft_strncmp(*environ, "PATH=", 5))
            path = ft_split(*environ + 5, ':');
        environ++;
    }
    return (path);
}

static char    *loop_through_env(char **path, char *command)
{
    char    *store_command;
    char    *possible_env_path;
    int i;

    i = 0;
    store_command = ft_strjoin("/", command);
    while (*(path + i))
    {
        possible_env_path = ft_strjoin(*(path + i), store_command);
        if (access(possible_env_path, F_OK) == 0)
        {
            if (store_command)
                free(store_command);
            return (possible_env_path);
        }
        else
            free(possible_env_path);
        i++;
        possible_env_path = NULL;
    }
    if (store_command)
        free(store_command);
    return (possible_env_path);
}

static char    *find_possible_path(char **path, char *command)
{
    char    *possible_env_path;

    possible_env_path = NULL;
    if (!(possible_env_path = loop_through_env(path, command)))
        error_out("Command not found\n");
    if (path)
        free_paths(path);
    return (possible_env_path);
}

char *find_paths(char *command)
{
    char **path;
    char *possible_path;
    int i;

    i = 0;
    if (!(path = get_environ_path()))
        error_out("Error finding paths\n");
    possible_path = find_possible_path(path, command);
    if (possible_path)
        return (possible_path);
    return (NULL);
}