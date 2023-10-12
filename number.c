/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:57:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 13:21:54 by dmacicio         ###   ########.fr       */
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

double	ft_quadratic_equation(double a, double b, double c, t_camera *camera)
{
	double	discriminant;
	double	sqrtd;
	double	t;

	discriminant = b * b - 4 * a * c;
	t = NAN;
	if (discriminant < 0)
		return (t);
	sqrtd = sqrt(discriminant);
	t = (-b - sqrtd) / (2 * a);
	if (t < camera->t_min || camera->t_max < t)
	{
		t = (-b + sqrtd) / (2 * a);
		if (t < camera->t_min || camera->t_max < t)
			return (NAN);
	}
	return (t);
}

int	ft_is_valid_double(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (ft_isdigit(*str))
	{
		while (*str && ft_isdigit(*str))
			str++;
		if (*str == '.')
			str++;
		if (ft_isdigit(*str))
		{
			while (*str && ft_isdigit(*str))
				str++;
		}
		if (ft_is_space(*str) || *str == ',' || *str == '\0' || *str == '\n')
			return (0);
	}
	return (-1);
}
