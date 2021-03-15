#include "../libftprintf.h"

void    ft_parse_treatment(t_data *store_data, t_buf *buf)
{
 //    printf("\nSTRUCTURE INFOS:\n");
 //	 printf("precision_nb >>>>> %d\n", store_data->precision_nb);
//     printf("precision >>>>> %d\n", store_data->precision);
//     printf("zero >>>>> %d\n", store_data->zero);
//     printf("zerop >>>>> %d\n", store_data->zero_p);
//    printf("zerow >>>>> %d\n", store_data->zero_w);
 //    printf("minus >>>>> %d\n", store_data->minus);
 //     printf("minus >>>>> %d\n", store_data->minus);
//    printf("len >>>>> %d\n", store_data->len);
//     printf("conv >>>>> %d\n", store_data->conv);
//     printf("wildcard >>>>> %d\n", store_data->wildcard_p);
//     //printf("arg_s >>>>> %s\n", store_data->arg.arg_s);
//     printf("hexa >>>>> %llu\n", store_data->arg.ptr);
//    // printf("int >>>>> %d\n", store_data->arg.arg_i);
 // printf("width >>>>> %d\n", store_data->width);
//    printf("mod >>>>> %d\n", store_data->mod);
    if (store_data->typ == 0)
    {
        if (store_data->zero_w && store_data->minus && !store_data->zero)
            store_data->zero_w = 0;
        ft_treat_width(store_data);
        if (store_data->mod > 0 && store_data->minus != 0)
        {
            ft_putchar('%', buf);
            ft_print_zero(store_data->zero_w, buf);
            ft_print_width(store_data->width, buf);
        }
        if (store_data->mod > 0 && store_data->minus == 0)
        {
            ft_print_zero(store_data->zero_w, buf);
            ft_print_width(store_data->width, buf);
            ft_putchar('%', buf);
        }
    }
    else if (store_data->typ == 'c')
        ft_treat_c(store_data, buf);
    else if (store_data->typ == 's')
        ft_treat_s(store_data,buf);
    else if (store_data->conv == 'i' || store_data->typ == 'u')
        ft_treat_u_i(store_data, buf);
    else if (store_data->conv == 'x')
        ft_treat_x(store_data,buf);
    else if (store_data->typ == 'p')
    {
      
     ft_treat_p(store_data, buf);
    }
    else
    {
        ft_print_width(store_data->width, buf);
        ft_print_zero(store_data->width, buf);  
    }
}

void    ft_treat_width(t_data *store_data)
{
    if (store_data->neg)
        ft_treat_neg(store_data);
    else if (!store_data->zero)
    {
      
        if (store_data->zero_w)
        {
            store_data->zero_w = store_data->width - store_data->len;
            store_data->width = 0;
        }
        if (store_data->typ == 'p' && !store_data->zero)
        {
             store_data->width = store_data->width - (store_data->len + 1);
             return ;
        }
        if (store_data->width < store_data->len)
            store_data->width = 0;
        else
            store_data->width = store_data->width - store_data->len;
    }
    else
    {
        
        if (store_data->typ == 'p' && !store_data->zero)
                store_data->width = store_data->width - store_data->len;
        else
            store_data->width = store_data->width - (store_data->len + 1);
    }
}

void    ft_treat_prec(t_data *store_data)
{
    store_data->zero_w = 0;
    if (store_data->precision_nb > store_data->len)
    {
            store_data->zero_p = store_data->precision_nb - store_data->len;
        if (store_data->width)
        {
             if (store_data->precision_nb >= store_data->width)
            store_data->width = 0;
        else
            store_data->width = store_data->width - store_data->precision_nb;
        }
    }
    else
    {
        store_data->width = store_data->width - store_data->len;
        store_data->zero_p = 0;
    }
}

void    ft_treat_arg_zero(t_data *store_data)
{
    if (store_data->width && !store_data->precision_nb)
    {
        if (store_data->zero_w)
        {
            store_data->zero_w = store_data->width - 1;
            store_data->width = 0;
        }
        if (!store_data->zero_w && !store_data->precision)
            store_data->width = store_data->width - 1;
        if (store_data->precision)
        {
            store_data->zero_w = 0;
            store_data->zero_p = 0;
            if (store_data->wildcard_p)
                store_data->zero_p = 1;
        }
    }
    if (store_data->width && store_data->precision_nb)
    {
        store_data->zero_w = 0;
        store_data->zero_p = store_data->precision_nb;
        store_data->width = store_data->width - store_data->precision_nb;
    }
    if (!store_data->width)
    {
        if (store_data->wildcard_p)
            store_data->zero_p = 1;
        if (store_data->precision_nb)
            store_data->zero_p = store_data->precision_nb;
    } 
}

void    ft_treat_flag(t_data *store_data)
{
    if (!store_data->zero)
    {
        if ((!store_data->precision || !store_data->precision_nb))
        ft_treat_width(store_data);
        else
            ft_treat_prec(store_data);
        if (store_data->zero_w && store_data->minus && !store_data->zero)
            store_data->zero_w = 0;
        if (store_data->neg && store_data->width)
                store_data->width = store_data->width -= 1;
    }
}

void ft_treat_neg(t_data * store_data)
{
    if (store_data->zero_w)
    {
        store_data->zero_w = store_data->width - store_data->len - 1;
        store_data->width = 0;
    }
    else
    {
        if (store_data->conv == 'p')
            store_data->width = store_data->width - (store_data->len + 1);
        else
            store_data->width = store_data->width - (store_data->len);
    }
}