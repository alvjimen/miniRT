/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flags_zero_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:36:48 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/12 18:00:28 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

int	ft_fill_flags_zero(char **str, t_flags *flags)
{
	return (*str[0] == '0' && !(flags->flags & B_ZERO)
		&& !flags->width && !flags->accuracy);
}
