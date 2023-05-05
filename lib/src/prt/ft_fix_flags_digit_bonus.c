/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_flags_digit_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:26:48 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/20 17:19:32 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

void	ft_fix_flags_digit(int nbr, t_flags *flags)
{
	ssize_t	len;

	len = ft_conversion_len(flags, (void *)&nbr, "d");
	if (flags->width > len && (!(flags->flags & B_DOT) || (flags->flags & B_DOT
				&& flags->accuracy)))
		flags->width -= len;
	else if (!(flags->flags & B_DOT) || (flags->flags & B_DOT
			&& (flags->accuracy || (!flags->accuracy && nbr))))
		flags->width = 0;
	if (flags->accuracy > len - 1 && (nbr < 0 || (nbr > 0
				&& (flags->flags & B_SPACE || flags->flags & B_PLUS))))
		flags->accuracy -= len - 1;
	else if (flags->accuracy > len && nbr)
		flags->accuracy -= len;
	else if (!(flags->accuracy && !nbr && flags->flags & B_DOT))
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
}
