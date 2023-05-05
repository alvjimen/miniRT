/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:00:05 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:12:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

static void	ft_print_base_pf(long int n, char *str, ssize_t *count,
	t_flags *flags)
{
	size_t	num;
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	if (len == 0)
		return ;
	num = n;
	if (n < 0)
	{
		num *= -n;
		*count += write(1, "-", 1);
	}
	if (num >= len)
		ft_print_base_pf(num / len, str, count, flags);
	*count += write(1, &str[num % len], 1);
}

void	ft_putnbr_base_pf(long int nbr, char *base, ssize_t *count,
	t_flags *flags)
{
	if (ft_is_str_uniq_exclude_rule(base, ft_is_plus_or_minus))
		ft_print_base_pf(nbr, base, count, flags);
}
