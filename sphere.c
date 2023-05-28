/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:04 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 06:26:35 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	ft_hit_sphere(t_vec3d *center, double diameter, t_ray *ray)
{
	t_vec3d	*oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = ft_vec3d_minus_vec3d(ray->origin, center);
	a = ft_vec3d_dot(ray->direction, ray->direction);
	b = 2.0 * ft_vec3d_dot(oc, ray->unit_direction);
	c = ft_vec3d_dot(oc, oc) - ((diameter / 2) * (diameter / 2));
	free(oc);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-b - sqrt(discriminant)) / (2.0 * a));
}
/* this should be the real formula don't know why is not working fine
	return (-b - sqrt(discriminant) / (2.0 * a));
*/

/* this is just for draw the sphere no normals
double	ft_hit_sphere(t_vec3d *center, double diameter, t_ray *ray)
{
	t_vec3d	*oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = ft_vec3d_minus_vec3d(ray->origin, center);
	a = ft_vec3d_dot(ray->direction, ray->direction);
	b = 2.0 * ft_vec3d_dot(oc, ray->direction);
	c = ft_vec3d_dot(oc, oc) - ((diameter / 2) * (diameter / 2));
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}
*/
