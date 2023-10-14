/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:10:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/09 18:46:05 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://www.cs.cornell.edu/courses/cs4620/2017sp/slides/05rt-shading.pdf
#include "minirt.h"

/*
for calcule the ambient ratio illumination u should take the main source of
light (the brightess) and multiplicate with ambient ratio
ks == light->light_ratio
l == ft_vec3d_unit_lenght(r);
*/
// TODO add to rec rec->element.
t_vec3d	ft_ambient_light(t_hit_record *rec, t_ray *ray, t_data *img)
{
	t_vec3d	colour;

	colour = ft_vec3d_pro_vec3d(ft_colour_to_vec3d(img->ambient_light.colour),
			ft_colour_to_vec3d(rec->colour));
	(void)ray;
	return (ft_vec3d_pro_double(colour, img->ambient_light.light_ratio));
}

t_vec3d	ft_diffuse_light(t_hit_record *rec, t_ray *ray, t_data *img,
		t_element *light)
{
	t_vec3d		colour;
	t_vec3d		r;
	double		diffuse_factor;
	double		intesity;

	(void)ray;
	if (ft_shadow_ray(rec, img, light))
		return (ft_vec3d_pro_double(bounce_light(rec, img, rec->bounce), 0.2));
	r = ft_vec3d_minus_vec3d(light->coords, rec->p);
	intesity = light->light_ratio / ft_vec3d_squared_len(r);
	if (ft_vec3d_squared_len(r) != 1)
		r = ft_vec3d_unit_lenght(r);
	diffuse_factor = ft_vec3d_dot(rec->normal, r);
	diffuse_factor = clamp(diffuse_factor, 0, 1);
	intesity = intesity * diffuse_factor;
	colour = ft_colour_to_vec3d(rec->colour);
	colour = ft_vec3d_pro_vec3d(ft_colour_to_vec3d(light->colour), colour);
	return (ft_vec3d_pro_double(colour, intesity));
}
	//https://stackoverflow.com/questions/15619830/raytracing-how-to-combine-diffuse-and-specular-color
	//_n  == normalized == unit_vector

static t_vec3d	reflect_n(t_vec3d *vector_n, t_vec3d *normal_n)
{
	t_vec3d		reflect_n;
	t_vec3d		tmpnormal;
	double		mylen;

	if (ft_vec3d_squared_len(*vector_n) != 1)
		*vector_n = ft_vec3d_unit_lenght(*vector_n);
	if (ft_vec3d_squared_len(*normal_n) != 1)
		*normal_n = ft_vec3d_unit_lenght(*normal_n);
	mylen = 2.0 * ft_vec3d_dot(*vector_n, *normal_n);
	tmpnormal = ft_vec3d_pro_double(*normal_n, mylen);
	reflect_n = ft_vec3d_minus_vec3d(*vector_n, tmpnormal);
	if (ft_vec3d_squared_len(reflect_n))
		reflect_n = ft_vec3d_unit_lenght(reflect_n);
	return (reflect_n);
}

//p point
t_vec3d	ft_specular_light(t_hit_record *rec, t_ray *ray, t_data *img,
		t_element *light)
{
	t_vec3d	pos_lightpos_n;
	t_vec3d	reflected_n;
	double	specular_factor;
	double	intesity;
	t_vec3d	specular_color;

	(void)ray;
	if (ft_shadow_ray(rec, img, light))
		return (ft_vec3d_pro_double(bounce_light(rec, img, rec->bounce), 0.2));
	pos_lightpos_n = ft_vec3d_minus_vec3d(rec->p, light->coords);
	intesity = light->light_ratio / ft_vec3d_squared_len(pos_lightpos_n);
	reflected_n = reflect_n(&pos_lightpos_n, &rec->normal);
	(void)img, (void)ray;
	specular_factor = clamp(-ft_vec3d_dot(reflected_n, pos_lightpos_n), 0, 1);
	specular_factor = pow(specular_factor, 5);
	specular_color = ft_colour_to_vec3d(light->colour);
	specular_color = ft_vec3d_pro_double(specular_color,
			intesity * specular_factor);
	return (specular_color);
}
