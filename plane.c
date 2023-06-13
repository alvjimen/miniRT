/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:33:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/12 19:12:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_hit_plane(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *plane)
{
	double	denom;

	denom = ft_vec3d_dot(plane->orientation_vector, ray->direction);
	if (isnan(denom) || ft_dabs(denom) <= 0.001)
		return (0);
	rec->t = ft_vec3d_dot(plane->orientation_vector,
				ft_vec3d_minus_vec3d(plane->coords, ray->origin)) / denom;
	if (rec->t >= 0)
	{
		rec->p = ft_ray_at(ray, rec->t);
		rec->normal = plane->orientation_vector;
		ft_hit_face(ray, rec);
		return (1);
	}
	if (camera)
		return (0);
	return (0);
}
