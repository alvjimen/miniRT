/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:00:05 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/20 17:44:54 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "num.h"

static void	ft_print_base(int n, char *str, size_t len)
{
	size_t	num;

	if (len <= 0 || !str)
		return ;
	num = n;
	if (n < 0)
	{
		num = -n;
		write(1, "-", 1);
	}
	if (num >= len)
		ft_print_base(num / len, str, len);
	write(1, &str[num % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	size_t	len;

	len = 0;
	while (base[len])
		len++;
	if (ft_is_str_uniq_exclude_rule(base, ft_is_plus_or_minus))
		ft_print_base(nbr, base, len);
}
