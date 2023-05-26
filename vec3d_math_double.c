/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_math_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:13:19 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/25 17:24:07 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	*ft_vec3d_pro_double(t_vec3d *o1, double o2)
{
	return (ft_init_vec3d(o1->x * o2, o1->y * o2, o1->z * o2));
}

t_vec3d	*ft_vec3d_div_double(t_vec3d *o1, double o2)
{
	return (ft_vec3d_pro_double(o1, 1.0 / o2));
}

void	ft_vec3d_pro_double_ptr(t_vec3d *o1, double o2, t_vec3d *dst)
{
	dst->x = o1->x * o2;
	dst->y = o1->y * o2;
	dst->z = o1->z * o2;
}

void	ft_vec3d_div_double_ptr(t_vec3d *o1, double o2, t_vec3d *dst)
{
	return (ft_vec3d_pro_double_ptr(o1, 1.0 / o2, dst));
}
