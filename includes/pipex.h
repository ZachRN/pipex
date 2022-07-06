/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:55:20 by znajda        #+#    #+#                 */
/*   Updated: 2022/07/06 17:14:16 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex {
	char	*infile;
	char	*outfile;
	int		pipes[2];
	char	**cmd_args;
	char	*path;
}				t_pipex;

#endif