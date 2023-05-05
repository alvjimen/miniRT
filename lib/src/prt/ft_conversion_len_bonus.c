/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_len_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:42:37 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/20 17:08:37 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

static ssize_t	ft_conversion_len_base(t_flags *flags, void *data, char *str)
{
	ssize_t	len;

	len = 0;
	if (*str == 'x' || *str == 'X')
	{
		len = ft_unumlen(*(unsigned int *)data, HEX_L);
		if (flags->flags & 1)
			len += 2;
	}
	return (len);
}

ssize_t	ft_conversion_len(t_flags *flags, void *data, char *str)
{
	ssize_t	len;

	len = 0;
	if (*str == 'c')
		len = 1;
	else if (*str == 's')
		len = ft_strlen_pf((char *)data);
	else if (*str == 'u')
		len = ft_unumlen(*(unsigned int *)data, DEC);
	else if (*str == 'd' || *str == 'i')
		len = ft_numlen(*(int *)data, DEC, flags);
	else if (*str == 'p')
		len = ft_unumlen(*(size_t *)data, HEX_L) + 2;
	else
		len = ft_conversion_len_base(flags, data, str);
	return (len);
}
