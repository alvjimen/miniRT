/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_is_digit_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:51:20 by alvaro            #+#    #+#             */
/*   Updated: 2022/07/30 17:45:04 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

int	ft_flags_is_digit(t_flags *flags, char *str)
{
	return (*str == 'd' || *str == 'i' || *str == 'u'
		|| *str == 'x' || *str == 'X' || *str == 'p' || *str == 'o' || !flags);
}
