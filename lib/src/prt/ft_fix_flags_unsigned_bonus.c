/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_flags_unsigned_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:29:30 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

void	ft_fix_flags_unsigned(t_flags *flags, unsigned int uint)
{
	ssize_t	len;

	len = ft_conversion_len(flags, (void *)&uint, "u");
	if (flags->width > len && (!(flags->flags & B_DOT) || (flags->flags & B_DOT
				&& flags->accuracy)))
		flags->width -= len;
	else if (!(flags->flags & B_DOT) || (flags->flags & B_DOT
			&& (flags->accuracy || (!flags->accuracy && uint))))
		flags->width = 0;
	if (flags->accuracy > len && uint)
		flags->accuracy -= len;
	else if (!(flags->flags & B_DOT && !uint && flags))
		flags->accuracy = 0;
	if (flags->width > flags->accuracy)
		flags->width -= flags->accuracy;
	else
		flags->width = 0;
	if (flags->flags & B_ZERO && flags->width > flags->accuracy)
	{
		flags->accuracy = flags->width;
		flags->width = 0;
	}
	if (flags->flags & B_ZERO)
		flags->flags -= B_ZERO;
}
