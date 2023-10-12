/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:01:19 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/07 18:16:24 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	ft_hit_surface_base(t_ray *ray, t_camera *camera, t_element *cylinder,
		t_hit_record *rec)
{
	const t_vec3d	nov = ft_vec3d_negative(cylinder->orientation_vector);
	const double	denom = ft_vec3d_dot(nov, ray->direction);
	double			t;
	t_vec3d			p_c;
	t_vec3d			p;

	if (ft_dabs(denom) <= 0.001)
		return (NAN);
	t = ft_vec3d_dot(nov, ft_vec3d_minus_vec3d(cylinder->coords, ray->origin))
		/ denom;
	if (t < camera->t_min || t > camera->t_max || isnan(t))
		return (NAN);
	p = ft_ray_at(ray, t);
	p_c = ft_vec3d_minus_vec3d(p, cylinder->coords);
	if (ft_vec3d_len(p_c) > cylinder->radius)
		return (NAN);
	rec->p = p;
	return (t);
}

double	ft_hit_surface_top(t_ray *ray, t_camera *camera, t_element *cylinder,
		t_hit_record *rec)
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
	if (ft_vec3d_len(p_c) > cylinder->radius)
		return (NAN);
	rec->p = p;
	return (t);
}

int	ft_base_of_the_cylinder(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cylinder)
{
	const double	t = ft_hit_surface_base(ray, camera, cylinder, rec);
	const t_vec3d	h = ft_vec3d_plus_vec3d(cylinder->coords,
			ft_vec3d_pro_double(
				cylinder->orientation_vector, cylinder->height));
	double			t_2;

	rec->p = h;
	t_2 = ft_hit_surface_top(ray, camera, cylinder, rec);
	if (isnan(t) && isnan(t_2))
		return (0);
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
	rec->p = ft_ray_at(ray, rec->t);
	return (1);
}
