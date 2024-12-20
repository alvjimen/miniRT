/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:59:10 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	ssize_t	count;
	char	*s;

	count = 0;
	s = (char *)str;
	va_start(args, str);
	while (*s)
	{
		if (*s == '%')
			ft_conversion(&s, args, &count);
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (count);
}
