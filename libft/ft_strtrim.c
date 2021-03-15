/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:51:40 by mgallizz          #+#    #+#             */
/*   Updated: 2020/12/07 09:32:01 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isinset(const char *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	if (s1 && set)
	{
		end = ft_strlen(s1);
		while (s1[start] && ft_isinset(set, s1[start]))
			start++;
		while (start < end && ft_isinset(set, s1[end - 1]))
			end--;
		if (!(cpy = malloc(sizeof(char) * ((end - start) + 1))))
			return (NULL);
		while (start < end)
			cpy[i++] = s1[start++];
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
