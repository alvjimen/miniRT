/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_flags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:10:48 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/12 18:07:35 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

void	ft_fix_flags(t_flags *flags, char *str)
{
	if (*str == 's' && flags->width && flags->flags & B_ZERO)
		flags->flags -= B_ZERO;
	if (flags->flags & B_DOT && flags->flags & B_ZERO)
		flags->flags -= B_ZERO;
	if (flags->flags & B_MINUS && flags->flags & B_ZERO)
		flags->flags -= B_ZERO;
	if (flags->flags & B_PLUS && flags->flags & B_SPACE)
		flags->flags -= B_SPACE;
}
