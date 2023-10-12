/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:57:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/12 17:38:40 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (max < x)
		return (max);
	return (x);
}

double	ft_dabs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}
