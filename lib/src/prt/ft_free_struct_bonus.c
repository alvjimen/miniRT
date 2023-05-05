/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:14:27 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/22 16:19:08 by alvjimen         ###   ########.fr       */
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
