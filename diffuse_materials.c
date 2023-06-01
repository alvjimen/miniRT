/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_materials.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:50:28 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/01 18:46:12 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_write_color_v2(t_vec3d vector, int samplex_per_pixel)
{
	vector = ft_vec3d_div_double(vector, samplex_per_pixel);
	//this is for gamma 2
	//vector.x = sqrt(vector.x);
	//vector.y = sqrt(vector.y);
	//vector.z = sqrt(vector.z);
	return (ft_color_vector_to_int(vector));
}

t_vec3d	ft_vec3d_random(double min, double max)
{
	return (ft_init_vec3d(random_double(min, max), random_double(min, max),
			random_double(min, max)));
}

t_vec3d	random_in_unit_sphere(void)
{
	t_vec3d	vector;

	while (1)
	{
		vector = ft_vec3d_random(-1, 1);
		if (ft_vec3d_squared_len(vector) >= 1)
			continue ;
		return (vector);
	}
	return (vector);
}

t_vec3d	random_in_unit_length_sphere(void)
{
	t_vec3d	vector;

	while (1)
	{
		vector = ft_vec3d_random(-1, 1);
		if (ft_vec3d_squared_len(vector) >= 1)
			continue ;
		return (ft_vec3d_unit_lenght(vector));
	}
	return (ft_vec3d_unit_lenght(vector));
}

t_vec3d	ft_ray_color_v4(t_ray ray, t_data *img, int depth)
{
	t_hit_record	rec;
	double			t;
	t_vec3d			vector;

	if (depth <= 0)
		return (ft_init_vec3d(0, 0, 0));
	if (ft_hittable(&ray, img->camera, &rec, img->world))
	{
		vector = ft_vec3d_plus_vec3d(rec.p, ft_vec3d_plus_vec3d(rec.normal,
					random_in_unit_sphere()));
		return (ft_vec3d_pro_double(ft_ray_color_v4(
							ft_init_ray(rec.p, ft_vec3d_minus_vec3d(vector,
									rec.p)), img, depth - 1), 0.5));
	}
	t = 0.5 * (ray.unit_direction.y + 1.0);
	return (ft_init_vec3d((1.0 - t) + t * 0.5,
		((1.0 - t) + t * 0.7), 1.0));
}

int	ft_antialiasing_v2(t_data *img, int x, int y)
{
	t_ray	ray;
	t_vec3d	vector;
	t_vec3d	acum;
	int		samples;

	samples = 0;
	img->max_depth = 50;
	ft_bzero(&acum, sizeof(acum));
	while (samples++ < img->samplex_per_pixel)
	{
		vector = ft_ray_direction_v2(img, x, img->image_height - (y + 1));
		ray = ft_init_ray(img->camera->origin, vector);
		acum = ft_vec3d_plus_vec3d(acum, ft_ray_color_v4(ray, img,
					img->max_depth));
	}
	return (ft_write_color_v2(acum, img->samplex_per_pixel));
}

void	ft_draw_background_v4(t_data *img)
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
			colour = ft_antialiasing_v2(img, x, y);
			my_mlx_pixel_put(img, x, y, colour);
			x++;
		}
		y++;
	}
}
