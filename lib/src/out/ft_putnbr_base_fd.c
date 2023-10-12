/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:14:55 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out.h"

static void	ft_print_base(int n, char *str, size_t len, int fd)
{
	size_t	num;

	if (len <= 0 || !str)
		return ;
	num = n;
	if (n < 0)
	{
		num = -n;
		write(fd, "-", 1);
	}
	if (num >= len)
		ft_print_base(num / len, str, len, fd);
	write(fd, &str[num % len], 1);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	size_t	len;

	len = 0;
	while (base[len])
		len++;
	if (ft_is_str_uniq_exclude_rule(base, ft_is_plus_or_minus))
		ft_print_base(nbr, base, len, fd);
}
