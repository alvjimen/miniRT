/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:56:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/29 08:10:14 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_ray	*ft_init_ray(t_vec3d *origin, t_vec3d *direction)
{
	t_ray	*ptr;

	if (!origin || !direction)
		return (NULL);
	ptr = malloc(sizeof(*ptr));
	if (!ptr)
		return (NULL);
	ptr->origin = origin;
	ptr->direction = direction;
	ptr->unit_direction = ft_vec3d_unit_lenght(direction);
	if (!ptr->unit_direction)
	{
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}

void	ft_destroy_ray(t_ray *ray)
{
	free(ray->direction);
	free(ray->unit_direction);
	free(ray);
}

t_vec3d	*ft_ray_at(t_ray *ray, double t)
{
	t_vec3d	*pro;
	t_vec3d	*value;

	if (!ray)
		return (NULL);
	pro = ft_vec3d_pro_double(ray->unit_direction, t);
	if (!pro)
		return (NULL);
	value = ft_vec3d_plus_vec3d(ray->origin, pro);
	free(pro);
	return (value);
}

t_vec3d	*ft_ray_direction(t_data *img, int x, int y)
{
	t_vec3d	*direction;
	double	u;
	double	v;

	u = ((double)x / (img->image_width - 1));
	v = ((double)y / (img->image_height - 1));
	direction = ft_init_vec3d((img->camera->lower_left_corner->x
				+ (u * img->camera->viewport_width) - img->camera->origin->x),
			(img->camera->lower_left_corner->y - img->camera->origin->y
				+ (v * img->camera->viewport_height)),
			(img->camera->lower_left_corner->z - img->camera->origin->z));
	return (direction);
}
/*direction -y*/

int	ft_ray_color(t_ray *ray)
{
	double		t;
	int			colour;
	t_vec3d		center_sphere = {.x=0,.y=0,.z=-1};
	t_vec3d		*point_intersection;
	t_vec3d		*vector_normal;
	t_vec3d		*unit_vector_normal;

	t = ft_hit_sphere(&center_sphere, 1, ray); 
	if (t > 0.0)
	{
		point_intersection = ft_ray_at(ray, t);
		if (!point_intersection)
			return (0);
		vector_normal = ft_vec3d_minus_vec3d(point_intersection, &center_sphere);
		free(point_intersection);
		unit_vector_normal = ft_vec3d_unit_lenght(vector_normal);
		free(vector_normal);
		if (!unit_vector_normal)
			return (0);
		colour = ft_color_double_to_int(0.5 * (unit_vector_normal->x + 1)) << 16 |
			ft_color_double_to_int(0.5 * (unit_vector_normal->y + 1)) << 8|
			ft_color_double_to_int(0.5 * (unit_vector_normal->z + 1));
		free(unit_vector_normal);
		return (colour);
	}
	t = 0.5 * (ray->unit_direction->y + 1.0);
	colour = ft_color_double_to_int((1.0 - t) + t * 0.5) << 16
		| ft_color_double_to_int((1.0 - t) + t * 0.7) << 8
		| ft_color_double_to_int(1.0);
	return (colour);
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
	t = 0.5 * (ray->unit_direction->y + 1.0);
	return (ft_color_double_to_int((1.0 - t) + t * 0.5) << 16
		| ft_color_double_to_int((1.0 - t) + t * 0.7) << 8
		| ft_color_double_to_int(1.0));
}
