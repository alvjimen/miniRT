/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:04 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/16 08:05:25 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	ft_sqrt_sphere(double discriminant, double a, double half_b,
			t_camera *camera)
{
	double	sqrtd;
	double	t;

	sqrtd = sqrt(discriminant);
	t = (-half_b - sqrtd) / a;
	if (t < camera->t_min || camera->t_max < t)
	{
		t = (-half_b + sqrtd) / a;
		if (t < camera->t_min || camera->t_max < t)
			return (NAN);
	}
	return (t);
}

double	ft_root_sphere(t_vec3d *oc, t_ray *ray, t_camera *camera,
		t_element *sphere)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	a = ft_vec3d_squared_len(ray->direction);
	half_b = ft_vec3d_dot(*oc, ray->direction);
	c = ft_vec3d_squared_len(*oc) - (sphere->radius * sphere->radius);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0.0)
		return (NAN);
	return (ft_sqrt_sphere(discriminant, a, half_b, camera));
}

int	ft_hit_sphere(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *sphere)
{
	t_vec3d	oc;

	oc = ft_vec3d_minus_vec3d(ray->origin, sphere->coords);
	rec->t = ft_root_sphere(&oc, ray, camera, sphere);
	if (isnan(rec->t))
		return (0);
	rec->p = ft_ray_at(ray, rec->t);
	rec->normal = ft_vec3d_div_double(ft_vec3d_minus_vec3d(rec->p,
				sphere->coords), sphere->radius);
	ft_hit_face(ray, rec);
	ft_sphere_uv(rec, sphere);
	return (1);
}
