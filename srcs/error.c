/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:52:42 by znajda        #+#    #+#                 */
/*   Updated: 2022/07/06 17:14:59 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static	int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error_out(const char *str)
{
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	else
		perror("Error: ");
	exit(EXIT_FAILURE);
}
