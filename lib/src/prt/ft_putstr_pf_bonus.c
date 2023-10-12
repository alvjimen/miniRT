/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:33:00 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

static ssize_t	ft_putstr_write_pf(const char *str, t_flags *flags)
{
	ssize_t	count;

	count = 0;
	if (!str && ((flags->flags & B_DOT && flags->accuracy >= 6)
			|| !(flags->flags & B_DOT)))
		count += write(1, "(null)", 6);
	else if (!str && ((flags->flags & B_DOT && flags->accuracy < 6)))
		count += write(1, "(null)", flags->accuracy);
	else if (str)
	{
		while (*str && (flags->accuracy > count || !(flags->flags & B_DOT)))
			count += write(1, str++, 1);
	}
	return (count);
}

ssize_t	ft_putstr_pf(const char *str, t_flags *flags)
{
	ssize_t	count;
	ssize_t	len;

	count = 0;
	len = ft_conversion_len(flags, (void *)str, "s");
	if (flags->accuracy < len && str && flags->flags & B_DOT)
		len = flags->accuracy;
	if (flags->width > len && (!(flags->flags & B_DOT)
			|| (flags->flags & B_DOT && flags->accuracy)))
		flags->width -= len;
	else if (!(flags->flags & B_DOT))
		flags->width = 0;
	if (flags->flags & B_MINUS)
	{
		count += ft_putstr_write_pf(str, flags);
		count += ft_width(flags);
	}
	else
	{
		count += ft_width(flags);
		count += ft_putstr_write_pf(str, flags);
	}
	return (count);
}
