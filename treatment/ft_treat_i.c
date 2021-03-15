#include "../libftprintf.h"

void ft_treat_u_i(t_data *store_data, t_buf *buf)
{
    long long int arg;
    if (store_data->conv == 'i')
        arg = store_data->arg.arg_i;
    else
        arg = store_data->arg.arg_u;
    if ( !store_data->width && !store_data->precision)
        store_data->zero_w = 0;
    if ((store_data->width || store_data->precision))
        ft_treat_flag(store_data);
    if (store_data->zero)
        ft_treat_arg_zero(store_data);
    if (!store_data->minus)
        ft_print_width(store_data->width, buf);
    if (store_data->neg)
        ft_putchar('-', buf);        
    ft_print_zero(store_data->zero_p, buf);
    ft_print_zero(store_data->zero_w, buf);
    if (!(store_data->precision && store_data->zero))
       ft_putnbr(arg, store_data, buf);
    if (store_data->minus)
        ft_print_width(store_data->width, buf);
}



