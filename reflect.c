/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:03:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 12:01:51 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO del this func del her prototype minirt.h
/*
t_vec3d	ft_color_mirror(const t_hit_record *rec, const t_ray *ray, t_data *img)
{
	const t_vec3d	direction = reflect(ray->direction, rec->normal);
	t_ray			new_ray;
	t_vec3d			tmp;

	ft_bzero(&colour, sizeof(colour));
	new_ray = ft_init_ray(rec->p, direction);
	img->mirror_limit--;
	img->camera.t_min = 0.00001;
	return (ft_ray_color(&new_ray, img));
}
*/

t_colour	ft_color_mirror(const t_hit_record *rec, const t_ray *ray, t_data *img)
{
	const t_vec3d	direction = reflect(ray->direction, rec->normal);
	t_ray			new_ray;
	t_vec3d			tmp;
	t_colour		colour;

	ft_bzero(&colour, sizeof(colour));
	new_ray = ft_init_ray(rec->p, direction);
	img->mirror_limit--;
	img->camera.t_min = 0.00001;
	tmp = ft_ray_color(&new_ray, img, 3);
	colour.red = (char)(clamp(tmp.x, 0, 1) * 255);
	colour.green = (char)(clamp(tmp.y, 0, 1) * 255);
	colour.blue = (char)(clamp(tmp.z, 0, 1) * 255);
	return (colour);
}

t_vec3d	ft_color_merge(t_vec3d color1, t_vec3d color2,  double ratio1,
	double ratio2)
{
	t_vec3d	color;
	t_vec3d	tmp;

	color = ft_vec3d_pro_double(color1, ratio1);
	tmp = ft_vec3d_pro_double(color2, ratio2);
	color = ft_vec3d_plus_vec3d(color, tmp);
	return (color);
}

t_vec3d	reflect(t_vec3d vector_n, t_vec3d normal_n)
{
	t_vec3d		reflect;
	double		mylen;

	if (ft_vec3d_squared_len(vector_n) != 1)
		vector_n = ft_vec3d_unit_lenght(vector_n);
	if (ft_vec3d_squared_len(normal_n) != 1)
		normal_n = ft_vec3d_unit_lenght(normal_n);
	mylen = 2.0 * ft_vec3d_dot(vector_n, normal_n);
	reflect = ft_vec3d_pro_double(normal_n, mylen);
	reflect = ft_vec3d_minus_vec3d(vector_n, reflect);
	return (reflect);
}
