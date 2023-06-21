/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:19:38 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/21 19:31:03 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	ft_matrix_pro(t_vec3d vector, t_m3x3 matrix)
{
	t_vec3d	value;

	value.x = vector->x * matrix.r[0].x + vector->y * matrix[0].y + vector->z * matrix[0].z;
	value.y = vector->x * matrix.r[1].x + vector->y * matrix[1].y + vector->z * matrix[1].z;
	value.y = vector->x * matrix.r[2].x + vector->y * matrix[2].y + vector->z * matrix[2].z;
}

t_vec3d	ft_rotate_x(t_vec3d vector, double angle)
{
	t_m3x3	rotate;

	ft_bzero(&rotate, sizeof(rotate));
	rotate.r[0].x = 1;
	rotate.r[1].y = cos(angle);
	rotate.r[1].z = -sen(angle);
	rotate.r[2].z = rotate.r[1].y;
	rotate.r[2].y = -rotate.r[1].z;
	ft_matrix_pro(vector, rotate);
}

t_vec3d	ft_rotate_y(t_vec3d vector, double angle)
{
	t_m3x3	rotate;

	ft_bzero(&rotate, sizeof(rotate));
	rotate.r[0].x = cos(angle);
	rotate.r[0].z = sen(angle);
	rotate.r[1].y = 1;
	rotate.r[2].x = -rotate.r[0].z;
	rotate.r[2].z = rotate.r[0].x;
	ft_matrix_pro(vector, rotate);
}

t_vec3d	ft_rotate_z(t_vec3d vector, double angle)
{
	t_m3x3	rotate;

	ft_bzero(&rotate, sizeof(rotate));
	rotate.r[0].x = cos(angle);
	rotate.r[0].y = -sen(angle);
	rotate.r[1].y = rotate.r[0].x;
	rotate.r[1].x = -rotate.r[0].y;
	rotate.r[2].z = 1;
	ft_matrix_pro(vector, rotate);
}
