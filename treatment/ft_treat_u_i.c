/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:49:35 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/23 13:39:09 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_treat_u_i(t_data *data, t_buf *buf)
{
    long long int arg;

    if (data->conv == 'i')
        arg = data->arg_i;
    else
        arg = data->arg_u;
    if (data->precision_nb < 0 && data->zero)
        data->precision_nb = 1;
    if (data->precision_nb < 0 && !data->zero)
        data->precision_nb = 0;
    if (!data->width && !data->precision)
        data->zero_w = 0;
    if (data->width || data->precision)
        ft_treat_flag(data);
    if (data->zero)
        ft_treat_arg_zero(data);
    if (!data->minus)
        ft_print_width(data->width, buf);
    if (data->neg)
         ft_putchar('-', &buf->count);
    ft_print_zero(data->zero_p, buf);
    ft_print_zero(data->zero_w, buf);
    if (!(data->precision && data->zero) && !data->int_min)
        ft_putnbr(arg, data, buf);
    if (data->int_min)
        ft_putstrl("2147483648",10, buf);
    if (data->minus)
        ft_print_width(data->width, buf);
}

void    ft_treat_arg_zero(t_data *data)
{
   // printf("p\n");
   if (data->precision)
       data->zero_w = 0;
	ft_width_notprec_nb(data);
	if (data->width && data->precision_nb)
	{
		data->zero_w = 0;
		data->zero_p = data->precision_nb;
		data->width = data->width - data->precision_nb;
	}
	if (!data->width)
	{
		if (data->wildcard_p)
			data->zero_p = 1;
		if (data->precision_nb)
			data->zero_p = data->precision_nb;
		if (data->typ == 'i' || data->typ == 'd')
		{
			if (data->zero_p && !data->precision_nb)
			data->zero_p = 0;
		}
	} 
}

void ft_width_notprec_nb(t_data *data)
{
    if (data->width && !data->precision_nb)
    {
        if (data->zero_w)
        {
                data->zero_w = data->width - 1;
                data->width = 0;
        }
        if (!data->zero_w && !data->precision)
                data->width = data->width - 1;
        if (data->precision)
        {
            data->zero_w = 0;
            data->zero_p = 0;
            if (data->wildcard_p)
                data->zero_p = 1;
        }
    }
}