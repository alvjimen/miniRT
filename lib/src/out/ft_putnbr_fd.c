/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:07:52 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:14:17 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "out.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	num;

	num = '0';
	if (write(fd, NULL, 0))
		return ;
	if (n == INT_MAX)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	num += n % 10;
	write(fd, &num, 1);
}
