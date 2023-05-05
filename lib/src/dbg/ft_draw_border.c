/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:39:21 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:42:06 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

static	void	identified_separator(char **k, char *delimiter[2])
{
	*k = NULL;
	if (!ft_strncmp(COR_TOP_LEFT, delimiter[0], ft_strlen(delimiter[0])))
		*k = TABLE_T;
	else if (!ft_strncmp(TABLE_BW_DATA_LEFT, delimiter[0],
			ft_strlen(delimiter[0])))
		*k = CROSS_THIN;
	else if (!ft_strncmp(COR_LOW_LEFT, delimiter[0],
			ft_strlen(delimiter[0])))
		*k = TABLE_RT;
}

void	ft_draw_all_borders(int fd, int num_fields, size_t len,
	char *delimiter[2])
{
	int		count;
	char	*end;
	char	*separator;

	identified_separator(&separator, delimiter);
	end = delimiter[1];
	count = 0;
	while (count < num_fields)
	{
		if (!count)
			delimiter[0] = delimiter[0];
		else
			delimiter[0] = "\0";
		if (count == num_fields - 1)
			delimiter[1] = end;
		else
			delimiter[1] = separator;
		ft_draw_border(fd, len, delimiter);
		count++;
	}
	write(fd, "\n", 1);
}

void	ft_draw_border(int fd, size_t len, char *delimiter[2])
{
	write(fd, delimiter[0], ft_strlen(delimiter[0]));
	fflush(NULL);
	ft_fill_cell(TABLE_SLASH, len, fd);
	write(fd, delimiter[1], ft_strlen(delimiter[1]));
	fflush(NULL);
}
