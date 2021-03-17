#include "../libftprintf.h"

int		ft_isflag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*' || c == '%')
		return (1);
	return (0);
}

void	*ft_check_n_store_digit(char *str_after_mod, int *width_or_prec)
{
	long	res;

	res = 0;
	if (ft_isdigit(*str_after_mod))
	{
		while (ft_isdigit(*str_after_mod))
		{
			res = res * 10 + (*str_after_mod - '0');
            str_after_mod++;
		}
		*width_or_prec = res;
	}
    return (str_after_mod);
}

void		ft_get_flags(char *str, t_data *data, t_buf *buf)
{
    if (!str)
        return ;
    while ((!ft_isflag(*str) && !ft_isdigit(*str)) && (str != buf->ptr))
        str++;
    str = ft_strchr(str, '0', &data->zero_w);
    str = ft_strchr(str, '-', &data->minus);
    str = ft_strchr(str, '0', &data->zero_w);
    str = ft_strchr(str, '-', &data->width_minus);
    str = ft_check_n_store_digit(str, &data->width);
    str = ft_strchr(str, '%', &data->mod);
    str = ft_strchr(str, '*', &data->wildcard_w);
    str = ft_strchr(str, '.', &data->precision);
    str = ft_strchr(str, '-', &data->precision);
    str = ft_strchr(str, '0', &data->zero_p);
    str = ft_strchr(str, '*', &data->wildcard_p);
    if (data->precision)
        str = ft_check_n_store_digit(str, &data->precision_nb);
}

void    ft_parser(va_list args_ptr, t_data *data, t_buf *buf)
{
    //     printf("\nSTRUCTURE INFOS:\n");
//  	 printf("precision_nb >>>>> %d\n", data->precision_nb);
//     printf("precision >>>>> %d\n", data->precision);
//     printf("zero >>>>> %d\n", data->zero);
//     printf("zerop >>>>> %d\n", data->zero_p);
//    printf("zerow >>>>> %d\n", data->zero_w);
 //    printf("typ >>>>> %c\n", data->typ);
//      printf("minus >>>>> %d\n", data->minus);
//    printf("len >>>>> %d\n", data->len);
//     printf("conv >>>>> %d\n", data->conv);
//     printf("wildcardp >>>>> %d\n", data->wildcard_p);
//     //printf("arg_s >>>>> %s\n", data->arg.arg_s);
//     //printf("hexa >>>>> %llu\n", data->arg.ptr);
//    // printf("int >>>>> %d\n", data->arg.arg_i);
//  printf("width >>>>> %d\n", data->width);
//    printf("mod >>>>> %d\n", data->mod);
    if (data->wildcard_w || data->wildcard_p)
        ft_treat_wildcard(data, args_ptr);
    if (data->typ == 'c')
         ft_treat_c(data, buf);
    if (data->typ == 's')
        ft_get_arg_s(args_ptr, data, buf);
    else if (data->typ == 'p')
        ft_get_arg_p(args_ptr, data, buf);
    else if (data->typ == 'i' || data->typ == 'd')
        ft_get_arg_i_d(args_ptr, data, buf);
    else if (data->typ == 'x' || data->typ == 'X' || data->typ == 'u')
        ft_get_arg_x_u(args_ptr, data, buf);
    else 
        ft_notype(args_ptr, data, buf);
}

void *ft_get_type(char *str_after_mod, t_data *data)
{
    int j;
    int i;

    i = 0;
    while (str_after_mod[i])
    {
        j = 0;
        while ((str_after_mod[i] != TYPE[j]) && j < 6)
            j++;
        if (str_after_mod[i] == TYPE[j])
        {
            data->typ = TYPE[j];
            return (str_after_mod + i);
        }
        else
            i++; 
    }
    return (str_after_mod);
}