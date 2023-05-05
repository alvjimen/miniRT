/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:06:00 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/26 16:30:38 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dct.h"

void	*ft_dict_search(t_list *lst, void *key, size_t step_size)
{
	t_dict	*dict_field;

	if (!lst)
		return (NULL);
	while (lst)
	{
		dict_field = lst->content;
		if (ft_memcmp(dict_field->key, key, step_size))
			return (dict_field->value);
		lst = lst->next;
	}
	return (NULL);
}
