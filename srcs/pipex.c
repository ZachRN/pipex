#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <find_paths.h>
#include <ft_split.h>
#include <pipex.h>
#include <fcntl.h>

static void child_process(t_pipex *pipex, int cmd_count, char *argv[])
{
    close(pipex->pipes[0]);
    if (dup2(STDOUT, pipex->pipes[1]) == -1)
        error_out("Error Duplicating Write to STDOUT\n");
    close (pipex->pipes[1]);
    if (!(pipex->cmd_args = ft_split(argv[cmd_count], ' ')))
        error_out("Couldn't Split the Arguements\n");
    if (!(pipex->path = find_paths(pipex->cmd_args[0])))
        error_out("Couldnt find any paths\n");
    //execve(pipex->path, );
    exit(EXIT_SUCCESS);
}

int parent_process(t_pipex *pipex)
{
    close(pipex->pipes[1]);
    if (dup2(STDIN, pipex->pipes[0]) == -1)
        error_out("Error Duplicating Read to STDIN\n");
    close (pipex->pipes[0]);
}

static void start_children(t_pipex *pipex, int arg_count, char *argv[])
{
    int cmd_count;
    int p_id;
    int status;

    cmd_count = 2;
    while (cmd_count < arg_count - 1)
    {
        if (pipe(pipex->pipes) == -1)
            error_out("Pipe Error\n");
        p_id = fork();
        if (p_id == 0)
            child_process(pipex, cmd_count, argv);
        else
            parent_process(pipex);
        cmd_count++;
    }
    while(wait(NULL) > 0)
        continue;
}

int main(int argc, char *argv[])
{
    t_pipex pipex;
    int temp_fd;

    if (argc < 5)
        error_out("Not Enough Arguements\n");
    temp_fd = open(argv[1], O_RDONLY);
    pipex.infile = argv[1];
    if (temp_fd == -1)
        error_out("Infile did not exist\n");
    dup2(STDIN, temp_fd);
    close(temp_fd);
    pipex.outfile = argv[argc - 1];
    start_children(&pipex, argc, argv);
    exit(1);
}