/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all_fields.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:38:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 18:39:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dbg.h"

void	ft_draw_all_fields(t_dbg stc, char **data, char *delim[4])
{
	ft_draw_all_borders(stc.fd, stc.num_fields, stc.len, delim);
	ft_draw_all_contents(stc, data, &delim[2]);
}
