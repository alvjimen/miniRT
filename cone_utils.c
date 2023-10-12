/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:11:08 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/07 18:10:12 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/* h = height */
/* ratio = hipotenusa_prima / hipotenusa */
static double	ft_calculate_height_on_axis(t_hit_record *rec,
		t_element *cone, t_vec3d h)
{
	const t_vec3d	q = ft_vec3d_minus_vec3d(cone->coords,
			ft_init_vec3d(cone->radius, 0, 0));
	const t_vec3d	t = ft_vec3d_plus_vec3d(cone->coords, h);
	const t_vec3d	ph = ft_vec3d_minus_vec3d(t, rec->p);
	double			hipotenusa;
	double			hipotenusa_prima;

	hipotenusa = ft_vec3d_len(ft_vec3d_minus_vec3d(q, t));
	hipotenusa_prima = hipotenusa - ft_vec3d_len(ph);
	return (cone->height * (hipotenusa_prima / hipotenusa));
}

void	ft_normal_cone(t_hit_record *rec, t_element *cone, t_ray *ray)
{
	const t_vec3d	h = ft_vec3d_pro_double(cone->orientation_vector,
			cone->height);

	rec->p = ft_ray_at(ray, rec->t);
	rec->q = ft_calculate_height_on_axis(rec, cone, h);
	rec->h = ft_vec3d_plus_vec3d(cone->coords, ft_vec3d_pro_double(
				cone->orientation_vector, rec->q));
	if (rec->q == cone->height)
		rec->normal = cone->orientation_vector;
	else
		rec->normal = ft_vec3d_unit_lenght(
				ft_vec3d_minus_vec3d(rec->p, rec->h));
}

int	ft_base_of_the_cone(t_ray *ray, t_camera *camera,
		t_hit_record *rec, t_element *cone)
{
	const double	t = ft_hit_surface_base(ray, camera, cone, rec);

	if (isnan(t))
		return (0);
	rec->t = t;
	rec->normal = ft_vec3d_negative(cone->orientation_vector);
	rec->p = ft_ray_at(ray, rec->t);
	rec->q = 0.0;
	rec->h = cone->coords;
	ft_cone_uv(rec, cone);
	return (1);
}
