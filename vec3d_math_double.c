/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_math_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:13:19 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/30 18:13:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	ft_vec3d_pro_double(t_vec3d o1, double o2)
{
	return (ft_init_vec3d(o1.x * o2, o1.y * o2, o1.z * o2));
}

t_vec3d	ft_vec3d_div_double(t_vec3d o1, double o2)
{
	return (ft_vec3d_pro_double(o1, 1 / o2));
}

t_vec3d	ft_vec3d_negative(t_vec3d ptr)
{
	t_vec3d	vector;

	if (!isnan(ptr.x))
		vector.x = -ptr.x;
	else
		vector.x = NAN;
	if (!isnan(ptr.y))
		vector.y = -ptr.y;
	else
		vector.y = NAN;
	if (!isnan(ptr.z))
		vector.z = -ptr.z;
	else
		vector.z = NAN;
	return (vector);
}
