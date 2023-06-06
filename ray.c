/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:56:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/30 18:46:04 by alvjimen         ###   ########.fr       */
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

	point = ft_vec3d_plus_vec3d(ray->origin, ft_vec3d_pro_double(ray->direction,
				t));
	return (point);
}

/*camera get_ray*/
t_vec3d	ft_ray_direction(t_data *img, int x, int y)
{
	t_vec3d	direction;
	double	u;
	double	v;

	u = ((double)x / (img->image_width - 1));
	v = ((double)y / (img->image_height - 1));
	direction = ft_init_vec3d((img->camera->lower_left_corner.x
				+ (u * img->camera->viewport_width) - img->camera->origin.x),
			(img->camera->lower_left_corner.y - img->camera->origin.y
				+ (v * img->camera->viewport_height)),
			(img->camera->lower_left_corner.z - img->camera->origin.z));
	return (direction);
}

t_vec3d	ft_ray_direction_v3(t_data *img, int x, int y)
{
	t_vec3d	direction;
	double	s;
	double	t;

	s = ((double)x / (img->image_width - 1));
	t = ((double)y / (img->image_height - 1));
	direction = ft_vec3d_minus_vec3d(ft_vec3d_plus_vec3d(img->camera->lower_left_corner, ft_vec3d_plus_vec3d(ft_vec3d_pro_double(img->camera->horizontal, s), ft_vec3d_pro_double(img->camera->vertical, t))), img->camera->origin);
	return (direction);
}
/*
int	ft_ray_color(t_ray *ray)
{
	double		t;
	int			colour;
	t_vec3d		center_sphere = {.x=0,.y=0,.z=-1};
	t_vec3d		vector_normal;
	t_vec3d		unit_vector_normal;

	t = ft_hit_sphere(&center_sphere, 1, ray); 
	if (t > 0.0)
	{
		vector_normal = ft_vec3d_minus_vec3d(ft_ray_at(ray, t), center_sphere);
		unit_vector_normal = ft_vec3d_unit_lenght(vector_normal);
		colour = ft_color_double_to_int(0.5 * (unit_vector_normal.x + 1)) << 16
			| ft_color_double_to_int(0.5 * (unit_vector_normal.y + 1)) << 8
			| ft_color_double_to_int(0.5 * (unit_vector_normal.z + 1));
		return (colour);
	}
	t = 0.5 * (ray->unit_direction.y + 1.0);
	colour = ft_color_double_to_int((1.0 - t) + t * 0.5) << 16
		| ft_color_double_to_int((1.0 - t) + t * 0.7) << 8
		| ft_color_double_to_int(1.0);
	return (colour);
}
*/

int	ft_ray_color_v2(t_ray *ray, t_data *img)
{
	t_hit_record	rec;
	double			t;
	int				colour;

	if (ft_hittable(ray, img->camera, &rec, img->world))
	{
		colour = ft_color_double_to_int((rec.normal.x + 1) * 0.5) << 16
			| ft_color_double_to_int((rec.normal.y + 1) * 0.5) << 8
			| ft_color_double_to_int((rec.normal.z + 1) * 0.5);
		colour = ft_color_vector_to_int(rec.normal);
		return (colour);
	}
	t = 0.5 * (ray->unit_direction.y + 1.0);
	return (ft_color_double_to_int((1.0 - t) + t * 0.5) << 16
		| ft_color_double_to_int((1.0 - t) + t * 0.7) << 8
		| ft_color_double_to_int(1.0));
}
