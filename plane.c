/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:33:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 16:59:17 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3d	ft_vec3d_xz(t_vec3d v1)
{
	v1.y = 0;
	return (v1);
}

t_vec3d	ft_vec3d_yz(t_vec3d v1)
{
	v1.x = 0;
	return (v1);
}

int	ft_hit_plane(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *plane)
{
	double	denom;

	denom = ft_vec3d_dot(plane->orientation_vector, ray->direction);
	if (isnan(denom) || ft_dabs(denom) <= 0.0)
		return (0);
	rec->t = ft_vec3d_dot(plane->orientation_vector,
			ft_vec3d_minus_vec3d(plane->coords, ray->origin)) / denom;
	if (rec->t >= camera->t_min || camera->t_max <= rec->t)
	{
		rec->p = ft_ray_at(ray, rec->t);
		rec->normal = plane->orientation_vector;
		ft_hit_face(ray, rec);
		ft_plane_uv(rec, plane);
		return (1);
	}
	return (0);
}
