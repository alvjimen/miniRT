/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:16:47 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:34:18 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dbg.h"

void	ft_fill_cell(char *str, size_t times, int fd)
{
	size_t	count;

	count = 0;
	while (count < times)
	{
		ft_putstr_fd(str, fd);
		count ++;
	}
}
