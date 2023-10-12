/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_title.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:16:47 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

static void	top_border(int fd, int padding, size_t len_str)
{
	int	len_delim;

	len_delim = 1;
	while (len_delim++ < padding)
		write(fd, " ", 1);
	len_delim = (int)ft_strlen(COR_TOP_LEFT);
	write(fd, COR_TOP_LEFT, len_delim);
	ft_fill_cell(TABLE_SLASH, len_str, fd);
	write(fd, COR_TOP_RIGHT, ft_strlen(COR_TOP_RIGHT));
	write(fd, "\n", 1);
}

static void	low_border(int fd, int padding, size_t len_str)
{
	int	len_delim;

	len_delim = 1;
	while (len_delim++ < padding)
		write(fd, " ", 1);
	write(fd, COR_LOW_LEFT, ft_strlen(COR_LOW_LEFT));
	ft_fill_cell(TABLE_SLASH, len_str, fd);
	write(fd, COR_LOW_RIGHT, ft_strlen(COR_LOW_RIGHT));
	write(fd, "\n", 1);
}

void	ft_title(char *str, int padding, int fd)
{
	size_t	len_str;
	int		len_delim;

	if (!str && !padding)
		return ;
	len_str = ft_strlen(str);
	top_border(fd, padding, len_str);
	len_delim = 1;
	while (len_delim++ < padding)
		write(fd, " ", 1);
	len_delim = ft_strlen(TABLE_PIPE);
	write(fd, TABLE_PIPE, len_delim);
	write(fd, str, len_str);
	write(fd, TABLE_PIPE, len_delim);
	write(fd, "\n", 1);
	low_border(fd, padding, len_str);
}
