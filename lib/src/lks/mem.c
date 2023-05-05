/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:45:08 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/31 13:07:21 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "lks.h"

void	*debug_malloc(size_t size, const char *file, size_t line)
{
	void	*p;
	char	*buff;
	int		fd;

	p = malloc(size);
	if (p == NULL)
		return (NULL);
	buff = ft_ptoa((size_t)p);
	fd = open(buff, O_RDWR | O_CREAT, 0644);
	ft_putstr_fd("File: ", fd);
	ft_putstr_fd((char *)file, fd);
	ft_putstr_fd(" Line: ", fd);
	ft_putnbr_base_unsigned_fd(line, "0123456789", fd);
	ft_putstr_fd(" Size: ", fd);
	ft_putnbr_base_unsigned_fd(size, "0123456789", fd);
	ft_putendl_fd(" Bytes", fd);
	close(fd);
	free(buff);
	return (p);
}

void	debug_free(void *p, const char *file, size_t line)
{
	char	*buff;

	buff = ft_ptoa((size_t)p);
	if (unlink(buff) < 0)
		write(1, "Double free", 11);
	(void)file;
	(void)line;
	free(p);
}
