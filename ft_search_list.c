/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:09:40 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/22 18:41:49 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lst.h"

t_list	*ft_search_list(t_list *lst, int (*f)(void *))
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!f(lst->content) && lst->content)
			break ;
		lst = lst->next;
	}
	return (lst);
}
