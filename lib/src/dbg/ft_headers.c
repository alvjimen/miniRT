/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_headers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:36:05 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

static void	ft_set_delim(char *delim[4])
{
	delim[0] = COR_TOP_LEFT;
	delim[1] = COR_TOP_RIGHT;
	delim[2] = TABLE_PIPE;
	delim[3] = TABLE_PIPE;
}

static void	ft_set_stc(int fd, int num_fields, t_dbg *stc)
{
	stc->len = ft_max(0);
	stc->fd = fd;
	stc->num_fields = num_fields;
}

void	ft_headers(int fd, int num_fields, ...)
{
	va_list	vl_str;
	int		num;
	t_dbg	stc;
	char	**params;
	char	*delim[4];

	va_start(vl_str, num_fields);
	params = ft_calloc(num_fields, sizeof(char *));
	if (!params)
		return ;
	num = 0;
	while (num < num_fields)
	{
		params[num] = va_arg(vl_str, char *);
		if (!params[num])
			return ;
		ft_max(ft_strlen(params[num]) + 2);
		num ++;
	}
	ft_set_delim(delim);
	ft_set_stc(fd, num_fields, &stc);
	ft_draw_all_fields(stc, params, delim);
	va_end(vl_str);
	free(params);
}
