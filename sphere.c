/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:04 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/24 19:11:10 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_hit_sphere(t_vec3d *center, double diameter, t_ray *ray)
{
	t_vec3d	*oc;
	double	square_x;
	double	square_y;
	double	square_z;
	double	discriminant;
	

	oc = ft_vec3d_minus_vec3d(ray->origin, center);
	square_x = ft_vec3d_dot(ray->direction, ray->direction);
	square_y = 2.0 * ft_vec3d_dot(oc, ray->direction);
	square_z = ft_vec3d_dot(oc, oc) - ((diameter / 2) * (diameter / 2));
	discriminant = square_y * square_y - 4 * square_x * square_z;
	return (discriminant > 0);
}

