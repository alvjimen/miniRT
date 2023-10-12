/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:39:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 13:14:30 by alvjimen         ###   ########.fr       */
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
	t_vec3d	tangent;
	t_vec3d	binormal;

	if (ft_vec3d_squared_len(normal) != 1)
		normal = ft_vec3d_unit_lenght(normal);
	tangent = ft_vec3d_cross(normal, ft_init_vec3d(0, 1, 0));
	if (!ft_vec3d_squared_len(tangent))
		tangent = ft_vec3d_cross(normal, ft_init_vec3d(0, 0, 1));
	tangent = ft_vec3d_unit_lenght(tangent);
	binormal = ft_vec3d_unit_lenght(ft_vec3d_cross(normal, tangent));
	return (ft_init_m3x3(tangent, binormal, normal));
}

t_vec3d	ft_vec3d_pro_matrix(t_vec3d vector, t_m3x3 matrix)
{
	t_vec3d	value;

	value.x = ft_vec3d_dot(vector, matrix.r[0]);
	value.y = ft_vec3d_dot(vector, matrix.r[1]);
	value.z = ft_vec3d_dot(vector, matrix.r[2]);
	return (value);
}
