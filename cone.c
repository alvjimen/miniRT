/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:20:39 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 13:27:52 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
   h = h^
   i	0, 1, 2
   abc { a, b, c }
 */
// h_v_n  
// _v vector
// _n normalize == unit_length
// raw = {-255, 255}
static double	ft_check_discriminant(double abc[3], t_camera *camera,
		t_ray *ray, t_vec3d h)
{
	double	discriminant;
	double	sqrtd;
	double	t;

	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (NAN);
	if (discriminant == 0 && ft_vec3d_dot(ray->unit_direction, h) != 1)
		return (-abc[1] / (2 * abc[0]));
	sqrtd = sqrt(discriminant);
	t = (-abc[1] - sqrtd) / (2 * abc[0]);
	if (t < camera->t_min || camera->t_max < t)
	{
		t = (-abc[1] + sqrtd) / (2 * abc[0]);
		if (t < camera->t_min || camera->t_max < t)
			return (NAN);
	}
	return (t);
}

/*ph = H*/
/*v = ray->direction*/
/* m = r^2 / ||h||^2*/
/* a = v · v - (v · h^)^2*/
/* b = (v · w) - v · h^ * w · h^ */
/* c = w · w - (w · h^)^2 - r^2*/
static double	ft_calculate_coefficients(t_ray *ray, t_element *cone,
		t_camera *camera, t_vec3d top_co)
{
	const t_vec3d	w = ft_vec3d_minus_vec3d(ray->origin, top_co);
	const double	m = (cone->radius * cone->radius)
		/ (cone->height * cone->height);
	double			abc[3];

	abc[0] = ft_vec3d_dot(ray->direction, ray->direction) - (m + 1) * pow(
			ft_vec3d_dot(ray->direction, cone->orientation_vector), 2);
	abc[1] = 2 * (ft_vec3d_dot(ray->direction, w) - (m + 1)
			* (ft_vec3d_dot(ray->direction, cone->orientation_vector)
				* ft_vec3d_dot(w, cone->orientation_vector)));
	abc[2] = ft_vec3d_dot(w, w) - (m + 1) * pow(ft_vec3d_dot(w,
				cone->orientation_vector), 2);
	return (ft_check_discriminant(abc, camera, ray,
			cone->orientation_vector));
}

/* intersect = (Lint - C) · h -> rec->p - cone->coords · h*/
/* rec->h  height_v */
static int	ft_calculate_intersection(t_hit_record *rec, t_element *cone,
		t_ray *ray, t_camera *camera)
{
	double	intersect;
	double	len_h;
	double	t;

	intersect = ft_vec3d_dot(ft_vec3d_minus_vec3d(rec->p, cone->coords),
			rec->h);
	len_h = ft_vec3d_len(rec->h);
	if (0.0 <= intersect && intersect <= len_h * len_h)
	{
		t = rec->t;
		ft_base_of_the_cone(ray, camera, rec, cone);
		if (!isnan(rec->t) && t > rec->t)
			return (1);
		rec->t = t;
		ft_normal_cone(rec, cone, ray);
		ft_cone_uv(rec, cone);
		ft_hit_face(ray, rec);
		return (1);
	}
	return (ft_base_of_the_cone(ray, camera, rec, cone));
}

int	ft_hit_cone(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cone)
{
	const t_vec3d	top_co = ft_vec3d_plus_vec3d(cone->coords,
			ft_vec3d_pro_double(cone->orientation_vector, cone->height));
	const t_vec3d	height_v = ft_vec3d_minus_vec3d(top_co, cone->coords);

	rec->t = ft_calculate_coefficients(ray, cone, camera, top_co);
	if (isnan(rec->t))
		return (0);
	rec->p = ft_ray_at(ray, rec->t);
	rec->h = height_v;
	return (ft_calculate_intersection(rec, cone, ray, camera));
}
