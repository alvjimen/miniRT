/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:17:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 18:40:12 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_hit_face(t_ray *ray, t_hit_record *rec)
{
	rec->front_face = ft_vec3d_dot(ray->direction, rec->normal) < 0.0;
	if (!rec->front_face)
		rec->normal = ft_vec3d_negative(rec->normal);
}

int	ft_hittable(t_ray *ray, t_data *img, t_hit_record *rec)
{
	int				hit_anything;
	t_hit_record	tmp_rec;
	t_element		*element;
	t_list			*world;

	hit_anything = 0;
	world = img->world;
	while (world)
	{
		element = world->content;
		world = world->next;
		if (element && element->hittable
			&& element->ft_hit(ray, &img->camera, &tmp_rec, element))
		{
			hit_anything = 1;
			img->camera.t_max = tmp_rec.t;
			if (element->textured)
				element->ft_texture(&tmp_rec, element, img);
			tmp_rec.colour = element->colour;
			if (element->textured)
			*rec = tmp_rec;
		}
	}
	img->camera.t_max = TMAX;
	return (hit_anything);
}

t_element	*ft_hittable_element(t_ray *ray, t_data *img, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	t_element		*element;
	t_element		*element_bk;
	t_list			*world;

	world = img->world;
	element_bk = NULL;
	while (world)
	{
		element = world->content;
		world = world->next;
		if (element && element->hittable
			&& element->ft_hit(ray, &img->camera, &tmp_rec, element))
		{
			element_bk = element;
			img->camera.t_max = tmp_rec.t;
			tmp_rec.colour = element->colour;
			tmp_rec.reflection_index = element->reflection_index;
			*rec = tmp_rec;
		}
	}
	if (element_bk && element_bk->reflection_index != 0.0)
	{
		rec->mirror_color = ft_color_mirror(rec, ray, img); 
		// The line below is for debugging purpouse
//		rec->colour = rec->mirror_color;
//		rec->colour = img->ft_color(rec, ray, img)
	}
	img->camera.t_max = TMAX;
	return (element_bk);
}
