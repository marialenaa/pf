#include "../libftprintf.h"

void    ft_parse_treatment(t_data *data, t_buf *buf)
{
 //    printf("\nSTRUCTURE INFOS:\n");
 //	 printf("precision_nb >>>>> %d\n", data->precision_nb);
//     printf("precision >>>>> %d\n", data->precision);
//     printf("zero >>>>> %d\n", data->zero);
//     printf("zerop >>>>> %d\n", data->zero_p);
//    printf("zerow >>>>> %d\n", data->zero_w);
 //    printf("minus >>>>> %d\n", data->minus);
 //     printf("minus >>>>> %d\n", data->minus);
//    printf("len >>>>> %d\n", data->len);
//     printf("conv >>>>> %d\n", data->conv);
//     printf("wildcard >>>>> %d\n", data->wildcard_p);
//     //printf("arg_s >>>>> %s\n", data->arg.arg_s);
//     printf("hexa >>>>> %llu\n", data->arg.ptr);
//    // printf("int >>>>> %d\n", data->arg.arg_i);
 // printf("width >>>>> %d\n", data->width);
//    printf("mod >>>>> %d\n", data->mod);
    if (data->typ == 0)
    {
        if (data->zero_w && data->minus && !data->zero)
            data->zero_w = 0;
        ft_treat_width(data);
        if (data->mod > 0 && data->minus != 0)
        {
            ft_putchar('%', buf);
            ft_print_zero(data->zero_w, buf);
            ft_print_width(data->width, buf);
        }
        if (data->mod > 0 && data->minus == 0)
        {
            ft_print_zero(data->zero_w, buf);
            ft_print_width(data->width, buf);
            ft_putchar('%', buf);
        }
    }
    else if (data->typ == 'c')
        ft_treat_c(data, buf);
    else if (data->typ == 's')
        ft_treat_s(data,buf);
    else if (data->conv == 'i' || data->typ == 'u')
        ft_treat_u_i(data, buf);
    else if (data->conv == 'x')
        ft_treat_x(data,buf);
    else if (data->typ == 'p')
    {
      
     ft_treat_p(data, buf);
    }
    else
    {
        ft_print_width(data->width, buf);
        ft_print_zero(data->width, buf);  
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
