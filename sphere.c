/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:04 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 10:16:41 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	ft_hit_sphere(t_vec3d *center, double diameter, t_ray *ray)
{
	t_vec3d	*oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = ft_vec3d_minus_vec3d(ray->origin, center);
	a = ft_vec3d_dot(ray->direction, ray->direction);
	half_b = ft_vec3d_dot(oc, ray->unit_direction);
	c = ft_vec3d_dot(oc, oc) - ((diameter / 2) * (diameter / 2));
	free(oc);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-half_b - sqrt(discriminant)) / a);
}
