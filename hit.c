/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:17:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/22 19:10:31 by alvjimen         ###   ########.fr       */
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
	double			bk_tmax;
	t_element		*element;
	t_list			*world;

	hit_anything = 0;
	bk_tmax = img->camera.t_max;
	world = img->world;
	while (world)
	{
		element = world->content;
		world = world->next;
		if (!element)
			continue ;
		if (element->ft_hit && element->ft_hit(ray, &img->camera, &tmp_rec, element))
		{
			hit_anything = 1;
			img->camera.t_max = tmp_rec.t;
			if (element->textured)
			{
				element->ft_texture(&tmp_rec, element, img);
			}
			else 
				tmp_rec.colour = element->colour;
			*rec = tmp_rec;
		}
	}
	img->camera.t_max = bk_tmax;
	return (hit_anything);
}

t_element	*ft_hittable_element(t_ray *ray, t_camera *camera,
		t_hit_record *rec, t_list *world)
{
	void			*hit_anything;
	t_hit_record	tmp_rec;
	double			bk_tmax;
	t_element		*element;

	hit_anything = 0;
	bk_tmax = camera->t_max;
	while (world)
	{
		element = world->content;
		world = world->next;
		if (!element)
			continue ;
		if (element->ft_hit && element->ft_hit(ray, camera, &tmp_rec, element))
		{
			hit_anything = element;
			camera->t_max = tmp_rec.t;
			tmp_rec.colour = element->colour;
			*rec = tmp_rec;
		}
	}
	camera->t_max = bk_tmax;
	return (hit_anything);
}
