#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex {
    char *infile;
    char *outfile;
    int pipes[2];
    char    **cmd_args;
    char    *path;
    int     in_fd;
    int     out_fd;
}               t_pipex;

# define STDIN 0
# define STDOUT 1

#endif