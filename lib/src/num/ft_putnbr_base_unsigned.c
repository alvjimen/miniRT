/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:21:21 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/20 17:47:37 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

static void	ft_print_base_unsigned(size_t n, char *str, size_t len)
{
	if (n >= len)
		ft_print_base_unsigned(n / len, str, len);
	write(1, &str[n % len], 1);
}

void	ft_putnbr_base_unsigned(size_t nbr, char *base)
{
	size_t	len;

	len = 0;
	if (!base)
		return ;
	while (base[len])
		len++;
	if (ft_is_str_uniq_exclude_rule(base, ft_is_plus_or_minus))
		ft_print_base_unsigned(nbr, base, len);
}
