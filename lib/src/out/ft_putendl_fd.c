/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:01:14 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/30 11:35:39 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || write(fd, NULL, 0))
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
