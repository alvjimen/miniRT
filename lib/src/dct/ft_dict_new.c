/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:19:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dct.h"

t_dict	*ft_dict_new(void *key, void *value)
{
	t_dict	*dict;

	if (!value)
		return (NULL);
	dict = ft_calloc(1, sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->key = key;
	dict->value = value;
	return (dict);
}
