/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:47:34 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/22 10:06:42 by mgallizz         ###   ########.fr       */
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
			str = ft_strchr(str, '-', &data->width_minus);
			str = ft_check_n_store_digit(str, &data->width);
			str = ft_strchr(str, '*', &data->wildcard_w);
			str = ft_strchr(str, '.', &data->precision);
			str = ft_strchr(str, '-', &data->precision);
			str = ft_strchr(str, '0', &data->zero_p);
			str = ft_strchr(str, '*', &data->wildcard_p);
			if (data->precision)
				str = ft_check_n_store_digit(str, &data->precision_nb);
		}
		else
		{
			ft_putchar(*str, &buf->count);
			str++;
		}
	}
}
