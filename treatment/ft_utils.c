/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:49:59 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/24 17:38:14 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_ptr_len(long long unsigned nbr, int *len)
{
	while (nbr > 15)
	{
		nbr = nbr / 16;
		*len = *len + 1;
	}
	*len = *len + 2;
}

size_t	ft_intlen(unsigned int nb, char typ)
{
	int i;

	i = 0;
	if ((typ == 'x' || typ == 'X') && nb)
	{
		while (nb > 15)
		{
			nb = nb / 16;
			i++;
		}
		return (i + 1);
	}
	if (nb)
		i++;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int		ft_isflag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*' || c == '%')
		return (1);
	return (0);
}
