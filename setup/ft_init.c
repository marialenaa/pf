/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:45:56 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/24 16:11:09 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_buf	ft_init_buf(char *list)
{
	t_buf buf;

	ft_strcpy(buf.buf, list);
	buf.len = ft_strlen(list);
	buf.mod = 0;
	buf.count = 0;
	buf.ptr = NULL;
	return (buf);
}

t_data	ft_data_init(void)
{
	t_data data;

	data.len = 0;
	data.mod = 0;
	data.conv = 0;
	data.zero = 0;
	data.typ = 0;
	data.minus = 0;
	data.neg = 0;
	data.zero_w = 0;
	data.zero_p = 0;
	data.width = 0;
	data.precision = 0;
	data.precision_nb = 0;
	data.wildcard_w = 0;
	data.wildcard_p = 0;
	data.int_min = 0;
	data.width_minus = 0;
	data.arg_s = "(null)";
	data.ptr = 0;
	data.arg_i = 0;
	data.arg_u = 0;
	return (data);
}
