/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnodeiteri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:23:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/* ! Doesn't destroy the node or the list as function pls?  */
void	ft_lstnodeiteri(t_list *node, void (*n)(t_list *node))
{
	t_list	*next;

	if (!n)
		return ;
	while (node)
	{
		next = node->next;
		n(node);
		node = next;
	}
}
