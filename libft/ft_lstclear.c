/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallizz <mgallizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:00:41 by mgallizz          #+#    #+#             */
/*   Updated: 2020/12/16 19:26:21 by mgallizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *save;

	while (*lst)
	{
		save = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = save;
	}
	*lst = NULL;
}
