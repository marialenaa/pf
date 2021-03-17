#include "../libftprintf.h"

void ft_get_arg_s(va_list args_ptr, t_data *data, t_buf *buf)
{
    data->arg.arg_s = va_arg(args_ptr, char *);
    if (data->arg.arg_s == NULL)
    {
            data->arg.arg_s = "(null)";
            data->zero = 1;
    }
    data->len = ft_strlen(data->arg.arg_s);
    ft_treat_s(data,buf);
}

void ft_get_arg_p(va_list args_ptr, t_data *data, t_buf *buf)
{
    data->arg.ptr = va_arg(args_ptr,long long unsigned);
    if (data->arg.ptr == (long long unsigned)NULL)
    {
        data->conv = data->typ;
        data->zero_w = 1;
        data->zero = 1;
        data->len = 2; 
    }
    if (data->arg.ptr > 0)
        ft_ptr_len(data->arg.ptr, &data->len);
    ft_treat_p(data, buf);
}

void ft_get_arg_i_d(va_list args_ptr, t_data *data, t_buf *buf)
{
    data->conv = 'i';
    data->arg.arg_i = va_arg(args_ptr, int);
    if (data->arg.arg_i < 0)
    {
        data->neg = 1;
        if (data->arg.arg_i == -2147483648)
            data->int_min = 1;
        else
            data->arg.arg_i *= -1; 
    }
    if (data->arg.arg_i == 0)
        data->zero = 1;
    data->len = ft_intlen(data->arg.arg_i, data->conv);
    ft_treat_u_i(data, buf);
}

void ft_get_arg_x_u(va_list args_ptr, t_data *data, t_buf *buf)
{
    data->arg.arg_u = va_arg(args_ptr, unsigned int);
    if (data->arg.arg_u == 0)
        data->zero = 1;
    else
        data->len = ft_intlen(data->arg.arg_u, data->conv);
    if (!(data->typ == 'u'))
    {
        data->conv = 'x';
        ft_treat_x(data, buf);
    }
    else
        ft_treat_u_i(data, buf);
}

void ft_notype(va_list args_ptr, t_data *data, t_buf *buf)
 {
    data->arg.arg_i = va_arg(args_ptr, int);
        data->len = 1; 
    if (data->typ == 0)
    {
        if (data->zero_w && data->minus && !data->zero)
            data->zero_w = 0;
        ft_treat_width(data);
        if (data->mod > 0 && data->minus != 0)
        {
            ft_putchar('%', &buf->count);
            ft_print_zero(data->zero_w, buf);
            ft_print_width(data->width, buf);
        }
        if (data->mod > 0 && data->minus == 0)
        {
            ft_print_zero(data->zero_w, buf);
            ft_print_width(data->width, buf);
            ft_putchar('%', &buf->count);
        }
    }
    else
    {
        ft_print_width(data->width, buf);
        ft_print_zero(data->width, buf);  
    }
}