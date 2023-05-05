/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_unsigned_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:21:21 by alvjimen          #+#    #+#             */
/*   Updated: 2022/07/25 17:17:24 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

static void	ft_print_base_unsigned(size_t n, char *str, size_t len,
ssize_t *count)
{
	if (n >= len)
		ft_print_base_unsigned(n / len, str, len, count);
	*count += write(1, &str[n % len], 1);
}

void	ft_putnbr_base_unsigned_pf(size_t nbr, char *base, ssize_t *count)
{
	size_t	len;

	len = 0;
	while (base && base[len])
		len ++;
	if (ft_is_str_uniq_exclude_rule(base, ft_is_plus_or_minus))
		ft_print_base_unsigned(nbr, base, len, count);
}
