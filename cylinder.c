/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:32:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 11:40:19 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/* Q = point of the center */
/* P = point of the surface cylinder */
/* C = point at the center top base */
/* H = point at the center base */
/* r = radius */
/* L0 = point of the line*/
/* v = vector that defines line direction */
/* h = (H - C) */
/* || = len*/
/* h^ = h / ||h||*/
/* Intersection calculation */
/* Point cylinder satisfied */
/* ||P - C|| = sqrt(||Q -C||^2 + r^2) */
/* ||P - C|| ^2 = ||Q -C||^2 + r^2 */
/* || ^ 2 == · */

/* (P - C) · (P - C) = ||Q - C|| + r^2 */
/* ||Q - C|| = (P - C) · h^ */
/* (P - C) · (P - C) = [(P - C) · h^]^2 + r^2 */
/* ||P - C|| - [(P - C) · h^]^2 = r^2 */
/* Substitute P with line equation */
/* L(t) == P = L0 + tv */
/* ||L0 + tv - C||^2 - [(Lo + tv - C) · h^]^2 = r^2*/
/* w = L0 - C */
/* ||w + tv||^2 - [(w + tv) · h^]^2 = r^2*/
/* (w + tv) · (w + tv) - [(w · h^) + (v · h^)t]^2 = r^2*/
/* a = (v · v) - (v · h^)^2*/
/* b = 2[(v · w) - (v · h^)(w · h^)*/
/* c = 2[(w · w) - (w · h^)^2 - r^2*/
/* solve for t = at^2 + bt + c = 0*/
/*
v = ray->direction;
w = ray->origin - cylinder->coords
h^ = ft_vec3d_unit_lenght(cylinder->orientation_vector);
*/
/*
a = ft_vec3d_dot(v, v) - pow(ft_vec3d_dot(v, h^), 2);
b = 2 * (ft_vec3d_dot(v, w) - ft_vec3d_dot(v, h^) * ft_vec3d_dot(w, h^));
c = ft_vec3d_dot(w, w) - pow(ft_vec3d_dot(w, h), 2) - pow(r, 2);
*/

double	ft_hit_surface_base(t_ray *ray, t_camera *camera, t_element *cylinder, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_vec3d	p_c;
	t_vec3d	p;

	denom = ft_vec3d_dot(ft_vec3d_negative(cylinder->orientation_vector), ray->direction);
	if (ft_dabs(denom) <= 0.001)
		return (NAN);
	t = ft_vec3d_dot(ft_vec3d_negative(cylinder->orientation_vector),
			ft_vec3d_minus_vec3d(cylinder->coords, ray->origin)) / denom;
	if (t < camera->t_min || t > camera->t_max || isnan(t))
		return (NAN);
	p = ft_ray_at(ray, t);
	p_c = ft_vec3d_minus_vec3d(p, cylinder->coords);
	if (ft_vec3d_len(p_c) <= cylinder->radius)
	{
		rec->p = p;
		return (t);
	}
	return (NAN);
}

double	ft_hit_surface_top(t_ray *ray, t_camera *camera, t_element *cylinder, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_vec3d	p_c;
	t_vec3d	p;

	denom = ft_vec3d_dot(cylinder->orientation_vector, ray->direction);
	if (ft_dabs(denom) <= 0.001)
		return (NAN);
	t = ft_vec3d_dot(cylinder->orientation_vector,
			ft_vec3d_minus_vec3d(rec->p, ray->origin)) / denom;
	if (t < camera->t_min || t > camera->t_max || isnan(t))
		return (NAN);
	p = ft_ray_at(ray, t);
	p_c = ft_vec3d_minus_vec3d(p, rec->p);
	if (ft_vec3d_len(p_c) <= cylinder->radius)
	{
		rec->p = p;
		return (t);
	}
	return (NAN);
}

int	ft_base_of_the_cylinder(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cylinder)
{
	double	t;
	double	t_2;
	t_vec3d	h;

	h = ft_vec3d_plus_vec3d(cylinder->coords,
			ft_vec3d_pro_double(ft_vec3d_unit_lenght(
			cylinder->orientation_vector), cylinder->height));
	t = ft_hit_surface_base(ray, camera, cylinder, rec);
	rec->p = h;
	t_2 = ft_hit_surface_top(ray, camera, cylinder, rec);
	if (isnan(t) && isnan(t_2))
		return (0);
	else
	{
		if (isnan(t) || (!isnan(t_2) && t >= t_2))
		{
			rec->t = t_2;
			rec->normal = cylinder->orientation_vector;
		}
		else if (isnan(t_2) || (!isnan(t) && t < t_2))
		{
			rec->t = t;
			rec->normal = ft_vec3d_negative(cylinder->orientation_vector);
		}
	}
	rec->p = ft_ray_at(ray, rec->t);
	return (1);
}
/*
   h = h^
   i 0, 1, 2
   abc { a, b, c }
 */
static double	ft_check_discriminant(double abc[3], t_camera *camera, t_ray * ray, t_vec3d h)
{
	double	discriminant;
	double	sqrtd;
	double	t;
	double	t_v2;
					/* b^2 - 4ac*/
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (NAN);		/* v^ · h^ != 1*/
	if (discriminant == 0 && ft_vec3d_dot(ft_vec3d_unit_lenght(ray->direction), h) != 1)
		/* -b / 2a */
		return (-abc[1] / (2 * abc[0]));
	sqrtd = sqrt(discriminant);
	/*(-b - sqrtd) / 2a*/
	t = (-abc[1] - sqrtd) / (2 * abc[0]);
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
		if (t_v2 > camera->t_min && camera->t_max > t_v2 && t > t_v2)
			return (t_v2);
	}
	return (t);
}

/*vector = H*/
/*v = ray->direction*/
static double	ft_calculate_coefficients(t_ray *ray, t_element *cylinder,
		t_camera *camera, t_vec3d vector)
{
	t_vec3d	h;
	t_vec3d	w;
	double	abc[3];

	w = ft_vec3d_minus_vec3d(ray->origin, cylinder->coords);
	/* h = H - C; h = h^*/
	h = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(vector, cylinder->coords));
	/* a = v · v - (v · h^)^2*/
	abc[0] = ft_vec3d_dot(ray->direction, ray->direction) - pow(ft_vec3d_dot(ray->direction, h), 2);
	/* b = (v · w) - v · h^ * w · h^ */
	abc[1] = 2 * (ft_vec3d_dot(ray->direction, w)
			- ft_vec3d_dot(ray->direction, h) * ft_vec3d_dot(w, h));
	/* c = w · w - (w · h^)^2 - r^2*/
	abc[2] = ft_vec3d_dot(w, w) - pow(ft_vec3d_dot(w, h), 2) -
		(cylinder->radius * cylinder->radius);
	return (ft_check_discriminant(abc, camera, ray, h));
}

int	ft_hit_cylinder(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cylinder)
{
	double	intersect;
	double	len_h;
	double	q;
	t_vec3d	h;

	/* h = H */
	h = ft_vec3d_plus_vec3d(cylinder->coords,
			ft_vec3d_pro_double(ft_vec3d_unit_lenght(cylinder->orientation_vector), cylinder->height));
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
		/*intersection on the cylinder surface*/
		q = sqrt(cylinder->radius *  cylinder->radius +
		ft_vec3d_squared_len(ft_vec3d_minus_vec3d(cylinder->coords, rec->p))); 
		h = ft_vec3d_plus_vec3d(cylinder->coords, ft_vec3d_pro_double(
					ft_vec3d_unit_lenght(cylinder->orientation_vector),
					q));
		rec->normal = ft_vec3d_minus_vec3d(rec->p, h);
		rec->normal = ft_vec3d_minus_vec3d(rec->p, h);
		//rec->normal = cylinder->orientation_vector;
		return (1);
	}
	else
		return (ft_base_of_the_cylinder(ray, camera, rec, cylinder));
}
