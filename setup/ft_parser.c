#include "../libftprintf.h"

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	ft_div(unsigned int *nb)
{
	*nb = *nb / 10;
}

size_t	ft_intlen(unsigned int nb, char typ)
{
	int i;
    
	i = 0;
    if (typ == 'x' && nb)
    {
        while (nb > 15)
        {
            nb = nb / 16;
            i++ ;
        }
        return (i + 1);
    }
    // if (typ == 'p')
    //     i += 2;
    if (nb)
		i++;
	while (nb > 9)
	{
		ft_div(&nb);
		i++;
	}
	return (i);
}

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

void    *ft_get_n_store_arg(char *alpha, va_list args_ptr, t_data *data)
{
    data->typ = *alpha;
    if (data->wildcard_w || data->wildcard_p)
        ft_treat_wildcard(data, args_ptr);
    if (*alpha == 's')
    {
        data->arg.arg_s = va_arg(args_ptr, char *);
        if (data->arg.arg_s == NULL)
        {
             data->arg.arg_s = "(null)";
             data->zero = 1;
        }
        data->len = ft_strlen(data->arg.arg_s);
    }
    else if (*alpha == 'p')
    {
        data->arg.ptr = va_arg(args_ptr,long long unsigned);
        if (data->arg.ptr == (long long unsigned)NULL)
        {
            data->conv = *alpha;
            data->zero_w = 1;
            data->zero = 1;
            data->len = 2; 
        }
        if (data->arg.ptr > 0)
            ft_ptr_len(data->arg.ptr, &data->len);
    }
    else if (*alpha == 'i' || *alpha == 'd')
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
    }
    else if (*alpha == 'x' || *alpha == 'X' || *alpha == 'u')
    {
        data->arg.arg_u = va_arg(args_ptr, unsigned int);
        if (!(*alpha == 'u'))
             data->conv = 'x';
        if (data->arg.arg_u == 0)
            data->zero = 1;
        else
            data->len = ft_intlen(data->arg.arg_u, data->conv);
    }
    else 
    {
        data->arg.arg_i = va_arg(args_ptr, int);
        data->len = 1;
    }
    return (alpha + 1);
}

char *ft_parser(char *str_after_mod, va_list args_ptr, t_buf *buf)
{
    int j;
 t_data data;

  data = ft_data_init();
    j = 0;
    if (!(ft_isalpha(*str_after_mod)))
        str_after_mod = ft_check_n_data(str_after_mod, &data);
    if (ft_isalpha(*str_after_mod))
    {
        while (TYPE[j] != *str_after_mod)
            j++;
        if (*str_after_mod == TYPE[j])
            str_after_mod = ft_get_n_store_arg(str_after_mod, args_ptr, &data);
    }
    if (data.mod > 0)
        data.len += 1;
    ft_parse_treatment(&data,buf);
    return (str_after_mod);
}
