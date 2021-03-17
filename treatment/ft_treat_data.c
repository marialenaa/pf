#include "../libftprintf.h"

void ft_treat_wildcard(t_data *data, va_list args_ptr)
{
    if (data->wildcard_w)
    {
        data->width = va_arg(args_ptr, int);
       if (data->width < 0)
        {
            data->width = data->width * (-1);
            data->zero_w = 0;
            if (data->typ != 'p')
                data->minus = 1;
        }
    }
    if (data->wildcard_p)
    {
        data->precision_nb = va_arg(args_ptr, int);
        if (data->precision_nb == 0)
            data->wildcard_p = 0;
        if (data->precision_nb < 0)
        {
             data->precision_nb = 0;
             if (data->typ == 's') 
                data->precision = 0;
        }
    }
}


void    ft_treat_width(t_data *data)
{
    if (data->neg)
        ft_treat_neg(data);
    else if (!data->zero)
    {
        if(data->precision && data->zero_p)
            data->zero_p = 0;
        if (data->zero_w)
        {
            data->zero_w = data->width - data->len;
            data->width = 0;
        }
        if (data->typ == 'p' && !data->zero)
        {
             data->width = data->width - (data->len + 1);
             return ;
        }
        if (data->width < data->len)
            data->width = 0;
        else
            data->width = data->width - data->len;
    }
    else
    {
        
        if (data->typ == 'p' && !data->zero)
                data->width = data->width - data->len;
        else
            data->width = data->width - (data->len + 1);
    }
}

void    ft_treat_prec(t_data *data)
{
    data->zero_w = 0;
    if (data->precision_nb > data->len)
    {
        data->zero_p = data->precision_nb - data->len;
        if (data->width)
        {
             if (data->precision_nb >= data->width)
            data->width = 0;
        else
            data->width = data->width - data->precision_nb;
        }
    }
    else
    {
        data->width = data->width - data->len;
        data->zero_p = 0;
    }
}

void    ft_treat_arg_zero(t_data *data)
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
    if (data->width && data->precision_nb)
    {
        data->zero_w = 0;
        data->zero_p = data->precision_nb;
        data->width = data->width - data->precision_nb;
    }
    if (!data->width)
    {
        if (data->typ == 'p' || data->conv == 'x')
        {
             if (data->precision && data->zero_p)
                data->zero_p = 0;
        }
        if (data->conv == 'i' || data->typ == 'u')
        {
            if (data->precision && (data->zero_p || data->zero_w))
            {
                data->zero_p = 0;
                data->zero_w = 0;
                data->len = 0;
            }
        }
        if (data->wildcard_p)
            data->zero_p = 1;
        if (data->precision_nb)
            data->zero_p = data->precision_nb;
    } 
}

void    ft_treat_flag(t_data *data)
{
    if (!data->zero)
    {
        if ((!data->precision || !data->precision_nb))
            ft_treat_width(data);
        else
            ft_treat_prec(data);
        if (data->zero_w && data->minus && !data->zero)
            data->zero_w = 0;
        if (data->neg && data->width)
            data->width = data->width -= 1;
    }
}

void ft_treat_neg(t_data * data)
{
    if (data->zero_w)
    {
        data->zero_w = data->width - data->len - 1;
        data->width = 0;
    }
    else
    {
        if (data->conv == 'p')
            data->width = data->width - (data->len + 1);
        else
            data->width = data->width - (data->len);
    }
}
