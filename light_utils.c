/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:19:10 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 08:11:26 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_find_light(void *node)
{
	t_element	*element;

	element = node;
	if (element && element->type == LIGHT)
		return (0);
	return (1);
}

t_vec3d	ft_calculate_lights(t_hit_record *rec, t_ray *ray, t_data *img,
			t_vec3d (*f)(t_hit_record *, t_ray *, t_data *, t_element *))
{
	t_list		*lst;
	t_element	*light;
	t_vec3d		colour;
	double		counter;

	lst = img->world;
	ft_bzero(&colour, sizeof(colour));
	counter = 0;
	while (lst)
	{
		lst = ft_search_list(lst, ft_find_light);
		if (!lst)
			break ;
		light = lst->content;
		colour = ft_vec3d_plus_vec3d(colour, f(rec, ray, img, light));
		counter++;
		lst = lst->next;
	}
	if (!counter || counter == 1)
		return (colour);
	return (ft_vec3d_div_double(colour, counter));
}
// const t_element light
double	ft_shadow_ray(t_hit_record *rec, t_data *img, t_element *light)
{
	t_ray			shadow;
	t_hit_record	tmp_rec;
	double			bk_tmin;
	int				hit;

	bk_tmin = img->camera.t_min;
	shadow = ft_init_ray(rec->p, ft_vec3d_minus_vec3d(light->coords, rec->p));
	img->camera.t_min = 0.00001;
	hit = ft_hittable(&shadow, img, &tmp_rec);
	img->camera.t_min = bk_tmin;
	return (hit);
}

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
