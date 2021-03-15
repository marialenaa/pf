/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:59:56 by mgallizz          #+#    #+#             */
/*   Updated: 2020/12/03 22:39:53 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*srccpy;
	char	*destcpy;

	srccpy = (char*)src;
	destcpy = (char *)dest;
	if (!(dest || src))
		return (NULL);
	while (n--)
	{
		*destcpy = *srccpy;
		destcpy++;
		srccpy++;
	}
	return (dest);
}
