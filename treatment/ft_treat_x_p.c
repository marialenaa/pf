/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:49:44 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/23 12:18:35 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_treat_x(t_data *data, t_buf *buf)
{
    if (data->width || data->precision)
        ft_treat_flag(data);
    if (data->zero)
        ft_treat_arg_zero(data);
    if (!data->minus)
        ft_print_width(data->width, buf);
    if (data->neg)
        ft_putchar('-', &buf->count);
    ft_print_zero(data->zero_p, buf);
    ft_print_zero(data->zero_w,buf);
    if (!(data->precision && data->zero))
        ft_convert_putnbr_base(data->arg_u, data,buf); 
    if (data->minus)
        ft_print_width(data->width, buf);
}


void ft_treat_p(t_data *data, t_buf *buf)
{
    if (data->zero)
        ft_treat_zero_p(data, buf);
    else
    {
        ft_treat_width(data);
        data->typ = 'x';
        if (data->minus)
        {
            ft_putchar('0',&buf->count);
            ft_putchar('x',&buf->count);
            ft_convert_putnbr_base(data->ptr, data, buf);
            ft_print_width(data->width, buf); 
        }
        if (!data->minus)
        {
            ft_print_width(data->width, buf);
            ft_putchar('0',&buf->count);
            ft_putchar('x',&buf->count);
            ft_convert_putnbr_base(data->ptr, data, buf);
        }
    }
}

void ft_treat_zero_p(t_data *data, t_buf *buf)
{
    if (data->minus)
        ft_print_zero_m(data,buf);
    if (!data->minus)
        ft_print_zero_nm(data,buf);
}

void ft_print_zero_m(t_data *data, t_buf *buf)
{
    ft_putchar('0',&buf->count);
        ft_putchar('x',&buf->count);
        if (data->precision && !data->precision_nb)
        {
           // printf("len%d\n", data->len);
               data->len -= 1;
        }
        else
             ft_putchar('0',&buf->count);
        ft_treat_width(data);
        ft_print_width(data->width, buf);
}

void ft_print_zero_nm(t_data *data, t_buf *buf)
{
    if (data->precision && !data->precision_nb)
        {
            data->len -= 1;
            ft_treat_width(data);
            ft_print_width(data->width, buf);
            ft_putchar('0',&buf->count);
            ft_putchar('x',&buf->count);
        }
        else
        {
            ft_treat_width(data);
            ft_print_width(data->width, buf);
            ft_putchar('0',&buf->count);
            ft_putchar('x',&buf->count);
            ft_putchar('0',&buf->count);
        }
}
