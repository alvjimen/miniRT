/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:20:39 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 19:42:21 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/* ph = H */
/* h = c - H */
/* uh = h^ */
int	ft_hit_cone(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cone)
{
	t_vec3d	ph;
	t_vec3d	h;
	t_vec3d	uh;
	t_vec3d	w;
	t_vec3d	uv;
	double	a;
	double	b;
	double	c;
	double	m;
	double	discriminant;
	double	sqrtd;
	double	t;
	double	intersection;
	double	len_h;
	double	cos_a;

	uh = ft_vec3d_unit_lenght(cone->orientation_vector);
	h = ft_vec3d_pro_double(uh, cone->height);
	len_h =  ft_vec3d_len(h);
	ph = ft_vec3d_plus_vec3d(cone->coords, h);
	m = (cone->radius * cone->radius) / ft_vec3d_squared_len(h);
	w = ft_vec3d_minus_vec3d(ray->origin, ph);
	a = ft_vec3d_dot(ray->direction, ray->direction) - (m + 1) *
		pow(ft_vec3d_dot(ray->direction, uh), 2);
	b = ft_vec3d_dot(ray->direction, w) - (m + 1) *
		(ft_vec3d_dot(ray->direction, uh) * ft_vec3d_dot(w, uh));
	c = ft_vec3d_dot(w, w) - (m + 1) * pow(ft_vec3d_dot(w, uh), 2);
	discriminant = (b * b) - 4 * a * c;
	if (discriminant < 0)
		return (0);
	else if (discriminant ==  0)
	{
		cos_a = len_h / sqrt(len_h * len_h + cone->radius * cone->radius);
		uv = ft_vec3d_unit_lenght(ray->direction);
		if (ft_vec3d_dot(uv, uh) != cos_a)
		{
			t = -b / (2 * a);
			if (t >= camera->t_min && t <= camera->t_max)
			{
				rec->p = ft_ray_at(ray, t);
				rec->normal = ft_init_vec3d(1, 0, 0);
				return (1);
			}
		}
	}
	else if (discriminant > 0)
	{
		sqrtd = sqrt(discriminant);
		t = (-b - sqrtd) / (2 * a);
		if (t < camera->t_min || camera->t_max < t)
		{
			t = (-b + sqrtd) / (2 * a);
			if (t < camera->t_min || camera->t_max < t)
				return (0);
		}
		rec->p =  ft_ray_at(ray, t);
		intersection = ft_vec3d_dot(ft_vec3d_minus_vec3d(rec->p, ph), uh);
		if (intersection < 0)
			return (0);
		if (0 <= intersection && intersection <= len_h)
		{
			rec->normal = ft_init_vec3d(0, 1, 0);
			return (1);
		}
		if (intersection > len_h)
		{
			/*t = ft_hit_surface_base(ray, camera, cone, rec);
			if (isnan(t))
				return (0);
			rec->t = t;
			rec->p = ft_ray_at(ray, t);
			*/
			rec->normal = ft_init_vec3d(0, 0, 1);
			return (1);
		}
	}
	return (0);
//	
//	rec->normal = cone->orientation_vector;
	return (0);
}
