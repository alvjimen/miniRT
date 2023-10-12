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

t_vec3d	ft_rotate_x(t_vec3d vector, double angle)
{
	t_m3x3	rotate;

	ft_bzero(&rotate, sizeof(rotate));
	rotate.r[0].x = 1;
	rotate.r[1].y = cos(angle);
	rotate.r[1].z = -sin(angle);
	rotate.r[2].y = -rotate.r[1].z;
	rotate.r[2].z = rotate.r[1].y;
	return (ft_vec3d_pro_matrix(vector, rotate));
}

t_vec3d	ft_rotate_y(t_vec3d vector, double angle)
{
	t_m3x3	rotate;

	ft_bzero(&rotate, sizeof(rotate));
	rotate.r[0].x = cos(angle);
	rotate.r[0].z = sin(angle);
	rotate.r[1].y = 1;
	rotate.r[2].x = -rotate.r[0].z;
	rotate.r[2].z = rotate.r[0].x;
	return (ft_vec3d_pro_matrix(vector, rotate));
}

t_vec3d	ft_rotate_z(t_vec3d vector, double angle)
{
	t_m3x3	rotate;

	ft_bzero(&rotate, sizeof(rotate));
	rotate.r[0].x = cos(angle);
	rotate.r[0].y = -sin(angle);
	rotate.r[1].y = rotate.r[0].x;
	rotate.r[1].x = -rotate.r[0].y;
	rotate.r[2].z = 1;
	return (ft_vec3d_pro_matrix(vector, rotate));
}
