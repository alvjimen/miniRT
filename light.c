/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:10:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/07/08 18:49:16 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://www.cs.cornell.edu/courses/cs4620/2017sp/slides/05rt-shading.pdf
#include "minirt.h"

static double	ft_max(double n1, double n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

/*
for calcule the ambient ratio illumination u should take the main source of
light (the brightess) and multiplicate with ambient ratio
ks == light->light_ratio
l == ft_vec3d_unit_lenght(r);
*/

t_vec3d	ft_ambient_light(t_hit_record *rec, t_data *img)
{
	t_vec3d	colour;

	colour = ft_colour_to_vec3d(img->ambient_light.colour);
	if (rec)
		return (ft_vec3d_pro_double(colour,
				img->ambient_light.light_ratio));
	return (ft_vec3d_pro_double(colour, img->ambient_light.light_ratio));
}

t_vec3d	ft_diffuse_light(t_hit_record *rec, t_ray *ray, t_data *img,
		t_element *light)
{
	t_vec3d		v;
	t_vec3d		r;
	double		n_l;
	double		i_r2;
	double		result;

	result = 0;
	if (!ft_shadow_ray(rec, img, light))
		return (ft_vec3d_pro_double(ft_colour_to_vec3d(rec->colour), result));
	r = ft_vec3d_minus_vec3d(light->coords, rec->p);
	i_r2 = light->light_ratio / ft_vec3d_squared_len(r);
	n_l = ft_vec3d_dot(rec->normal, ft_vec3d_unit_lenght(r));
	result += 0.4 * i_r2 * ft_max(0, n_l);
	v = ft_colour_to_vec3d(light->colour);
	if (ray)
		return (ft_vec3d_pro_double(v, result));
	return (ft_vec3d_pro_double(v, result));
}

t_vec3d	ft_specular_light(t_hit_record *rec, t_ray *ray, t_data *img,
		t_element *light)
{
	t_vec3d		try;
	t_vec3d		h;
	t_vec3d		r;
	double		result;
	double		i_r2;

	result = 0;
	if (!ft_shadow_ray(rec, img, light))
		return (ft_vec3d_pro_double(ft_colour_to_vec3d(light->colour), result));
	r = ft_vec3d_minus_vec3d(light->coords, rec->p);
	i_r2 = light->light_ratio / ft_vec3d_squared_len(r);
	h = ft_vec3d_unit_lenght(ft_vec3d_plus_vec3d(ft_vec3d_negative(
					ray->direction), r));
	result = 0.5 * i_r2 * pow(ft_max(0, ft_vec3d_dot(rec->normal,
					h)), 1024);
	try = ft_colour_to_vec3d(light->colour);
	return (ft_vec3d_pro_double(try, result));
}
