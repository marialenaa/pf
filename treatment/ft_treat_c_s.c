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
    else
        ft_treat_prec_s(data);

    if (!data->minus)
        ft_print_width(data->width, buf);
    ft_putstrl(data->arg.arg_s, data->len, buf);
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

void ft_treat_c(t_data *data, t_buf *buf)
{
    if (!data->minus)
    {
        if (data->width)
        {
            ft_treat_width(data);
            ft_print_width(data->width, buf);
        }
        ft_putchar(data->arg.arg_i, &buf->count);
    }
    if (data->minus)
    {
       ft_putchar(data->arg.arg_i, &buf->count);
       if (data->width)
       {
            ft_treat_width(data);
            ft_print_width(data->width, buf);
       }
    }
}
