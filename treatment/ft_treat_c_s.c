#include "../libftprintf.h"

void ft_treat_s(t_data *store_data, t_buf *buf)
{
    if(!store_data->precision)
    {
        if (store_data->width && store_data->width > store_data->len)
            store_data->width = store_data->width - store_data->len;
        else
            store_data->width = 0;
    }
    else
        ft_treat_prec_s(store_data);

    if (!store_data->minus)
        ft_print_width(store_data->width, buf);
    ft_putstrl(store_data->arg.arg_s, store_data->len, buf);
    if (store_data->minus)
        ft_print_width(store_data->width, buf);
}

void ft_treat_prec_s(t_data *store_data)
{
    if (store_data->precision_nb)
    {
        if (store_data->width > store_data->precision_nb)
        {
            if (store_data->precision_nb < store_data->len)
                store_data->width = store_data->width - store_data->precision_nb;
            else
                store_data->width = store_data->width - store_data->len;
        }
        else if (store_data->width > store_data->len)
            store_data->width = store_data->width - store_data->len;
        else
            store_data->width = 0;
        if (store_data->precision_nb < store_data->len)
            store_data->len = store_data->precision_nb;
        if (store_data->zero_p && store_data->zero && store_data->precision_nb < store_data->len)
            store_data->len = 0;
    }
    else
    {
        if (!store_data->wildcard_p)
        store_data->len = 0;
    }
}

void ft_treat_c(t_data *store_data, t_buf *buf)
{
    if (!store_data->minus)
    {
        if (store_data->width)
        {
            ft_treat_width(store_data);
            ft_print_width(store_data->width, buf);
        }
        ft_putchar(store_data->arg.arg_i, buf);
    }
    if (store_data->minus)
    {
       ft_putchar(store_data->arg.arg_i, buf);
       if (store_data->width)
       {
            ft_treat_width(store_data);
            ft_print_width(store_data->width, buf);
       }
    }
}
