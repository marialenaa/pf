#include "../libftprintf.h"

void ft_putnbr(long long int n,t_data *store_data,  t_buf *buf)
{
    if (n > 9)
    {
	    ft_putnbr(n / 10,store_data, buf);
        ft_putnbr(n % 10,store_data, buf);
    }
    else
      ft_putchar(n + '0', buf);
}

// void ft_convert_putnbr_base(long long unsigned int nbr, t_data *store_data,  t_buf *buf)
// {
// 	int temp;
// 	int rest;

//     if (store_data->len > 0 && !store_data->zero)
//     {
//         temp = nbr / num_base;
//         store_data->len--;
//         ft_convert_putnbr_base(temp, store_data, buf);
//         rest = (nbr % num_base);
//         if (store_data->typ == 'X')
//             ft_putchar((HEXA_UPPER[rest]),buf);
//         else
//             ft_putchar((HEXA_LOWER[rest]),buf);
//     }
//     if (store_data->zero && store_data->typ == 'p')
//         ft_putchar('0',buf);
// }

void ft_convert_putnbr_base(long long unsigned nbr, t_data *store_data,  t_buf *buf)
{
    long long unsigned num_base;
    num_base = 16;
    if (nbr >= num_base && !store_data->zero)
    {
        ft_convert_putnbr_base((nbr / num_base), store_data, buf);
        ft_convert_putnbr_base((nbr % num_base), store_data, buf);
    }
    else if (store_data->zero && store_data->conv != 'x')
    {
        ft_putchar('0',buf);
            return ;
    }
    else
    {
        if (store_data->typ == 'X')
            ft_putchar((HEXA_UPPER[nbr]),buf);
        if (store_data->typ == 'x')
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
