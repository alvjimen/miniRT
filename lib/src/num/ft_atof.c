/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:45:04 by alvjimen          #+#    #+#             */
/*   Updated: 2022/10/28 16:42:58 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

double	ft_atof(char	*str)
{
	double	result;
	double	period;
	size_t	divider;

	result = ft_atoi(str);
	period = 0;
	divider = 1;
	while (*str >= '0' && *str < '9')
		str++;
	if (*str == '.')
	{
		str++;
		period = ft_atoi(str);
		while (*str >= '0' && *str < '9')
		{
			str ++;
			divider *= 10;
		}
	}
	return (result + period / divider);
}
