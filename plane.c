/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:33:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/21 08:46:45 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_plane_uv(t_hit_record *rec, t_element *plane)
{
	t_vec3d	a;
	t_vec3d	b;
	t_vec3d	max_ab;
	t_vec3d	c;
	t_vec3d	u;

	a = ft_vec3d_cross(rec->normal, ft_init_vec3d(1, 0, 0));
	b = ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 1, 0));
	if (ft_vec3d_squared_len(a) < ft_vec3d_squared_len(b))
		max_ab = b;
	else
		max_ab = a;
	c = ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 0, 1));
	if (ft_vec3d_squared_len(max_ab) < ft_vec3d_squared_len(c))
		u = c;
	else
		u = max_ab;
	rec->v = ft_vec3d_dot(ft_vec3d_cross(rec->normal, u), rec->p);
	rec->u = ft_vec3d_dot(u, rec->p);
	rec->v = ft_dabs(rec->v);
	rec->u = ft_dabs(rec->u);
	if (plane)
		return ;
}
/*
void	ft_plane_uv(t_hit_record *rec, t_element *plane)
{
	t_vec3d	e1;
	t_vec3d	e2;

	e1 = ft_vec3d_unit_lenght(ft_vec3d_cross(rec->normal, ft_init_vec3d(1, 0, 0)));
	if (ft_vec3d_eq(e1, ft_init_vec3d(0, 0, 0)))
		e1 = ft_vec3d_unit_lenght(ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 0, 1)));
	e2 = ft_vec3d_unit_lenght(ft_vec3d_cross(rec->normal, e1));
	rec->u = ft_vec3d_dot(e1, rec->p);// rec->u = ft_vec3d_dot(e1, rec->p)/ 2;
	//if (rec->u <= 0.0)
	//	rec->u = ft_dabs(rec->u);
	rec->v = ft_vec3d_dot(e2, rec->p);//rec->v = ft_vec3d_dot(e2, rec->p);
	//if (rec->v < 0.0)
	//	rec->v = ft_dabs(rec->v);
	if (plane)
		return ;
}
*/

int	ft_hit_plane(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *plane)
{
	double	denom;

	/*In theory it should plane->orientation_vector should be unit_length*/
	denom = ft_vec3d_dot(plane->orientation_vector, ray->direction);
	if (isnan(denom) || ft_dabs(denom) <= 0.0)
		return (0);
	rec->t = ft_vec3d_dot(plane->orientation_vector,
			ft_vec3d_minus_vec3d(plane->coords, ray->origin)) / denom;
	if (rec->t >= 0)
	{
		rec->p = ft_ray_at(ray, rec->t);
		rec->normal = plane->orientation_vector;
		ft_hit_face(ray, rec);
		ft_plane_uv(rec, plane);
		return (1);
	}
	if (camera)
		return (0);
	return (0);
}
