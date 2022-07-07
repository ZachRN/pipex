/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:47:11 by znajda        #+#    #+#                 */
/*   Updated: 2022/07/07 16:01:29 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_paths(char *paths[])
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		if (paths[i])
			free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
	paths = NULL;
}
