/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_putnbr_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:11:55 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/24 18:25:23 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(long long int n, t_data *data, t_buf *buf)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, data, buf);
		ft_putnbr(n % 10, data, buf);
	}
	else
		ft_putchar(n + '0', &buf->count);
}

void	ft_conv(long long unsigned nbr, t_data *data, t_buf *buf)
{
	long long unsigned num_base;

	num_base = 16;
	if (nbr >= num_base && !data->zero)
	{
		ft_conv((nbr / num_base), data, buf);
		ft_conv((nbr % num_base), data, buf);
	}
	else if (data->zero && data->conv != 'x')
	{
		ft_putchar('0', &buf->count);
		return ;
	}
	else
	{
		if (data->typ == 'X')
			ft_putchar((HEXA_UPPER[nbr]), &buf->count);
		if (data->typ == 'x')
			ft_putchar((HEXA_LOWER[nbr]), &buf->count);
	}
}
