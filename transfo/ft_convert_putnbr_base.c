#include "../libftprintf.h"

void ft_putnbr(long long int n,t_data *data,  t_buf *buf)
{
    if (n > 9)
    {
	    ft_putnbr(n / 10,data, buf);
        ft_putnbr(n % 10,data, buf);
    }
    else
      ft_putchar(n + '0', buf);
}

// void ft_convert_putnbr_base(long long unsigned int nbr, t_data *data,  t_buf *buf)
// {
// 	int temp;
// 	int rest;

//     if (data->len > 0 && !data->zero)
//     {
//         temp = nbr / num_base;
//         data->len--;
//         ft_convert_putnbr_base(temp, data, buf);
//         rest = (nbr % num_base);
//         if (data->typ == 'X')
//             ft_putchar((HEXA_UPPER[rest]),buf);
//         else
//             ft_putchar((HEXA_LOWER[rest]),buf);
//     }
//     if (data->zero && data->typ == 'p')
//         ft_putchar('0',buf);
// }

void ft_convert_putnbr_base(long long unsigned nbr, t_data *data,  t_buf *buf)
{
    long long unsigned num_base;
    num_base = 16;
    if (nbr >= num_base && !data->zero)
    {
        ft_convert_putnbr_base((nbr / num_base), data, buf);
        ft_convert_putnbr_base((nbr % num_base), data, buf);
    }
    else if (data->zero && data->conv != 'x')
    {
        ft_putchar('0',buf);
            return ;
    }
    else
    {
        if (data->typ == 'X')
            ft_putchar((HEXA_UPPER[nbr]),buf);
        if (data->typ == 'x')
            ft_putchar((HEXA_LOWER[nbr]),buf);
    }
    
     
}

void ft_ptr_len(long long unsigned nbr, int *len)
{
    while (nbr > 15)
    {
        nbr = nbr / 16;
        *len = *len +1;
    }
    *len = *len + 2;
}
