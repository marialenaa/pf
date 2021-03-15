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

void ft_treat_wildcard(t_data *store_data, va_list args_ptr)
{
    
    if (store_data->wildcard_w)
    {
        store_data->width = va_arg(args_ptr, int);
        if (store_data->width < 0)
        {
            store_data->width = store_data->width * (-1);
            if (store_data->typ != 'p')
                store_data->minus = 1;
        }
            
        
    }
    if (store_data->wildcard_p)
    {
        store_data->precision_nb = va_arg(args_ptr, int);
        if (store_data->precision_nb < 0)
            store_data->precision_nb = 0;
    }
        
		
}

void    *ft_get_n_store_arg(char *alpha, va_list args_ptr, t_data *store_data)
{
    store_data->typ = *alpha;
    if (store_data->wildcard_w || store_data->wildcard_p)
        ft_treat_wildcard(store_data, args_ptr);
    if (*alpha == 's')
    {
        store_data->arg.arg_s = va_arg(args_ptr, char *);
        if (store_data->arg.arg_s == NULL)
        {
             store_data->arg.arg_s = "(null)";
             store_data->zero = 1;
        }
        store_data->len = ft_strlen(store_data->arg.arg_s);
    }
    else if (*alpha == 'p')
    {
        store_data->arg.ptr = va_arg(args_ptr,long long unsigned);
        if (store_data->arg.ptr == (long long unsigned)NULL)
        {
            store_data->conv = *alpha;
            store_data->zero_w = 1;
            store_data->zero = 1;
            store_data->len = 2; 
        }
        if (store_data->arg.ptr > 0)
            ft_ptr_len(store_data->arg.ptr, &store_data->len);
    }
    else if (*alpha == 'i' || *alpha == 'd')
    {
        store_data->conv = 'i';
        store_data->arg.arg_i = va_arg(args_ptr, int);
        if (store_data->arg.arg_i < 0)
        {
             store_data->neg = 1;
             store_data->arg.arg_i *= -1; 
        }
        if (store_data->arg.arg_i == 0)
            store_data->zero = 1;
        store_data->len = ft_intlen(store_data->arg.arg_i, store_data->conv);
    }
    else if (*alpha == 'x' || *alpha == 'X' || *alpha == 'u')
    {
        store_data->arg.arg_u = va_arg(args_ptr, unsigned int);
        if (!(*alpha == 'u'))
             store_data->conv = 'x';
        if (store_data->arg.arg_u == 0)
            store_data->zero = 1;
        else
            store_data->len = ft_intlen(store_data->arg.arg_u, store_data->conv);
    }
    else 
    {
        store_data->arg.arg_i = va_arg(args_ptr, int);
        store_data->len = 1;
    }
    return (alpha + 1);
}

char *ft_parser(char *str_after_mod, va_list args_ptr, t_buf *buf)
{
    int j;
 t_data store_data;

  store_data = ft_store_data_init();
    j = 0;
    if (!(ft_isalpha(*str_after_mod)))
        str_after_mod = ft_check_n_store_data(str_after_mod, &store_data);
    if (ft_isalpha(*str_after_mod))
    {
        while (TYPE[j] != *str_after_mod)
            j++;
        if (*str_after_mod == TYPE[j])
            str_after_mod = ft_get_n_store_arg(str_after_mod, args_ptr, &store_data);
    }
    if (store_data.mod > 0)
        store_data.len += 1;
    ft_parse_treatment(&store_data,buf);
    return (str_after_mod);
}
