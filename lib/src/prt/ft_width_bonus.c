/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:52:38 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

ssize_t	ft_width(t_flags *flags)
{
	ssize_t	count;

	count = 0;
	while (count < flags->width)
	{
		if (flags->flags & B_ZERO)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
	}
	flags->width = 0;
	return (count);
}
