/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:47:03 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/24 16:12:27 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_get_arg_s(va_list args_ptr, t_data *data, t_buf *buf)
{
	data->arg_s = va_arg(args_ptr, char *);
	if (data->arg_s == NULL)
	{
		data->arg_s = "(null)";
		data->zero = 1;
		data->len = 6;
	}
	else
		data->len = ft_strlen(data->arg_s);
	ft_treat_wildcard(data);
	ft_treat_s(data, buf);
}

void	ft_get_arg_p(va_list args_ptr, t_data *data, t_buf *buf)
{
	data->ptr = va_arg(args_ptr, long long unsigned);
	if (data->ptr == (long long unsigned)NULL)
	{
		data->conv = data->typ;
		data->zero_w = 1;
		data->zero = 1;
		data->len = 2;
	}
	if (data->ptr > 0)
		ft_ptr_len(data->ptr, &data->len);
	ft_treat_wildcard(data);
	if (!data->width)
	{
		if (data->precision && data->zero_p)
			data->zero_p = 0;
	}
	ft_treat_p(data, buf);
}

void	ft_get_arg_i_d(va_list args_ptr, t_data *data, t_buf *buf)
{
	data->conv = 'i';
	data->arg_i = va_arg(args_ptr, int);
	if (data->arg_i < 0)
	{
		data->neg = 1;
		if (data->arg_i == -2147483648)
			data->int_min = 1;
		else
			data->arg_i *= -1;
	}
	if (data->arg_i == 0)
		data->zero = 1;
	ft_treat_wildcard(data);
	data->len = ft_intlen(data->arg_i, data->conv);
	ft_treat_u_i(data, buf);
}

void	ft_get_arg_x_u(va_list args_ptr, t_data *data, t_buf *buf)
{
	data->arg_u = va_arg(args_ptr, unsigned int);
	if (data->arg_u == 0)
		data->zero = 1;
	else
		data->len = ft_intlen(data->arg_u, data->typ);
	ft_treat_wildcard(data);
	if (!(data->typ == 'u'))
	{
		data->conv = 'x';
		if (data->precision && data->zero_p && !data->width)
			data->zero_p = 0;
		ft_treat_x(data, buf);
	}
	else if (data->typ == 'u')
	{
		if (!data->width && data->precision && (data->zero_p || data->zero_w))
		{
			data->zero_p = 0;
			data->zero_w = 0;
		}
		ft_treat_u_i(data, buf);
	}
}

void	ft_notype_print(t_data *data, t_buf *buf, va_list args_ptr)
{
	data->len = 1;
	ft_get_wildcard(data, args_ptr);
	ft_treat_wildcard(data);
	if (data->zero_w && data->minus)
		data->zero_w = 0;
	ft_treat_width(data);
	if (data->minus != 0)
	{
		ft_putchar('%', &buf->count);
		ft_print_zero(data->zero_w, buf);
		ft_print_width(data->width, buf);
	}
	if (data->minus == 0)
	{
		ft_print_zero(data->zero_w, buf);
		ft_print_width(data->width, buf);
		ft_putchar('%', &buf->count);
	}
	buf->mod = 0;
}
