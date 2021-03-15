/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:34:02 by mgallizz          #+#    #+#             */
/*   Updated: 2020/12/29 12:18:31 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(char *scpy, char c)
{
	int		word;
	int		issep;

	issep = 1;
	word = 0;
	if (!scpy)
		return (0);
	while (*scpy)
	{
		if (issep == 1 && *scpy != c)
			word += 1;
		if (*scpy == c)
			issep = 1;
		if (*scpy != c)
			issep = 0;
		scpy++;
	}
	return (word);
}

static char	**ft_tab(char *s, char c, char **tab, int word)
{
	int				col;
	int				empty;
	unsigned int	index;
	unsigned int	start;

	col = 0;
	index = 0;
	empty = 0;
	while (col < word)
	{
		while (s[index] == c)
			index++;
		start = index;
		while (s[index] != c && s[index] != '\0')
			index++;
		if (!(tab[col] = ft_substr(s, start, index - start)))
		{
			while (empty < col)
				free(tab[empty++]);
			return (NULL);
		}
		col++;
	}
	tab[col] = NULL;
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		word;

	tab = NULL;
	word = ft_word((char *)s, c);
	if (!(tab = malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	if (!(tab = ft_tab((char *)s, c, tab, word)))
	{
		free(tab);
		tab = NULL;
	}
	return (tab);
}
