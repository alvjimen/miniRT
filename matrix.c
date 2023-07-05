/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:39:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/07/04 15:44:28 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/*i = input data*/
/*m = matrix with i is multiplied*/
/*o = output data*/
t_m3x3	ft_init_m3x3(t_vec3d v1, t_vec3d v2, t_vec3d v3)
{
	t_m3x3	matrix;

	matrix.r[0] = v1;
	matrix.r[1] = v2;
	matrix.r[2] = v3;
	return (matrix);
}

t_m3x3	ft_tbn(t_vec3d normal)
{
	t_vec3d	t;
	t_vec3d	b;

	t = ft_vec3d_cross(normal, ft_init_vec3d(0, 1, 0));
	if (!ft_vec3d_squared_len(t))
		t = ft_vec3d_cross(normal, ft_init_vec3d(0, 0, 1));
	t = ft_vec3d_unit_lenght(t);
	b = ft_vec3d_unit_lenght(ft_vec3d_cross(normal, t));
	return (ft_init_m3x3(t, b, normal));
}
/*
void	multiplymatrixvector(t_vec3d &i, t_vec3d &o, t_m4x4 &m)
{
	double	w;

	o->x = i->x * m->m[0].x + i->y * m->m[1].x + i->z * m.m[2].x + m->m[3].x;
	o->y = i->x * m->m[0].y + i->y * m->m[1].y + i->z * m.m[2].y + m->m[3].y;
	o->z = i->x * m->m[0].z + i->y * m->m[1].z + i->z * m->m[2].z + m->m[3].z;
	w = i->x * m->m[0].w + i->y * m->m[1].w + i->z * m->m[2].w + m->m[3].w;
	if (w != 0.0f)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
}
*/
