/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:11:08 by alvjimen          #+#    #+#             */
/*   Updated: 2023/09/07 16:17:46 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/* h = height */
/* ratio = hipotenusa_prima / hipotenusa */
static double	ft_calculate_height_on_axis(t_hit_record *rec,
		t_element *cylinder, t_vec3d h)
{
	t_vec3d	q;
	t_vec3d	t;
	t_vec3d	ph;
	double	hipotenusa;
	double	hipotenusa_prima;

	q = ft_vec3d_minus_vec3d(cylinder->coords,
			ft_init_vec3d(cylinder->radius, 0, 0));
	t = ft_vec3d_plus_vec3d(cylinder->coords, h);
	hipotenusa = ft_vec3d_len(ft_vec3d_minus_vec3d(q, t));
	ph = ft_vec3d_minus_vec3d(t, rec->p);
	hipotenusa_prima = hipotenusa - ft_vec3d_len(ph);
	return (cylinder->height * (hipotenusa_prima / hipotenusa));
}

void	ft_normal_cone(t_hit_record *rec, t_element *cylinder, t_ray *ray)
{
	t_vec3d	h;

	rec->p = ft_ray_at(ray, rec->t);
	h = ft_vec3d_pro_double(cylinder->orientation_vector, cylinder->height);
	rec->q = ft_calculate_height_on_axis(rec, cylinder, h);
	rec->h = ft_vec3d_plus_vec3d(cylinder->coords, ft_vec3d_pro_double(
				ft_vec3d_unit_lenght(cylinder->orientation_vector),
				rec->q));
	if (rec->q == cylinder->height)
		rec->normal = cylinder->orientation_vector;
	else
		rec->normal = ft_vec3d_unit_lenght(
				ft_vec3d_minus_vec3d(rec->p, rec->h));
}

int	ft_base_of_the_cone(t_ray *ray, t_camera *camera,
		t_hit_record *rec, t_element *cone)
{
	double	t;

	t = ft_hit_surface_base(ray, camera, cone, rec);
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
