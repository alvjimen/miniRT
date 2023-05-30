/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:17:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/29 08:56:30 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_hit_face(t_ray *ray, t_hit_record *rec)
{
	rec->front_face  = ft_vec3d_dot(ray->direction, rec->normal) < 0.0;
	if (!rec->front_face)
		rec->normal = ft_vec3d_negative(rec->normal);
}

double	ft_root_sphere(t_vec3d *oc, t_ray *ray, t_camera  *camera,
		t_element *sphere)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	t;

	a = ft_vec3d_squared_len(ray->direction);
	half_b = ft_vec3d_dot(*oc, ray->direction);
	c = ft_vec3d_squared_len(*oc) - ((sphere->diameter * sphere->diameter) / 4);

	discriminant = half_b * half_b - a * c;
	if (discriminant < 0.0)
		return (NAN);
	sqrtd = sqrt(discriminant);

	t = (-half_b - sqrtd) / a;
	if (t < 0.0/*camera->focal_length*/ || camera->t_max < t)
	{
		t = (-half_b + sqrtd) / a;
		if (t < 0.0/*camera->focal_length*/ || camera->t_max < t)
			return (NAN);
	}
	return (t);
}

int	ft_hit_sphere_v2(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *sphere)
{
	t_vec3d	oc;

	oc = ft_vec3d_minus_vec3d(ray->origin, sphere->coords);
	rec->t = ft_root_sphere(&oc, ray, camera, sphere);
	if (isnan(rec->t))
		return (0);
	rec->p = ft_ray_at(ray, rec->t);
	/*unit_lenght_for then colour*/
	rec->normal = ft_vec3d_div_double(ft_vec3d_minus_vec3d(rec->p, sphere->coords),
			(sphere->diameter / 2));
	ft_hit_face(ray, rec);
	return (1);
}

int	ft_hittable(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_list *world)
{
	int				hit_anything;
	t_hit_record	tmp_rec;
	double			bk_tmax;
	t_element		*element;

	hit_anything = 0;
	bk_tmax = camera->t_max;
	while (world)
	{
		element = world->content;
		world = world->next;
		if (!element)
			continue ;
		if (element->ft_hit && element->ft_hit(ray, camera, &tmp_rec, element))
		{
			hit_anything = 1;
			camera->t_max = tmp_rec.t;
			*rec = tmp_rec;
		}
	}
	camera->t_max = bk_tmax;
	return (hit_anything);
}

int	ft_ray_color_v2(t_ray *ray, t_data *img)
{
	t_hit_record	rec;
	double			t;
	int				colour;

	if (ft_hittable(ray, img->camera, &rec, img->world))
	{
		colour = ft_color_double_to_int((rec.normal.x + 1) * 0.5) << 16 |
			ft_color_double_to_int((rec.normal.y + 1) * 0.5) <<  8 |
			ft_color_double_to_int((rec.normal.z + 1) * 0.5);
		return (colour);
	}
	t = 0.5 * (ray->unit_direction.y + 1.0);
	return (ft_color_double_to_int((1.0 - t) + t * 0.5) << 16
		| ft_color_double_to_int((1.0 - t) + t * 0.7) << 8
		| ft_color_double_to_int(1.0));
}
