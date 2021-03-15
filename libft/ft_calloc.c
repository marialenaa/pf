/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:11:01 by mgallizz          #+#    #+#             */
/*   Updated: 2020/12/07 10:36:48 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*my_void;
	size_t	azt;

	azt = count * size;
	if (!(my_void = malloc(azt)))
		return (NULL);
	if (my_void)
		ft_memset(my_void, 0, azt);
	return (my_void);
}
