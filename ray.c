/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:56:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 19:40:50 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ft_init_ray(t_vec3d origin, t_vec3d direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.unit_direction = ft_vec3d_unit_lenght(ray.direction);
	return (ray);
}

t_vec3d	ft_ray_at(t_ray *ray, double t)
{
	t_vec3d	point;
	t_vec3d	vector;

	vector = ft_vec3d_pro_double(ray->direction, t);
	point = ft_vec3d_plus_vec3d(ray->origin, vector);
	return (point);
}

/* This is a readable */
t_vec3d	ft_ray_direction(t_data *img, int x, int y, int antialiasing)
{
	double	s;
	double	t;
	t_vec3d	xy_p[2];
	t_vec3d	x_a_y_p;
	t_vec3d	display_point;

	if (!antialiasing)
	{
		s = ((double)(x) / (img->display.width - 1));
		t = ((double)(img->display.height - (y + 1))
				/ (img->display.height - 1));
	}
	else
	{
		s = (x + pseudo_random()) / (img->display.width - 1);
		t = (img->display.height - (y + 1) + pseudo_random())
			/ (img->display.height - 1);
	}
	xy_p[0] = ft_vec3d_pro_double(img->camera.horizontal, s);
	xy_p[1] = ft_vec3d_pro_double(img->camera.vertical, t);
	x_a_y_p = ft_vec3d_plus_vec3d(xy_p[0], xy_p[1]);
	display_point = ft_vec3d_plus_vec3d(img->camera.lower_left_corner, x_a_y_p);
	return (ft_vec3d_minus_vec3d(display_point, img->camera.origin));
}

//TODO Renombrar la función si no te cuadra 
//mir = mirror
//c = color
//bl = bounce_light
//rc = rec
static t_vec3d	get_color(t_vec3d *c, t_vec3d bl, t_hit_record rc, t_vec3d mir)
{
	*c = ft_vec3d_plus_vec3d(*c,
			ft_vec3d_pro_double(bl, 0));
	*c = ft_color_merge(*c, mir, 1 - rc.reflection_index,
			rc.reflection_index);
	return (*c);
}

t_vec3d	ft_ray_color(t_ray *ray, t_data *img, int bounce)
{
	t_hit_record	rec;
	t_element		*element;
	t_vec3d			color;
	t_vec3d			mirror;

	if (img->mirror_limit <= 0 || bounce <= 0)
		return (ft_init_vec3d(0, 0, 0));
	ft_bzero(&rec, sizeof(rec));
	element = ft_hittable_element(ray, img, &rec);
	ft_hit_face(ray, &rec);
	if (!element)
		return (ft_init_vec3d(0, 0, 0));
	else if (element->textured)
		element->ft_texture(&rec, element, img);
	rec.bounce = bounce;
	color = img->ft_color(&rec, ray, img);
	if (rec.reflection_index == 0)
		return (ft_vec3d_plus_vec3d(color,
				ft_vec3d_pro_double(bounce_light(&rec, img, bounce), 0)));
	else if (rec.reflection_index == 1)
		return (ft_colour_to_vec3d(rec.mirror_color));
	mirror = ft_colour_to_vec3d(rec.mirror_color);
	color = get_color(&color, bounce_light(&rec, img, bounce), rec, mirror);
	return (color);
}

/*	Esto es commo estaba antes de sustituirla por la función kk a renombrar
	una vez probado que funciona correctamente y que no he metido la pata.

	color = ft_vec3d_plus_vec3d(color,
			ft_vec3d_pro_double(bounce_light(&rec, img, bounce), 0));
	color = ft_color_merge(color, mirror, 1 - rec.reflection_index,
			rec.reflection_index);
*/