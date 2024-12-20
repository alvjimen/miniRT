/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:45:54 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/30 14:32:56 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, NULL, 0))
		return ;
	write(fd, &c, 1);
}
