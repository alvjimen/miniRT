/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:04 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 10:34:25 by alvjimen         ###   ########.fr       */
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
	a = ft_vec3d_squared_len(ray->direction);
	half_b = ft_vec3d_dot(oc, ray->unit_direction);
	c = ft_vec3d_squared_len(oc) - ((diameter / 2) * (diameter / 2));
	free(oc);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-half_b - sqrt(discriminant)) / a);
}
/*
int	ft_hit_sphere(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *sphere)
{
	t_vec3d	*oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	*/
	/*
		double	sqrtd;
		double	root;
	*/
	/*

	oc = ft_vec3d_minus_vec3d(ray->origin, sphere.coords);
	a = ft_vec3d_dot(ray->direction, ray->direction);
	half_b = ft_vec3d_dot(oc, ray->unit_direction);
	c = ft_vec3d_dot(oc, oc) - ((diameter / 2) * (diameter / 2));
	free(oc);
*/
	/*
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (0);
	sqrtd = sqrt(discriminant);
	
	return ((-half_b - sqrt(discriminant)) / a);
	*/
//}
