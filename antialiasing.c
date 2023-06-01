/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:42:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/01 17:42:56 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/*
double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (max < x)
		return (max);
	return (x);
}

int	ft_color_double_to_int_v2(double c)
{
	return (c * 256);
}

int	ft_color_vector_to_int_v2(t_vec3d v)
{
	return (ft_color_double_to_int_v2(clamp(v.x, 0.0, 0.999)) << 16
			| ft_color_double_to_int_v2(clamp(v.y, 0.0, 0.999)) << 8
			| ft_color_double_to_int_v2(clamp(v.z, 0.0, 0.999)));
}

int	ft_write_color(t_vec3d vector, int samplex_per_pixel)
{
	vector = ft_vec3d_div_double(vector, samplex_per_pixel);
	return (ft_color_vector_to_int(vector));
}
*/

t_vec3d	ft_ray_direction_v2(t_data *img, int x, int y)
{
	t_vec3d	direction;
	double	u;
	double	v;

	u = (x + pseudo_random()) / (img->image_width - 1);
	v = (y + pseudo_random()) / (img->image_height - 1);
	direction = ft_init_vec3d((img->camera->lower_left_corner.x
				+ (u * img->camera->viewport_width) - img->camera->origin.x),
			(img->camera->lower_left_corner.y - img->camera->origin.y
				+ (v * img->camera->viewport_height)),
			(img->camera->lower_left_corner.z - img->camera->origin.z));
	return (direction);
}

t_vec3d	ft_ray_color_v3(t_ray *ray, t_data *img)
{
	t_hit_record	rec;
	double			t;

	if (ft_hittable(ray, img->camera, &rec, img->world))
		return (rec.normal);
	t = 0.5 * (ray->unit_direction.y + 1.0);
	return (ft_init_vec3d((1.0 - t) + t * 0.5, (1.0 - t) + t * 0.7, 1.0));
}

int	ft_antialiasing(t_data *img, int x, int y)
{
	t_ray	ray;
	t_vec3d	vector;
	t_vec3d	acum;
	int		samples;

	samples = 0;
	ft_bzero(&acum, sizeof(acum));
	while (samples++ < img->samplex_per_pixel)
	{
		vector = ft_ray_direction_v2(img, x, img->image_height - (y + 1));
		ray = ft_init_ray(img->camera->origin, vector);
		acum = ft_vec3d_plus_vec3d(acum, ft_ray_color_v3(&ray, img));
	}
	return (ft_write_color(acum, img->samplex_per_pixel));
}

void	ft_draw_background_v3(t_data *img)
{
	int		x;
	int		y;
	int		colour;

	y = 0;
	while (y < img->image_height)
	{
		x = 0;
		while (x < img->image_width)
		{
			colour = ft_antialiasing(img, x, y);
			my_mlx_pixel_put(img, x, y, colour);
			x++;
		}
		y++;
	}
}
