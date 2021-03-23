/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:50:44 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/23 13:28:13 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_find_mod(char *str, va_list args_ptr, t_buf *buf)
{
    t_data data;

    while (*str)
    {
        str = ft_check_mod(str, buf);
        if (*str == '%' && !buf->mod)
        {
            data = ft_data_init();
            str++;
            buf->ptr = ft_get_type(str, &data, buf);
            ft_get_flags(str, &data, buf);
            //printf("tYP%c\n", data.typ);
            if (data.typ)
                ft_parser(args_ptr, &data, buf);
            else
                ft_notype(&data, buf, args_ptr);
            str = buf->ptr;
        }
        else
        {
            buf->mod = 0;
            ft_putchar(*str, &buf->count);
        }
        str++;
    }
}

void *ft_check_mod(char *str, t_buf *buf)
{
    if ((*(str + 1)) && *str == '%')
    {
        //write(1, "**\n", 3);
        if (*(str + 1) == '%')
        {
            buf->mod = 1;
            str++;
        } 
    }
    return (str);
}

int ft_printf(char *str, ...)
{
    va_list args_ptr;
    t_buf buf;
    va_start(args_ptr, str);
    int i;

    i = 0;
    buf = ft_init_buf(str);
    ft_find_mod(str ,args_ptr, &buf);
    va_end(args_ptr);
    return (buf.count);
}
