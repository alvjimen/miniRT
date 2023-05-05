/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:56:02 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/20 17:34:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

static ssize_t	ft_putdigit_pf_write(int nbr, t_flags *flags)
{
	ssize_t			count;
	long int		num;

	count = 0;
	num = nbr;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	else if (num > -1 && flags->flags & B_PLUS)
		count += write(1, "+", 1);
	else if (num > -1 && flags->flags & B_SPACE)
		count += write(1, " ", 1);
	if (flags->accuracy)
		count += ft_accuracy(flags);
	if (!(flags->flags & B_DOT) || (flags->flags & B_DOT && (flags->accuracy
				|| (!(flags->accuracy) && nbr))))
		ft_putnbr_base_pf(num, DEC, &count, flags);
	return (count);
}

ssize_t	ft_putdigit(int nbr, t_flags *flags)
{
	ssize_t	count;

	count = 0;
	ft_fix_flags_digit(nbr, flags);
	if (flags->flags & B_MINUS)
	{
		count += ft_putdigit_pf_write(nbr, flags);
		count += ft_width(flags);
	}
	else
	{
		count += ft_width(flags);
		count += ft_putdigit_pf_write(nbr, flags);
	}
	return (count);
}
