/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:57:34 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/27 19:45:54 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//https://www.cs.cornell.edu/courses/cs4620/2017sp/slides/05rt-shading.pdf
#include "minirt.h"

int	ft_find_light(void *node)
{
	t_element	*element;

	element = node;
	if (element && element->type == LIGHT)
		return (0);
	return (1);
}

static double	ft_max(double n1, double n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

t_vec3d	ft_specular_reflection(t_vec3d direction, t_vec3d normal)
{
	return (ft_vec3d_minus_vec3d(direction,
				ft_vec3d_pro_double(direction,
					2 * ft_vec3d_dot(direction, normal))));
}
/*
for calcule the ambient ratio illumination u should take the main source of
light (the brightess) and multiplicate with ambient ratio
ks == light->light_ratio
l == ft_vec3d_unit_lenght(r);
*/

t_vec3d	ft_calculate_lights(t_hit_record *rec, t_ray *ray, t_data *img,
			t_vec3d (*f)(t_hit_record *, t_ray *, t_data *, t_element *))
{
	t_list		*lst;
	t_element	*light;
	t_vec3d		result;
	double		counter;

	lst = img->world;
	ft_bzero(&result, sizeof(result));
	counter = 0;
	while (lst)
	{
		lst = ft_search_list(lst, ft_find_light);
		if (!lst)
			break ;
		light = lst->content;
		result = ft_vec3d_plus_vec3d(f(rec, ray, img, light), result);
		counter++;
		lst = lst->next;
	}
	if (!counter)
		return (result);
	return (result);
	return (ft_vec3d_div_double(result,  counter));
}

double	ft_shadow_ray(t_hit_record *rec, t_data *img, t_element *light)
{
	t_ray			shadow;
	t_hit_record	tmp_rec;
	double			bk_tmin;
	int				result;

	bk_tmin = img->camera.t_min;
	img->camera.t_min = 0.00001;
	shadow = ft_init_ray(rec->p, ft_vec3d_minus_vec3d(light->coords, rec->p));
	result = !ft_hittable(&shadow, img, &tmp_rec);
	img->camera.t_min = bk_tmin;
	return (result);
}

t_vec3d	ft_ambient_light(t_hit_record *rec, t_data *img)
{
	t_vec3d	colour;
	t_vec3d	try;
	
	colour = ft_colour_to_vec3d(img->ambient_light.colour);
	try = ft_vec3d_pro_vec3d(colour, ft_colour_to_vec3d(rec->colour));
	return (ft_vec3d_pro_double(try,
				0.2 * img->ambient_light.light_ratio));
}

t_vec3d	ft_diffuse_light_v2(t_hit_record *rec, t_ray *ray, t_data *img,
		t_element *light)
{
	t_vec3d		v;
	t_vec3d		r;
	double		n_l;
	double		i_r2;
	double		result;

//	v = -ray->unit_direction;
	result = 0;
	if (!ft_shadow_ray(rec, img, light))
		return (ft_vec3d_pro_double(ft_colour_to_vec3d(rec->colour), result));
	r = ft_vec3d_minus_vec3d(light->coords, rec->p);
	i_r2 = light->light_ratio / ft_vec3d_squared_len(r);
	n_l = ft_vec3d_dot(rec->normal, ft_vec3d_unit_lenght(r));
	result += 0.4 * i_r2 * ft_max(0, n_l);
	v = ft_vec3d_pro_vec3d(ft_colour_to_vec3d(rec->colour),
			ft_colour_to_vec3d(light->colour));
	if (ray)
		return (ft_vec3d_pro_double(v, result));
	return (ft_vec3d_pro_double(v, result));
}

t_vec3d	ft_specular_light_v2(t_hit_record *rec, t_ray *ray, t_data *img,
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
	h  = ft_vec3d_unit_lenght(ft_vec3d_plus_vec3d(ft_vec3d_negative(
					ray->direction), r));
	result = 0.5 * i_r2 * pow(ft_max(0, ft_vec3d_dot(rec->normal,
					h)), 1024);
	try = ft_vec3d_pro_vec3d(ft_colour_to_vec3d(rec->colour),
			ft_colour_to_vec3d(light->colour));
	return (ft_vec3d_pro_double(try, result));
}

t_vec3d	ft_color_ambient_light(t_hit_record *rec, t_ray *ray, t_data *img)
{
	if (rec && ray && img)
		return (ft_ambient_light(rec, img));
	return (ft_ambient_light(rec, img));
}

t_vec3d	ft_color_diffuse_light(t_hit_record *rec, t_ray *ray, t_data *img)
{
	return (ft_calculate_lights(rec, ray, img, ft_diffuse_light_v2));
}

t_vec3d	ft_color_specular_light(t_hit_record *rec, t_ray *ray, t_data *img)
{
	return (ft_calculate_lights(rec, ray, img, ft_specular_light_v2));
}

t_vec3d	ft_color_ambient_diffuse_light(t_hit_record *rec, t_ray *ray,
		t_data *img)
{
	return (ft_vec3d_plus_vec3d(ft_color_diffuse_light(rec, ray, img),
			ft_color_ambient_light(rec, ray, img)));
}

t_vec3d	ft_color_specular_ambient_light(t_hit_record *rec, t_ray *ray,
		t_data *img)
{
	return (ft_vec3d_plus_vec3d(ft_color_specular_light(rec, ray, img),
			ft_color_ambient_light(rec, ray, img)));
}

t_vec3d	ft_color_specular_diffuse_light(t_hit_record *rec, t_ray *ray,
		t_data *img)
{
	return (ft_vec3d_plus_vec3d(ft_color_specular_light(rec, ray, img),
			ft_color_diffuse_light(rec, ray, img)));
}

t_vec3d	ft_color_diffuse_specular_ambiance_light(t_hit_record *rec, t_ray *ray,
		t_data *img)
{
	return (ft_vec3d_plus_vec3d(ft_color_specular_diffuse_light(rec, ray, img),
			ft_color_ambient_light(rec, ray, img)));
}
/* ft_ specular reflection

t_vec3d	ft_ray_color_diffuse_ambiance(t_ray *ray, t_data *img)
{
	t_hit_record	rec;
	int				depth;

	depth = 1;
	if (depth <= 0)
		return (ft_init_vec3d(0, 0, 0));
	ft_bzero(&rec, sizeof(rec));
	if (!ft_hittable(ray, &img->camera, &rec, img->world))
		return (ft_init_vec3d(0, 0, 0));
	return (ft_vec3d_plus_vec3d(ft_calculate_lights(&rec, ray, img,
					ft_diffuse_light_v2), ft_ambient_light(&rec, img)));
}


t_vec3d	ft_ray_color_ambient(t_ray *ray, t_data *img)
{
	t_hit_record	rec;
	int				depth;

	depth = 1;
	if (depth <= 0)
		return (ft_init_vec3d(0, 0, 0));
	ft_bzero(&rec, sizeof(rec));
	if (!ft_hittable(ray, &img->camera, &rec, img->world))
		return (ft_init_vec3d(0, 0, 0));
	return (ft_ambient_light(&rec, img));
}
*/
void	ft_img_color(t_data *img)
{
	if (img->value_color & AMBIANCE && img->value_color & DIFFUSE
			&& img->value_color & SPECULAR)
		img->ft_color = ft_color_diffuse_specular_ambiance_light;
	else if (img->value_color & AMBIANCE && img->value_color & DIFFUSE)
		img->ft_color = ft_color_ambient_diffuse_light;
	else if (img->value_color & AMBIANCE && img->value_color & SPECULAR)
		img->ft_color = ft_color_specular_ambient_light;
	else if (img->value_color & SPECULAR && img->value_color & DIFFUSE)
		img->ft_color = ft_color_specular_diffuse_light;
	else if (img->value_color == SPECULAR)
		img->ft_color = ft_color_specular_light;
	else if (img->value_color == DIFFUSE)
		img->ft_color = ft_color_diffuse_light;
	else if (img->value_color == AMBIANCE)
		img->ft_color = ft_color_ambient_light;
}
