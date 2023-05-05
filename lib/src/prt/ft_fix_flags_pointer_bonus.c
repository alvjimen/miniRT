/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_flags_pointer_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:10:48 by alvaro            #+#    #+#             */
/*   Updated: 2022/08/13 13:52:19 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

void	ft_fix_flags_pointer(t_flags *flags, size_t pointer)
{
	ssize_t	len;

	len = ft_conversion_len(flags, (void *)&pointer, "p");
	if ((flags->flags & 2 || flags->flags & 4) && flags->width)
		flags->width --;
	if (flags->width > len)
		flags->width -= len;
	else
		flags->width = 0;
	if (flags->accuracy > len - 2)
		flags->accuracy -= len - 2;
	else
		flags->accuracy = 0;
	if (flags->width > flags->accuracy)
		flags->width -= flags->accuracy;
	else
		flags->width = 0;
	if (flags->flags & 16 && flags->width > flags->accuracy)
	{
		flags->accuracy = flags->width;
		flags->width = 0;
	}
	if (flags->flags & 16)
		flags->flags -= 16;
}
