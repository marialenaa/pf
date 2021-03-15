#include "../libftprintf.h"

void ft_treat_x(t_data *store_data, t_buf *buf)
{
    if (store_data->width || store_data->precision)
        ft_treat_flag(store_data);
    if (store_data->zero)
        ft_treat_arg_zero(store_data);
    if (!store_data->minus)
        ft_print_width(store_data->width, buf);
    if (store_data->neg)
        ft_putchar('-', buf);
    ft_print_zero(store_data->zero_p, buf);
    ft_print_zero(store_data->zero_w,buf);
    if (!(store_data->precision && store_data->zero))
        ft_convert_putnbr_base(store_data->arg.arg_u, store_data,buf); 
    if (store_data->minus)
        ft_print_width(store_data->width, buf);
}

void ft_treat_p(t_data *store_data, t_buf *buf)
{
    if (store_data->zero)
    {
        store_data->arg.arg_s = "(nil)";
        if (store_data->minus)
        {
            ft_putchar('0',buf);
            ft_putchar('x',buf);
            if (store_data->arg.ptr != 0)
            ft_convert_putnbr_base(store_data->arg.ptr, store_data, buf);
            else
                ft_putchar('0',buf);
            ft_treat_width(store_data);
            ft_print_width(store_data->width, buf);
        }
        if (!store_data->minus)
        {
            ft_treat_width(store_data);
            ft_print_width(store_data->width, buf); 
            ft_putchar('0',buf);
            ft_putchar('x',buf);
            if (store_data->arg.ptr != 0)
                ft_convert_putnbr_base(store_data->arg.ptr, store_data, buf);
            else
                ft_putchar('0',buf);
        }
    }
    else
    {
        ft_treat_width(store_data);
        store_data->typ = 'x';
        if (store_data->minus)
        {
            ft_putchar('0',buf);
            ft_putchar('x',buf);
            ft_convert_putnbr_base(store_data->arg.ptr, store_data, buf);
            ft_print_width(store_data->width, buf); 
        }
        if (!store_data->minus)
        {
            ft_print_width(store_data->width, buf);
            ft_putchar('0',buf);
            ft_putchar('x',buf);
            ft_convert_putnbr_base(store_data->arg.ptr, store_data, buf);
        }
       
    }
}