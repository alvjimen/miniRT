/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:20:39 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 16:47:59 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/* ph = H */
/* h = c - H */
/* uh = h^ */
int	ft_hit_cone(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cone)
{
	t_vec3d	ph;
	t_vec3d	h;
	t_vec3d	uh;
	t_vec3d	w;
	double	a;
	double	b;
	double	c;
	double	m;
	double	discriminant;

	uh = ft_vec3d_unit_lenght(cone->orientation_vector);
	h = ft_vec3d_pro_double(uh, cone->height);
	ph = ft_vec3d_plus_vec3d(cone->coords, h);
	m = (cone->radius * cone->radius) / ft_vec3d_squared_len(h);
	w = ft_vec3d_minus_vec3d(ray->origin, ph);
	a = ft_vec3d_dot(ray->direction, ray->direction) -
		pow((m + 1) * ft_vec3d_dot(ray->direction, uh), 2);
	b = ft_vec3d_dot(ray->direction, w) - (m + 1) *
		(ft_vec3d_dot(ray->direction, uh) * ft_vec3d_dot(w, uh));
	c = ft_vec3d_dot(w, w) - pow((m + 1) * ft_vec3d_dot(w, uh), 2);
	discriminant = (b * b) - 4 * a * c;
	if (discriminant < 0)
		return (0);
	if (camera)
	{
	}
	rec->normal = cone->orientation_vector;
	return (1);
}
