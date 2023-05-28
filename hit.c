/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:17:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 17:16:59 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_hit_face(t_ray *ray, t_hit_record *rec)
{
	rec->front_face  = ft_vec3d_dot(ray->direction, rec->normal);
	if (!rec->front_face)
		ft_vec3d_negative(rec->normal);
}

int	ft_hittable(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_list *world)
{
	int				hit_anything;
	t_hit_record	tmp_rec;
	double			closest_so_far;
	t_element		*element;

	hit_anything = 0;
	closest_so_far = camera->t_max;
	while (world)
	{
		element = world->content;
		world = world->next;
		if (!element)
			continue ;
		if (element->ft_hit && element->ft_hit(ray, camera, &tmp_rec, element))
		{
			if (tmp_rec.t > closest_so_far)
				hit_anything = 1;
			hit_anything = 1;
			closest_so_far = tmp_rec.t;
			*rec = tmp_rec;
		}
	}
	return (hit_anything);
}
