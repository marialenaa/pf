/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:48:36 by mgallizz          #+#    #+#             */
/*   Updated: 2021/03/24 16:36:09 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(int c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstrl(char *str, int len, t_buf *buf)
{
	int i;

	i = 0;
	while (str[i] != '\0' && len > 0)
	{
		if (buf->mod && str[i] == '%')
		{
			i++;
			buf->mod = 0;
		}
		ft_putchar(str[i], &buf->count);
		i++;
		len--;
	}
}

void	ft_print_zero(int zero_nb, t_buf *buf)
{
	while (zero_nb > 0)
	{
		ft_putchar('0', &buf->count);
		zero_nb--;
	}
}

void	ft_print_width(int width, t_buf *buf)
{
	while (width > 0)
	{
		ft_putchar(' ', &buf->count);
		width--;
	}
}
