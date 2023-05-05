/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_is_conversion_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:26:28 by alvaro            #+#    #+#             */
/*   Updated: 2022/07/30 16:51:34 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

int	ft_flags_is_conversion(t_flags *flags, char *str)
{
	return (ft_flags_is_digit(flags, str) || ft_flags_is_str(str));
}
