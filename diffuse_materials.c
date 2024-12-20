/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_materials.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:50:28 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/16 11:35:29 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_vec3d	random_on_hemisphere(t_vec3d normal)
{
	t_vec3d	on_unit_sphere;

	on_unit_sphere = random_in_unit_length_sphere();
	if (ft_vec3d_dot(on_unit_sphere, normal) > 0.0)
		return (on_unit_sphere);
	return (ft_vec3d_negative(on_unit_sphere));
}

t_vec3d	bounce_light(t_hit_record *rec, t_data *img)
{
	t_ray	ray;
	t_vec3d	color;

	ray = ft_init_ray(rec->p, rec->normal);
	color = ft_ray_color(&ray, img, rec->bounce - 1);
	return (ft_vec3d_div_double(color, 100));
}
