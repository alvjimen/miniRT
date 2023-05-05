/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:11:55 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:31:30 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dbg.h"

void	ft_foot(int fd, int num_fields, ...)
{
	va_list		vl_str;
	static int	min_fields;
	int			num;
	char		**params;

	va_start(vl_str, num_fields);
	if (min_fields < num_fields)
		min_fields = num_fields;
	params = ft_calloc(min_fields, sizeof(char *));
	if (!params)
		return ;
	num = -1;
	while (++num < 2)
	{
		params[num] = va_arg(vl_str, char *);
		if (params[num])
			ft_max(ft_strlen(params[num]) + 2);
	}
	while (min_fields > num_fields)
		params[num_fields++] = "\0";
	ft_draw_all_borders(fd, min_fields, ft_max(0), params);
	va_end(vl_str);
	free(params);
}
