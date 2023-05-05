/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:33:39 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/14 13:11:25 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

ssize_t	ft_putchar_pf(char c, t_flags *flags)
{
	ssize_t	count;
	ssize_t	len;

	count = 0;
	len = ft_conversion_len(flags, (void *)&c, "c");
	if (flags->width >= len)
		flags->width -= len;
	if (flags->flags & B_MINUS)
	{
		count += write(1, &c, 1);
		count += ft_width(flags);
	}
	else
	{
		count += ft_width(flags);
		count += write(1, &c, 1);
	}
	return (count);
}
