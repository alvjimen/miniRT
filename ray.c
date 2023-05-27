/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:56:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/26 13:57:45 by alvjimen         ###   ########.fr       */
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
	return (ptr);
}

void	ft_destroy_ray(t_ray *ray)
{
	free(ray->direction);
	free(ray);
}

t_vec3d	*ft_ray_at(t_ray *ray, double t)
{
	t_vec3d	*pro;
	t_vec3d	*value;

	if (!ray)
		return (NULL);
	pro = ft_vec3d_pro_double(ray->direction, t);
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
	direction = ft_init_vec3d(-(img->camera->lower_left_corner->x
			+ (u * img->camera->viewport_width) - img->camera->origin->x),
			-(img->camera->lower_left_corner->y +(v * img->camera->viewport_height)
			- img->camera->origin->y),
			-(img->camera->lower_left_corner->z - img->camera->origin->z));
	return (direction);
}

int	ft_ray_color(t_ray *ray)
{
	t_vec3d		*unit_direction;
	double		t;
	int			colour;
	t_vec3d		center_sphere = {.x=0,.y=0,.z=-1};
	t_vec3d		*point_intersection;
	t_vec3d		*normal_vector;

	t = ft_hit_sphere(&center_sphere, 1, ray); 
	if (t > 0.0)
	{
		point_intersection = ft_ray_at(ray, t);
		point_intersection->z -= 1.0;
		normal_vector = ft_vec3d_unit_lenght(point_intersection);
		free(point_intersection);
		colour = ft_color_double_to_int(0.5 * (normal_vector->x + 1)) << 16 |
			ft_color_double_to_int(0.5 * (normal_vector->y + 1)) << 8|
			ft_color_double_to_int(0.5 * (normal_vector->z + 1));
		free(normal_vector);
		return (colour);
	}
	unit_direction = ft_vec3d_unit_lenght(ray->direction);
	t = 0.5 * (unit_direction->y + 1.0);
	free(unit_direction);
	colour = ft_color_double_to_int((1.0 - t) + t * 0.5) << 16
		| ft_color_double_to_int((1.0 - t) + t * 0.7) << 8
		| ft_color_double_to_int(1.0);
	return (colour);
}
/* this is just for draw a sphere no normals
int	ft_ray_color(t_ray *ray)
{
	t_vec3d		*unit_direction;
	double		t;
	int			colour;
	t_vec3d		center_sphere = {.x=0,.y=0,.z=-1};

	if (ft_hit_sphere(&center_sphere, 1, ray))
		return (255 << 16);
	unit_direction = ft_vec3d_unit_lenght(ray->direction);
	t = 0.5 * (unit_direction->y + 1.0);
	free(unit_direction);
	colour = ft_color_double_to_int((1.0 - t) + t * 0.5) << 16
		| ft_color_double_to_int((1.0 - t) + t * 0.7) << 8
		| ft_color_double_to_int(1.0);
	return (colour);
}
*/
