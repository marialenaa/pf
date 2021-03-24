/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:46:26 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/24 14:41:55 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void                    ft_parser(va_list args_ptr, t_data *data, t_buf *buf)
{
    if (data->wildcard_w || data->wildcard_p)
        ft_get_wildcard(data, args_ptr);
    if (data->minus && data->zero_w)
        data->zero_w = 0;
    if (data->typ == 'c')
        ft_treat_c(args_ptr, data, buf);
    if (data->typ == 's')
        ft_get_arg_s(args_ptr, data, buf);
    else if (data->typ == 'p')
        ft_get_arg_p(args_ptr, data, buf);
    else if (data->typ == 'i' || data->typ == 'd')
        ft_get_arg_i_d(args_ptr, data, buf);
    else if (data->typ == 'x' || data->typ == 'X' || data->typ == 'u')
        ft_get_arg_x_u(args_ptr, data, buf);
}
