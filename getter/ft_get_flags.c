/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:47:34 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/24 09:12:42 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	*ft_get_type(char *str_after_mod, t_data *data, t_buf *buf)
{
	int j;
	int i;

	i = 0;
	while (str_after_mod[i] && str_after_mod[i] != '%')
	{
		j = 8;
		while ((str_after_mod[i] != TYPE[j]) && j)
			j--;
		if (str_after_mod[i] == TYPE[j])
		{
			data->typ = TYPE[j];
			return (str_after_mod + i);
		}
		else
			i++;
	}
	if (str_after_mod[i] == '%')
		buf->mod = 1;
	return (str_after_mod + i);
}

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
		return (str_after_mod);
	}
	return (str_after_mod);
}

void	ft_get_flags(char *str, t_data *data, t_buf *buf)
{
	if (!*str)
		return ;
	while (*str != data->typ && *str != '%')
	{
		if (ft_isflag(*str) || ft_isdigit(*str))
		{
			str = ft_strchr(str, '0', &data->zero_w);
			str = ft_strchr(str, '-', &data->minus);
			str = ft_strchr(str, '0', &data->zero_w);
			str = ft_strchr(str, '-', &data->minus);
			str = ft_check_n_store_digit(str, &data->width);
			str = ft_strchr(str, '*', &data->wildcard_w);
			str = ft_strchr(str, '.', &data->precision);
			//str = ft_strchr(str, '-', &data->minus);
			str = ft_strchr(str, '0', &data->zero_p);
			str = ft_strchr(str, '*', &data->wildcard_p);
			if (data->precision)
				str = ft_check_n_store_digit(str, &data->precision_nb);
				//printf("w%d",data->precision_nb);
			if (data->minus && data->zero_w)
        		data->zero_w = 0;
		}
		else
		{
			ft_putchar(*str, &buf->count);
			str++;
		}
	}
//printf("\nSTRUCTURE INFOS:\n");
//printf("minus >>>>> %d\n", data->minus);
//printf("zerow >>>>> %d\n", data->zero_w);
//printf("wildcardW >>>>> %d\n", data->wildcard_w);
//printf("width >>>>> %d\n", data->width);
//printf("precision >>>>> %d\n", data->precision);
//printf("wildcardP >>>>> %d\n", data->wildcard_p);
//printf("precision_nb >>>>> %d\n", data->precision_nb);
//printf("zero >>>>> %d\n", data->zero);
//printf("zerop >>>>> %d\n", data->zero_p);
//printf("len >>>>> %d\n", data->len);
//printf("conv >>>>> %d\n", data->conv);
   
// //     //printf("arg_s >>>>> %s\n", data->arg_s);
// //     printf("hexa >>>>> %llu\n", data->arg.ptr);
//  //  printf("int >>>>> %d\n", data->arg_i);
 
//    printf("mod >>>>> %d\n", data->mod);
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
			if (data->typ != 'i' && data->typ != 'd' && data->typ != 'u')
				data->precision_nb = 1;
			if (data->typ == 's') 
				data->precision = 0;
		}
	}
}