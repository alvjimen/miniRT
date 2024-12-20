/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:17:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/*
	lst == equal to first part.
	delim == equal to second part.
*/
static int	ft_split_first(t_list *lst, t_list *delim)
{
	if (!lst)
		return (1);
	if (lst == delim)
		return (0);
	while (lst && lst->next != delim)
		lst = lst->next;
	if (!lst)
		return (1);
	lst->next = NULL;
	return (0);
}

t_list	*ft_split_list(t_list **lst, int (*f)(void *))
{
	t_list	*second;

	if (!lst || !*lst)
		return (NULL);
	second = ft_search_list(*lst, (*f));
	if (!second)
		return (NULL);
	if (ft_split_first(*lst, second))
		return (NULL);
	return (second);
}
