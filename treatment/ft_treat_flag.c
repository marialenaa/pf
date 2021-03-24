/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:49:22 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/19 14:49:24 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_treat_flag(t_data *data)
{
		if ((!data->precision || !data->precision_nb))
			ft_treat_width(data);
		else
			ft_treat_prec(data);
		if (data->zero_w && data->minus && !data->zero)
			data->zero_w = 0;
		if (data->neg && data->width)
			data->width = data->width -= 1;
}

void    ft_treat_width(t_data *data)
{
	if (data->neg)
		ft_treat_neg(data);
	else if (!data->zero && !data->neg)
	{
		if(data->precision && data->zero_p)
			data->zero_p = 0;
		if(data->precision && data->zero_w && data->typ)
			data->zero_w = 0;
		if (data->zero_w)
		{
			data->zero_w = data->width - data->len;
			data->width = 0;
		}
		if (data->typ == 'p' && !data->zero)
		{
			 data->width = data->width - (data->len + 1);
			 return ;
		}
		if (data->width <= data->len)
			data->width = 0;
		else
		{
			data->width = data->width - data->len;
			data->zero_w = 0;
		}
	}
	else
		data->width = data->width - (data->len + 1);
}

void    ft_treat_prec(t_data *data)
{
	data->zero_w = 0;
	if (data->precision_nb > data->len)
	{
		data->zero_p = data->precision_nb - data->len;
		if (data->width)
		{
			if (data->precision_nb >= data->width)
				data->width = 0;
			else
				data->width = data->width - data->precision_nb;
		}
	}
	else
	{
		data->width = data->width - data->len;
		data->zero_p = 0;
	}
}

void ft_treat_neg(t_data * data)
{
	if (data->zero_p)
		data->zero_p = 0;
	if (data->zero_w && !data->precision)
	{
		data->zero_w = data->width - data->len - 1;
		data->width = 0;
	}
	else
	{
		if (data->conv == 'p')
			data->width = data->width - (data->len + 1);
		else
			data->width = data->width - data->len;
		data->zero_w = 0;
	}
}
