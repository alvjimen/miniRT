/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:06:00 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
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
