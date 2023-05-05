/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:00:49 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/20 17:36:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

static ssize_t	ft_puthex_pf_write(unsigned int num, t_flags *flags, char *str)
{
	ssize_t		count;

	count = 0;
	if (num && flags->flags & B_HASTAG
		&& !ft_strncmp(str, HEX_L, ft_strlen_null(str)))
		count += write(1, "0x", 2);
	if (num && flags->flags & B_HASTAG
		&& !ft_strncmp(str, HEX_U, ft_strlen_null(str)))
		count += write(1, "0X", 2);
	if (flags->accuracy)
		count += ft_accuracy(flags);
	if (!(flags->flags & B_DOT) || (flags->flags & B_DOT && (flags->accuracy
				|| (!(flags->accuracy) && num))))
		ft_putnbr_base_unsigned_pf(num, str, &count);
	return (count);
}

ssize_t	ft_puthex_pf(unsigned int num, t_flags *flags, char *str)
{
	ssize_t	count;

	count = 0;
	ft_fix_flags_hex(flags, num, ft_conversion_len(flags,
			&num, "x"));
	if (flags->flags & B_MINUS)
	{
		count += ft_puthex_pf_write(num, flags, str);
		count += ft_width(flags);
	}
	else
	{
		count += ft_width(flags);
		count += ft_puthex_pf_write(num, flags, str);
	}
	return (count);
}
