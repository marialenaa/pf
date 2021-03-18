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
        ft_convert_putnbr_base(data->arg.arg_u, data,buf); 
    if (data->minus)
        ft_print_width(data->width, buf);
}

void ft_treat_p(t_data *data, t_buf *buf)
{
    if (data->zero)
    {
        data->arg.arg_s = "(nil)";
        ft_putstrl(data->arg.arg_s, 5, buf);
        return ;
        // if (data->minus)
        // {
        //     ft_putchar('0',&buf->count);
        //     ft_putchar('x',&buf->count);
        //     if (data->arg.ptr != 0)
        //     ft_convert_putnbr_base(data->arg.ptr, data, buf);
        //     else
        //         ft_putchar('0',&buf->count);
        //     ft_treat_width(data);
        //     ft_print_width(data->width, buf);
        // }
        // if (!data->minus)
        // {
        //     ft_treat_width(data);
        //     ft_print_width(data->width, buf); 
        //     ft_putchar('0',&buf->count);
        //     ft_putchar('x',&buf->count);
        //     if (data->arg.ptr != 0)
        //         ft_convert_putnbr_base(data->arg.ptr, data, buf);
        //     else
        //         ft_putchar('0',&buf->count);
        // }
    }
    else
    {
        ft_treat_width(data);
        data->typ = 'x';
        if (data->minus)
        {
            ft_putchar('0',&buf->count);
            ft_putchar('x',&buf->count);
            ft_convert_putnbr_base(data->arg.ptr, data, buf);
            ft_print_width(data->width, buf); 
        }
        if (!data->minus)
        {
            ft_print_width(data->width, buf);
            ft_putchar('0',&buf->count);
            ft_putchar('x',&buf->count);
            ft_convert_putnbr_base(data->arg.ptr, data, buf);
        }
    }
}
