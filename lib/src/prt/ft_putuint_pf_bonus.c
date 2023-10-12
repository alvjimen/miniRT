/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:34:46 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

static void	ft_putuint_write_pf(unsigned int n, t_flags *flags, char *str,
	ssize_t *count)
{
	unsigned int	num;
	unsigned int	len;

	len = 0;
	num = n;
	while (str[len])
		len++;
	if (flags->accuracy)
		*count += ft_accuracy(flags);
	if (num >= len)
		ft_putuint_write_pf(num / len, flags, str, count);
	if (!(flags->flags & B_DOT) || (flags->flags & B_DOT && (flags->accuracy
				|| (!(flags->accuracy) && n))))
		*count += write(1, &str[num % len], 1);
}

ssize_t	ft_putuint(unsigned int n, char *str, t_flags *flags)
{
	size_t	len;
	ssize_t	count;

	len = 0;
	count = 0;
	while (str[len])
		len++;
	if (len <= 0)
		return (0);
	ft_fix_flags_unsigned(flags, n);
	if (flags->flags & B_MINUS)
	{
		ft_putuint_write_pf(n, flags, str, &count);
		count += ft_width(flags);
	}
	else
	{
		count += ft_width(flags);
		ft_putuint_write_pf(n, flags, str, &count);
	}
	return (count);
}
