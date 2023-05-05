/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:13:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:13:18 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "out.h"

void	ft_putpointer_fd(size_t pointer, int fd)
{
	write(fd, "0x", 2);
	ft_putnbr_base_unsigned_fd(pointer, "0123456789abcdef", fd);
}
