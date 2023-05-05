/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:15:49 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/22 17:35:49 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dct.h"

void	ft_free_t_dict(void	*content)
{
	t_dict	*struc;

	struc = content;
	if (!struc)
		return ;
	if (struc->value)
		free(struc->value);
	struc->value = NULL;
}
