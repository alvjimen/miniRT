/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:20:39 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/25 14:16:29 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_base_of_the_cone(t_ray *ray, t_camera *camera,
		t_hit_record *rec, t_element *cylinder)
{
	double	t;

	t = ft_hit_surface_base(ray, camera, cylinder, rec);
	if (isnan(t))
		return (0);
	rec->t = t;
	rec->normal = ft_vec3d_negative(cylinder->orientation_vector);
	rec->p = ft_ray_at(ray, rec->t);
	return (1);
}

/*
   h = h^
   i 0, 1, 2
   abc { a, b, c }
 */
static double	ft_check_discriminant(double abc[3], t_camera *camera,
		t_ray *ray, t_vec3d h)
{
	double	discriminant;
	double	sqrtd;
	double	t;
	double	t_v2;
					/* b^2 - 4ac*/
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (NAN);/*		 v^ · h^ != 1*/
	if (discriminant == 0 && ft_vec3d_dot(ft_vec3d_unit_lenght(ray->direction),
			h) != 1)
		/* -b / 2a */
		return (-abc[1] / (2 * abc[0]));
	sqrtd = sqrt(discriminant);
	/*(-b - sqrtd) / 2a*/
	t = (-abc[1] - sqrtd) / (2 * abc[0]);
	/*this is for take the closest t*/
	if (t < camera->t_min || camera->t_max < t)
	{
		/*(-b + sqrtd) / 2a*/
		t = (-abc[1] + sqrtd) / (2 * abc[0]);
		if (t < camera->t_min || camera->t_max < t)
			return (NAN);
	}
	else
	{
		t_v2 = (-abc[1] + sqrtd) / (2 * abc[0]);
		if (t_v2 >= camera->t_min && camera->t_max >= t_v2 && t > t_v2)
			return (t_v2);
	}
	return (t);
}

/*ph = H*/
/*v = ray->direction*/
static double	ft_calculate_coefficients(t_ray *ray, t_element *cylinder,
		t_camera *camera, t_vec3d ph)
{
	t_vec3d	uh;
	t_vec3d	w;
	double	m;
	double	abc[3];

	w = ft_vec3d_minus_vec3d(ray->origin, ph);
	/* h = H - C; h = h^*/
	uh = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(ph, cylinder->coords));
	/* a = v · v - (v · h^)^2*/
	m = (cylinder->radius * cylinder->radius) / ft_vec3d_squared_len(
			ft_vec3d_minus_vec3d(ph, cylinder->coords));
	abc[0] = ft_vec3d_dot(ray->direction, ray->direction) - (m + 1) * pow(
			ft_vec3d_dot(ray->direction, uh), 2);
	/* b = (v · w) - v · h^ * w · h^ */
	abc[1] = 2 * (ft_vec3d_dot(ray->direction, w) - (m + 1)
			* (ft_vec3d_dot(ray->direction, uh) * ft_vec3d_dot(w, uh)));
	/* c = w · w - (w · h^)^2 - r^2*/
	abc[2] = ft_vec3d_dot(w, w) - (m + 1) * pow(ft_vec3d_dot(w, uh), 2);
	return (ft_check_discriminant(abc, camera, ray, uh));
}

int	ft_hit_cone(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cylinder)
{
	double	intersect;
	double	len_h;
	double	q;
	t_vec3d	h;
	double	t;

	/* h = ph */
	h = ft_vec3d_plus_vec3d(cylinder->coords, ft_vec3d_pro_double(
				ft_vec3d_unit_lenght(cylinder->orientation_vector),
				cylinder->height));
	rec->t = ft_calculate_coefficients(ray, cylinder, camera, h);
	if (isnan(rec->t))
		return (0);
	rec->p = ft_ray_at(ray, rec->t);
	/* h = h */
	h = ft_vec3d_minus_vec3d(h, cylinder->coords);
	/* intersect = (Lint - C) · h -> rec->p - cylinder->coords · h*/
	intersect = ft_vec3d_dot(ft_vec3d_minus_vec3d(rec->p, cylinder->coords), h);
	len_h = ft_vec3d_len(h);
	if (0.0 <= intersect && intersect <= len_h)
	{
		t = rec->t;
		ft_base_of_the_cone(ray, camera, rec, cylinder);
		if (t > rec->t)
			return (1);
		rec->t = t;
		rec->p = ft_ray_at(ray, rec->t);
		/* calculating the normal */
		/* calculating the height on the axis */
		q = sqrt(cylinder->radius * cylinder->radius + ft_vec3d_squared_len(
					ft_vec3d_minus_vec3d(cylinder->coords, rec->p)));
		/* calculating the point of the axis */
		h = ft_vec3d_plus_vec3d(cylinder->coords, ft_vec3d_pro_double(
					ft_vec3d_unit_lenght(cylinder->orientation_vector),
					q));
		rec->normal = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(rec->p, h));
		return (1);
	}
	else
		return (ft_base_of_the_cone(ray, camera, rec, cylinder));
}
