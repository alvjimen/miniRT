/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:04 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 20:17:08 by alvjimen         ###   ########.fr       */
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


double	ft_root_sphere(t_vec3d *oc, t_ray *ray, t_camera  *camera,
		t_element *sphere)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	t;

	a = ft_vec3d_squared_len(ray->direction);
	half_b = ft_vec3d_dot(oc, ray->unit_direction);
	c = ft_vec3d_squared_len(oc) - ((sphere->diameter / 2) * (sphere->diameter / 2));
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (NAN);
	discriminant = sqrt(discriminant);
	t = (-half_b - discriminant) / a;
	if (t < camera->focal_length || camera->t_max < t)
	{
		t = (-half_b + discriminant) / a;
		if (t < camera->focal_length || camera->t_max < t)
			return (NAN);
	}
	return (t);
}

int	ft_hit_sphere_v2(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *sphere)
{
	t_vec3d	*oc;
	double	t;

	oc = ft_vec3d_minus_vec3d(ray->origin, &sphere->coords);
	t = ft_root_sphere(oc, ray, camera, sphere);
	free(oc);
	if (isnan(t))
		return (0);
	rec->t = t;
	rec->p = ft_ray_at(ray, t);
	rec->normal	= ft_init_vec3d((rec->p->x  - sphere->coords.x)  / (sphere->diameter / 2),
		(rec->p->y  - sphere->coords.y)  / (sphere->diameter / 2),
		(rec->p->z  - sphere->coords.z)  / (sphere->diameter / 2));
	ft_hit_face(ray, rec);
	return (1);
}
