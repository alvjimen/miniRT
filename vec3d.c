/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:07:32 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/27 15:21:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	*ft_init_vec3d(double x, double y, double z)
{
	t_vec3d	*ptr;

	ptr = malloc(sizeof(*ptr));
	if (!ptr)
		return (ptr);
	ptr->x = x;
	ptr->y = y;
	ptr->z = z;
	return (ptr);
}

/*this is the same to x^2 + y^2 + z^2 */
double	ft_vec3d_squared_len(t_vec3d *o1)
{
	if (!o1)
		return (NAN);
	return (ft_vec3d_dot(o1, o1));
}

double	ft_vec3d_len(t_vec3d *o1)
{
	if (!o1)
		return (NAN);
	return (sqrt(ft_vec3d_squared_len(o1)));
}

t_vec3d	*ft_vec3d_unit_lenght(t_vec3d *o1)
{
	if (!o1)
		return (NULL);
	return (ft_vec3d_div_double(o1, ft_vec3d_len(o1)));
}