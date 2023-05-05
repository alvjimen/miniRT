/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:19:38 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 11:28:55 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	rotation_x(double angle, int *y, int *z)
{
	*y = (cos(angle) * *y) - (sin(angle) * *y);
	*z = (sin(angle) * *z) + (cos(angle) * *z);
}

void	rotation_y(double angle, int *x, int *z)
{
	*x = (sin(angle) * *x)- (cos(angle) * *x);
	*z = (sin(angle) * *z) + (cos(angle) * *z);
}

void	rotation_z(double angle, int *x, int *y)
{
	*x = (sin(angle) * *x) - (cos(angle) * *x);
	*y = (sin(angle) * *y) + (cos(angle) * *y);
}
