/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:56:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/27 18:53:34 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_ray	ft_init_ray(t_vec3d origin, t_vec3d direction)
{
	t_ray	ptr;

	ptr.origin = origin;
	ptr.direction = direction;
	ptr.unit_direction = ft_vec3d_unit_lenght(ptr.direction);
	return (ptr);
}

t_vec3d	ft_ray_at(t_ray *ray, double t)
{
	t_vec3d	point;

	point = ft_vec3d_plus_vec3d(ray->origin,
			ft_vec3d_pro_double(ray->direction, t));
	return (point);
}

/*camera get_ray*/
t_vec3d	ft_ray_direction(t_data *img, int x, int y, int flag)
{
	double	s;
	double	t;

	if (!flag)
	{
		s = ((double)(x) / (img->image_width - 1));
		t = ((double)(img->image_height - (y + 1)) / (img->image_height - 1));
	}
	else
	{
		s = (x + pseudo_random()) / (img->image_width - 1);
		t = (img->image_height - (y + 1) + pseudo_random())
			/ (img->image_height - 1);
	}
	return (ft_vec3d_minus_vec3d(ft_vec3d_plus_vec3d(
				img->camera.lower_left_corner, ft_vec3d_plus_vec3d(
					ft_vec3d_pro_double(img->camera.horizontal, s),
					ft_vec3d_pro_double(img->camera.vertical, t))),
			img->camera.origin));
}

/*t_vec3d	ft_ray_color(t_ray *ray, t_data *img)
{
	t_hit_record	rec;
	int				depth;

	depth = 1;
	if (depth <= 0)
		return (ft_init_vec3d(0, 0, 0));
	ft_bzero(&rec, sizeof(rec));
	if (!ft_hittable(ray, &img->camera, &rec, img->world))
		return (ft_init_vec3d(0, 0, 0));
	*/
	/* rec.colour + specular + diffuse + ambient*/
	/* specular + diffuse + ambient */
	/*
	return (ft_vec3d_div_double(ft_vec3d_plus_vec3d(
						ft_vec3d_plus_vec3d(ft_colour_to_vec3d(rec.colour),
					ft_calculate_lights(&rec, ray, img, ft_specular_light)),
					ft_calculate_lights(&rec, ray, img, ft_diffuse_light)),
					//ft_ambient_light(img)
					3));
					*/
			/* ft_calculate_lights(&rec, ray, img, ft_specular_light) + ft_ambient_light(img))));*/
//}
