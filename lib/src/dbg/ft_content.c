/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:36:13 by alvjimen          #+#    #+#             */
/*   Updated: 2022/12/18 17:56:12 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

void	ft_content(int fd, char *str, int padding, char *delimiter[2])
{
	int	len;

	write(fd, delimiter[0], ft_strlen(delimiter[0]));
	len = (int)ft_strlen(str);
	write(fd, " ", 1);
	if (len < (padding - 2))
	{
		padding -= (len + 2);
		while (padding--)
			write(fd, " ", 1);
	}
	write(fd, str, len);
	write(fd, " ", 1);
	write(fd, delimiter[1], ft_strlen(delimiter[1]));
	fflush(NULL);
}
