/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:02:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:42:49 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

int	main(void)
{
	int	padding;
	int	fd;

	padding = 0;
	fd = 2;
	ft_title(" La caja es A ", padding, fd);
	ft_headers(fd, 3, "Palabra", "Palabra 1", "Palabra2");
	ft_data(fd, 3, "Hola", "Saludos", "Adios");
	ft_data(fd, 2, "Hola", "Saludos");
	ft_data(fd, 2, "Hola", "Saludos");
	ft_data(fd, 2, "Hola", "Saludos");
	ft_data(fd, 2, "Hola", "Saludos");
	ft_data(fd, 2, "Hola", "Saludos");
	ft_foot(fd, 3, COR_LOW_LEFT, COR_LOW_RIGHT);
	ft_title(" La caja es A ", padding, fd);
	ft_headers(fd, 3, "Palabra", "Palabra 1", "Palabra2");
	ft_data(fd, 3, "Hola", "Saludos", "Adios");
	ft_foot(fd, 3, COR_LOW_LEFT, COR_LOW_RIGHT);
	return (0);
}
