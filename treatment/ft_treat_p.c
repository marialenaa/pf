/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:49:44 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/24 18:26:04 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_treat_p(t_data *data, t_buf *buf)
{
	if (data->zero)
		ft_treat_zero_p(data, buf);
	else
	{
		ft_treat_width(data);
		data->typ = 'x';
		if (data->minus)
		{
			ft_putchar('0', &buf->count);
			ft_putchar('x', &buf->count);
			ft_conv(data->ptr, data, buf);
			ft_print_width(data->width, buf);
		}
		if (!data->minus)
		{
			ft_print_width(data->width, buf);
			ft_putchar('0', &buf->count);
			ft_putchar('x', &buf->count);
			ft_conv(data->ptr, data, buf);
		}
	}
}

void	ft_treat_zero_p(t_data *data, t_buf *buf)
{
	if (data->minus)
		ft_print_zero_m(data, buf);
	if (!data->minus)
		ft_print_zero_nm(data, buf);
}

void	ft_print_zero_m(t_data *data, t_buf *buf)
{
	ft_putchar('0', &buf->count);
	ft_putchar('x', &buf->count);
	if (data->precision && !data->precision_nb)
		data->len -= 1;
	else
		ft_putchar('0', &buf->count);
	ft_treat_width(data);
	ft_print_width(data->width, buf);
}

void	ft_print_zero_nm(t_data *data, t_buf *buf)
{
	if (data->precision && !data->precision_nb)
	{
		data->len -= 1;
		ft_treat_width(data);
		ft_print_width(data->width, buf);
		ft_putchar('0', &buf->count);
		ft_putchar('x', &buf->count);
	}
	else
	{
		ft_treat_width(data);
		ft_print_width(data->width, buf);
		ft_putchar('0', &buf->count);
		ft_putchar('x', &buf->count);
		ft_putchar('0', &buf->count);
	}
}
