/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:59:19 by mgallizz          #+#    #+#             */
/*   Updated: 2020/12/14 11:26:13 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_make_positive(long **n)
{
	if (**n == -2147483648)
		**n = 2147483648;
	else if (**n == -32768)
		**n = 32768;
	else
		**n *= -1;
}

static int		ft_nb_len_isneg(long *n, int *minus)
{
	int			nb_len;
	long		res;
	long		ncpy;

	ncpy = *n;
	nb_len = 0;
	res = 0;
	if (ncpy < 0)
	{
		nb_len++;
		*minus *= -1;
		ft_make_positive(&n);
	}
	while (ncpy != 0)
	{
		res = ncpy % 10;
		ncpy /= 10;
		nb_len++;
	}
	return (nb_len);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			nb_len;
	int			res;
	int			minus;
	long		ncpy;

	ncpy = (long)n;
	minus = 1;
	nb_len = ft_nb_len_isneg(&ncpy, &minus);
	if (!n)
		nb_len = 1;
	if (!(str = malloc(sizeof(char) * (nb_len + 1))))
		return (NULL);
	str[nb_len] = '\0';
	while (nb_len > 0)
	{
		res = 1;
		res = res * (ncpy % 10);
		str[--nb_len] = (res + '0');
		ncpy /= 10;
	}
	if (minus < 0)
		str[0] = '-';
	return (str);
}
