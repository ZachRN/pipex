/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:54:48 by znajda        #+#    #+#                 */
/*   Updated: 2022/07/06 15:55:07 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

/*Used to compare Strings to see if they are the same up to a certain point
currently being used to determine the path= variable*/
int		ft_strncmp(const char *s1, const char *s2, size_t len);

#endif