/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:32:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 19:57:24 by dmacicio         ###   ########.fr       */
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

/*
   h = h^
   i 0, 1, 2
   abc { a, b, c }
 */

/* b^2 - 4ac*/
/*		 v^ · h^ != 1*/
/* -b / 2a */
/*(-b - sqrtd) / 2a*/
/*(-b + sqrtd) / 2a*/

//Lo he comentado para pasar la norminette, aplicando la condición dentro
//de la función (Línea 90 y 97)
// static int	ft_t_is_valid(double t, t_camera *camera)
// {
// 	return (!isnan(t) && t > camera->t_min && t < camera->t_max);
// }

//c = camera
static double	ft_check_discriminant(double abc[3], t_camera *c,
		t_ray *ray, t_vec3d h)
{
	const double	discriminant = (abc[1] * abc[1]) - (4 * abc[0] * abc[2]);
	double			sqrtd;
	double			t;
	double			t_2;

	if (discriminant < 0)
		return (NAN);
	if (discriminant == 0 && ft_vec3d_dot(ray->unit_direction, h) != 1)
		return (-abc[1] / (2 * abc[0]));
	sqrtd = sqrt(discriminant);
	t = (-abc[1] - sqrtd) / (2 * abc[0]);
	t_2 = (-abc[1] + sqrtd) / (2 * abc[0]);
	if ((!isnan(t) && t > c->t_min && t < c->t_max)
		&& (!isnan(t_2) && t_2 > c->t_min && t_2 < c->t_max))
	{
		if (t < t_2)
			return (t);
		return (t_2);
	}
	else if (!isnan(t) && t > c->t_min && t < c->t_max)
		return (t);
	return (t_2);
}

/*v = ray->direction*/
/* h = H - C; h = h^*/
/* a = v · v - (v · h^)^2*/
/* b = (v · w) - v · h^ * w · h^ */
/* c = w · w - (w · h^)^2 - r^2*/
static double	ft_calculate_coefficients(t_ray *ray, t_element *cylinder,
		t_camera *camera)
{
	const t_vec3d	h_u = cylinder->orientation_vector;
	const t_vec3d	w = ft_vec3d_minus_vec3d(ray->origin, cylinder->coords);
	double			abc[3];

	abc[0] = ft_vec3d_squared_len(ray->direction) - pow(ft_vec3d_dot(
				ray->direction, h_u), 2);
	abc[1] = 2 * (ft_vec3d_dot(ray->direction, w)
			- ft_vec3d_dot(ray->direction, h_u) * ft_vec3d_dot(w, h_u));
	abc[2] = ft_vec3d_dot(w, w) - pow(ft_vec3d_dot(w, h_u), 2)
		- (cylinder->radius * cylinder->radius);
	return (ft_check_discriminant(abc, camera, ray, h_u));
}

void	ft_normal_cylinder(t_hit_record *rec, t_element *cylinder)
{
	rec->q = ft_vec3d_squared_len(ft_vec3d_minus_vec3d(cylinder->coords,
				rec->p));
	rec->q = sqrt(rec->q - (cylinder->radius * cylinder->radius));
	rec->h = ft_vec3d_plus_vec3d(cylinder->coords, ft_vec3d_pro_double(
				ft_vec3d_unit_lenght(cylinder->orientation_vector),
				rec->q));
	rec->normal = ft_vec3d_minus_vec3d(rec->p, rec->h);
	ft_cylinder_uv(rec, cylinder);
}

/* h = h */
/* intersect = (Lint - C) · h -> rec->p - cylinder->coords · h*/
static int	ft_calculate_intersection(t_hit_record *rec, t_element *cylinder,
		t_ray *ray, t_camera *camera)
{
	const t_vec3d	h = ft_vec3d_pro_double(cylinder->orientation_vector,
			cylinder->height);
	const double	intersect = ft_vec3d_dot(ft_vec3d_minus_vec3d(rec->p,
				cylinder->coords), h);
	const double	len_h = cylinder->height;
	const double	t = rec->t;

	if (0.0 <= intersect && intersect <= len_h * len_h)
	{
		ft_base_of_the_cylinder(ray, camera, rec, cylinder);
		if (t > rec->t)
			return (1);
		rec->t = t;
		rec->p = ft_ray_at(ray, rec->t);
		ft_normal_cylinder(rec, cylinder);
		return (1);
	}
	return (ft_base_of_the_cylinder(ray, camera, rec, cylinder));
}

int	ft_hit_cylinder(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cylinder)
{
	rec->t = ft_calculate_coefficients(ray, cylinder, camera);
	if (isnan(rec->t))
		return (0);
	rec->p = ft_ray_at(ray, rec->t);
	return (ft_calculate_intersection(rec, cylinder, ray, camera));
}
