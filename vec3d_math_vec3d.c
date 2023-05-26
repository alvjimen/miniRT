/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_math_vec3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:14:17 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/24 20:23:51 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	*ft_vec3d_plus_vec3d(t_vec3d *o1, t_vec3d *o2)
{
	return (ft_init_vec3d(o1->x + o2->x, o1->y + o2->y, o1->z + o2->z));
}

t_vec3d	*ft_vec3d_minus_vec3d(t_vec3d *o1, t_vec3d *o2)
{
	return (ft_init_vec3d(o1->x - o2->x, o1->y - o2->y, o1->z - o2->z));
}

t_vec3d	*ft_vec3d_cross(t_vec3d *o1, t_vec3d *o2)
{
	return (ft_init_vec3d(o1->y * o2->z - o1->z * o2->y,
			o1->z * o2->x - o1->x * o2->z, o1->x * o2->y - o1->y * o2->x));
}

t_vec3d	*ft_vec3d_pro_vec3d(t_vec3d *o1, t_vec3d *o2)
{
	return (ft_init_vec3d(o1->x * o2->x, o1->y * o2->y, o1->z * o2->z));
}

double	ft_vec3d_dot(t_vec3d *o1, t_vec3d *o2)
{
	return (o1->x * o2->x + o1->y * o2->y + o1->z * o2->z);
}
