/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:07:32 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/17 18:40:06 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	ft_init_vec3d(double x, double y, double z)
{
	t_vec3d	ptr;

	ptr.x = x;
	ptr.y = y;
	ptr.z = z;
	return (ptr);
}

/*this is the same to x^2 + y^2 + z^2 */
double	ft_vec3d_squared_len(t_vec3d o1)
{
	return (ft_vec3d_dot(o1, o1));
}

double	ft_vec3d_len(t_vec3d o1)
{
	return (sqrt(ft_vec3d_squared_len(o1)));
}

t_vec3d	ft_vec3d_unit_lenght(t_vec3d o1)
{
	return (ft_vec3d_div_double(o1, ft_vec3d_len(o1)));
}

int	ft_vec3d_eq(t_vec3d v1, t_vec3d v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

t_vec3d	ft_vec3d_xz(t_vec3d v1)
{
	t_vec3d	xz;

	xz = v1;
	xz.y = 0;
	return (xz);
}

t_vec3d	ft_vec3d_yz(t_vec3d v1)
{
	t_vec3d	yz;

	yz = v1;
	yz.x = 0;
	return (yz);
}
