/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:52:38 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/12 19:39:39 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

ssize_t	ft_width(t_flags *flags)
{
	ssize_t	count;

	count = 0;
	while (count < flags->width)
	{
		if (flags->flags & B_ZERO)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
	}
	flags->width = 0;
	return (count);
}
