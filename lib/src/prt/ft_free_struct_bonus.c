/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:14:27 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

void	ft_free_t_flags(void *content)
{
	t_flags	*struc;

	struc = content;
	if (!struc)
		return ;
	if (struc->str)
		free(struc->str);
	struc->str = NULL;
}

void	ft_free_struct(void *structs, void (*f) (void *))
{
	f(structs);
	free(structs);
	structs = 0;
}
