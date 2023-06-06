/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:56:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/06 16:13:19 by alvjimen         ###   ########.fr       */
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
t_vec3d	ft_ray_direction(t_data *img, double s, double t)
{
	return (ft_vec3d_minus_vec3d(ft_vec3d_plus_vec3d(
				img->camera.lower_left_corner, ft_vec3d_plus_vec3d(
					ft_vec3d_pro_double(img->camera.horizontal, s),
					ft_vec3d_pro_double(img->camera.vertical, t))),
			img->camera.origin));
}

t_vec3d	ft_ray_color(t_ray *ray, t_data *img)
{
	t_hit_record	rec;
	double			t;

	if (ft_hittable(ray, &img->camera, &rec, img->world))
		return (rec.normal);
	t = 0.5 * (ray->unit_direction.y + 1.0);
	return (ft_init_vec3d((1.0 - t) + t * 0.5, (1.0 - t) + t * 0.7, 1.0));
}
