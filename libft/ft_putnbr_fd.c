/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:36:14 by mgallizz          #+#    #+#             */
/*   Updated: 2020/12/14 23:41:21 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	cpy;

	if (fd < 0)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		cpy = -n;
	}
	else
		cpy = n;
	if (cpy >= 10)
	{
		ft_putnbr_fd((cpy / 10), fd);
		cpy %= 10;
	}
	cpy += 48;
	write(fd, &cpy, 1);
}
