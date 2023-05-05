/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:23:07 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/17 18:47:39 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

ssize_t	ft_strlen_pf(const char *str)
{
	const char	*tmp;

	if (!str)
		return (6);
	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

ssize_t	ft_numlen(int nbr, char *base, t_flags *flags)
{
	size_t		base_len;
	long int	num;
	ssize_t		count;

	base_len = ft_strlen_pf((const char *)base);
	num = (long int)nbr;
	count = 0;
	if (num > -1 && (flags->flags & B_PLUS || flags->flags & B_SPACE))
		count ++;
	if (num < 0)
	{
		num = -num;
		count ++;
	}
	while (num / base_len)
	{
		num /= base_len;
		count ++;
	}
	return (++count);
}

ssize_t	ft_unumlen(size_t nbr, char *base)
{
	size_t	base_len;
	ssize_t	len;

	len = 0;
	base_len = ft_strlen_pf((const char *)base);
	while (nbr / base_len)
	{
		nbr /= base_len;
		len++;
	}
	return (++len);
}
