/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:49:13 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/19 15:04:57 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_treat_s(t_data *data, t_buf *buf)
{
    if(!data->precision)
    {
        if (data->width && data->width > data->len)
            data->width = data->width - data->len;
        else
            data->width = 0;
    }
    else if (data->precision)
        ft_treat_prec_s(data);
    if (!data->minus)
        ft_print_width(data->width, buf);
   
    ft_putstrl(data->arg_s, data->len, buf);
    if (data->minus)
        ft_print_width(data->width, buf);
}

void ft_treat_prec_s(t_data *data)
{
    if (data->precision_nb)
    {
        if (data->width > data->precision_nb)
        {
            if (data->precision_nb < data->len)
                data->width = data->width - data->precision_nb;
            else
                data->width = data->width - data->len;
        }
        else if (data->width > data->len)
            data->width = data->width - data->len;
        else
            data->width = 0;
        if (data->precision_nb < data->len)
            data->len = data->precision_nb;
        if (data->zero_p && data->zero && data->precision_nb < data->len)
            data->len = 0;
    }
    else
    {
        if (!data->wildcard_p)
            data->len = 0;
    }
}

void ft_treat_c(va_list args_ptr, t_data *data, t_buf *buf)
{
    data->len = 1;
    data->arg_i = va_arg(args_ptr, int);
    if (!data->minus)
    {
        if (data->width)
        {
            ft_treat_width(data);
            ft_print_width(data->width, buf);
        }
        ft_putchar(data->arg_i, &buf->count);
    }
    else if (data->minus)
    {
       ft_putchar(data->arg_i, &buf->count);
       if (data->width)
       {
            ft_treat_width(data);
            ft_print_width(data->width, buf);
       }
    }
}
