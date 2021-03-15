#include "../libftprintf.h"

void ft_treat_u_i(t_data *data, t_buf *buf)
{
    long long int arg;
    if (data->conv == 'i')
        arg = data->arg.arg_i;
    else
        arg = data->arg.arg_u;
    if ( !data->width && !data->precision)
        data->zero_w = 0;
    if ((data->width || data->precision))
        ft_treat_flag(data);
    if (data->zero)
        ft_treat_arg_zero(data);
    if (!data->minus)
        ft_print_width(data->width, buf);
    if (data->neg)
        ft_putchar('-', buf);        
    ft_print_zero(data->zero_p, buf);
    ft_print_zero(data->zero_w, buf);
    if (!(data->precision && data->zero) && !data->int_min)
    {
        ft_putnbr(arg, data, buf);
        //printf("**%llu", arg);
    }
    // else 
    // {
    //     printf("**%llu", arg);
    // }   
    if (data->int_min)
        ft_putstrl("2147483648",10, buf);
    if (data->minus)
        ft_print_width(data->width, buf);
}



