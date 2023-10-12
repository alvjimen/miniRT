/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned_fd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:15:20 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out.h"

static void	ft_print_base(size_t n, char *str, size_t len, int fd)
{
	if (len <= 0 || !str)
		return ;
	if (n >= len)
		ft_print_base(n / len, str, len, fd);
	write(fd, &str[n % len], 1);
}

void	ft_putnbr_base_unsigned_fd(size_t nbr, char *base, int fd)
{
	size_t	len;

	len = 0;
	while (base[len])
		len++;
	if (ft_is_str_uniq_exclude_rule(base, NULL))
		ft_print_base(nbr, base, len, fd);
}
