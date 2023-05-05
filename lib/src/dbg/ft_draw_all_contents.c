/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all_contents.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:36:02 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 18:40:38 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

void	ft_draw_all_contents(t_dbg stc, char **data, char *delimiter[2])
{
	int		count;

	count = 0;
	while (count < stc.num_fields)
	{
		if (count)
			delimiter[0] = "\0";
		ft_content(stc.fd, data[count], stc.len, delimiter);
		count ++;
	}
	write(stc.fd, "\n", 1);
}
