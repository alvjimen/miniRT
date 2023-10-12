/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_pf_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:34:16 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

static ssize_t	ft_putpointer_pf_write(size_t pointer, t_flags *flags)
{
	ssize_t			count;

	count = 0;
	if (flags->flags & B_SPACE)
		count += write(1, " ", 1);
	else if (flags->flags & B_PLUS)
		count += write(1, "+", 1);
	count += write(1, "0x", 2);
	if (flags->accuracy)
		ft_accuracy(flags);
	ft_putnbr_base_unsigned_pf(pointer, HEX_L, &count);
	return (count);
}

ssize_t	ft_putpointer_pf(size_t pointer, t_flags *flags)
{
	ssize_t	count;

	count = 0;
	ft_fix_flags_pointer(flags, pointer);
	if (flags->flags & B_MINUS)
	{
		count += ft_putpointer_pf_write(pointer, flags);
		count += ft_width(flags);
	}
	else
	{
		count += ft_width(flags);
		count += ft_putpointer_pf_write(pointer, flags);
	}
	return (count);
}
