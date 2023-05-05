/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:36:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 18:42:41 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

static void	ft_delim(char *delim[4])
{
	if (!delim)
		return ;
	delim[0] = TABLE_BW_DATA_LEFT;
	delim[1] = TABLE_BW_DATA_RIGHT;
	delim[2] = TABLE_PIPE;
	delim[3] = TABLE_PIPE;
}

static char	**ft_params(int num_fields, int min_fields, va_list vl_str)
{
	int		num;
	char	**params;

	params = ft_calloc(min_fields, sizeof(char *));
	if (!params)
		return (NULL);
	num = 0;
	while (num < num_fields)
	{
		params[num] = va_arg(vl_str, char *);
		if (!params[num])
			return (NULL);
		ft_max(ft_strlen(params[num]) + 2);
		num ++;
	}
	return (params);
}

void	ft_data(int fd, int num_fields, ...)
{
	static int	min_fields;
	va_list		vl_str;
	t_dbg		stc;
	char		**params;
	char		*delim[4];

	va_start(vl_str, num_fields);
	if (min_fields < num_fields)
		min_fields = num_fields;
	params = ft_params(num_fields, min_fields, vl_str);
	while (min_fields > num_fields)
		params[num_fields++] = "\0";
	stc.len = ft_max(0);
	stc.num_fields = num_fields;
	stc.fd = fd;
	ft_delim(delim);
	ft_draw_all_fields(stc, params, delim);
	va_end(vl_str);
	free(params);
}
