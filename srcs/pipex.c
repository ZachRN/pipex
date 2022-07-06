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
	extern char **environ;

    close(pipex->pipes[0]);
    if (dup2(pipex->pipes[1], STDOUT) == -1)
        error_out("Error Duplicating Write to STDOUT\n");
    close (pipex->pipes[1]);
    if (!(pipex->cmd_args = ft_split(argv[cmd_count], ' ')))
        error_out("Couldn't Split the Arguements\n");
    if (!(pipex->path = find_paths(pipex->cmd_args[0])))
        error_out("Couldnt find any paths\n");
    execve(pipex->path, pipex->cmd_args, environ);
    exit(EXIT_SUCCESS);
}

static void parent_process(t_pipex *pipex)
{
    close(pipex->pipes[1]);
    if (dup2(pipex->pipes[0], STDIN) == -1)
        error_out("Error Duplicating Read to STDIN\n");
    close (pipex->pipes[0]);
}

static void final_process(t_pipex *pipex, int argc, char *argv[])
{
	int final_fd;
	int p_id;
	extern char **environ;

	p_id = fork();
	if (p_id == 0)
	{
		final_fd = open(pipex->outfile, (O_TRUNC | O_CREAT | O_RDWR), 0755);
		if (dup2(final_fd, STDOUT) == -1)
			error_out("Error Dupliating to STDOUT\n");
		if (!(pipex->cmd_args = ft_split(argv[argc - 2], ' ')))
        	error_out("Couldn't Split the Arguements\n");
    	if (!(pipex->path = find_paths(pipex->cmd_args[0])))
        	error_out("Couldnt find any paths\n");
		execve(pipex->path, pipex->cmd_args, environ);
		exit(EXIT_SUCCESS);
	}
}

static void start_children(t_pipex *pipex, int arg_count, char *argv[])
{
    int cmd_count;
    int p_id;

    cmd_count = 2;
    while (cmd_count < arg_count - 2)
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
	final_process(pipex, arg_count, argv);
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
    if (dup2(temp_fd, STDIN) == -1)
			error_out("Error Dupliating to STDIN\n");
    close(temp_fd);
    pipex.outfile = argv[argc - 1];
    start_children(&pipex, argc, argv);
	system("leaks -quiet pipex");
    exit(EXIT_SUCCESS);
}