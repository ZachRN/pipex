#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <find_paths.h>
#include <ft_split.h>
#include <pipex.h>
#include <fcntl.h>

int birth_first(t_pipex *pipex, char *argv[])
{
    pipex->in_fd = open(pipex->infile, O_RDONLY);
}
int    birth_children(t_pipex *pipex, int arg_count, char *argv[])
{
    int i;
    int p_id;

    i = 2;
    while (i < arg_count - 1)
    {
        p_id = fork();
        if (p_id == 0)
        {
            if (!(pipex->cmd_args = ft_split(argv[i], ' ')))
                exit(command_error());
            if (!(pipex->path = find_paths(pipex->cmd_args[0])))
                exit(error_paths());
            execut_command();
            exit(1);
        }
    }
}

int main(int argc, char *argv[])
{
    t_pipex *pipex;
    int *pid;

    pipex->path = NULL;
    if (argc < 5)
        return (arguement_error());
    pipex->infile = argv[1];
    pipex->outfile = argv[argc - 1];
    if (pipe(pipex->pipes) == -1)
        exit(pipe_error());
    // pid = fork();
    // if (pid == 0)
    // {
    //     path = find_paths(argv[2]);
    //     printf("%s\n", path);
    // }
    // else if (pid > 0)
    //     printf("This is the parent!\n");
    // if (path)
    //     free(path);
    // while (*envp)
    // {
    //     printf("%s\n", *envp);
    //     envp++;
    // }
   // system("leaks pipex");
   // printf("%s\n%s\n",cmd[0],cmd[1]);
}