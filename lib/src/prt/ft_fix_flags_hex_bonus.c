/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_flags_hex_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:10:48 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

void	ft_fix_flags_hex(t_flags *flags, size_t pointer, ssize_t len)
{
	if (flags->width > len && (!(flags->flags & B_DOT) || (flags->flags & B_DOT
				&& flags->accuracy)))
		flags->width -= len;
	else if (!(flags->flags & B_DOT) || (flags->flags & B_DOT
			&& (flags->accuracy || (!flags->accuracy && pointer))))
		flags->width = 0;
	if (flags->accuracy && flags->accuracy > len - 2 && flags->flags & B_HASTAG)
		flags->accuracy -= len - 2;
	else if (flags->accuracy > len && pointer)
		flags->accuracy -= len;
	else if (!(flags->flags & B_DOT && flags->accuracy && !pointer))
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
