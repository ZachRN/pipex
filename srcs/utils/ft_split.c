/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 12:01:49 by znajda        #+#    #+#                 */
/*   Updated: 2021/05/13 15:42:50 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	free_my_lines(char **strsplit, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(strsplit[i]);
		i++;
	}
	free(strsplit);
}

static char	**wordinput(char const *s, int pos[2], int line, char **strsplit)
{
	int	i;

	i = 0;
	strsplit[line] = (char *)malloc((pos[0] - pos[1] + 2) * sizeof(char *));
	if (strsplit[line] == NULL)
	{
		free_my_lines(strsplit, line);
		return (NULL);
	}
	while (pos[1] < pos[0])
	{
		strsplit[line][i] = s[pos[1]];
		pos[1]++;
		i++;
	}
	strsplit[line][i] = '\0';
	return (&strsplit[0]);
}

static char	**wordfill(char const *s, char c, char **strsplit)
{
	int	pos[2];
	int	line;

	pos[0] = 0;
	line = 0;
	while (s[pos[0]] == c && s[pos[0]] != '\0')
		pos[0] += 1;
	pos[1] = pos[0];
	while (s[pos[0]] != '\0')
	{
		pos[0]++;
		if ((s[pos[0]] == c || s[pos[0]] == '\0') && s[pos[0] - 1] != c)
		{
			wordinput(s, pos, line, strsplit);
			if (strsplit == NULL)
				return (NULL);
			while (s[pos[0]] == c && c != '\0')
				pos[0]++;
			pos[1] = pos[0];
			line++;
		}
	}
	return (&strsplit[0]);
}

static int	word_amount(const char *s, char c)
{
	int		pos;
	int		words;

	pos = 0;
	words = 0;
	while (s[pos] == c && s[pos] != '\0')
		pos++;
	while (s[pos] != '\0')
	{
		pos++;
		if ((s[pos] == c || s[pos] == '\0') && s[pos - 1] != c)
			words++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**strsplit;
	int		words;

	if (!s)
		return (NULL);
	words = word_amount(s, c);
	strsplit = (char **)malloc((words + 1) * sizeof(char *));
	if (strsplit == NULL)
		return (NULL);
	strsplit[words] = NULL;
	wordfill(s, c, strsplit);
	if (strsplit == NULL)
		return (NULL);
	return (&strsplit[0]);
}
