/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avoid_leaks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 07:32:36 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/29 07:57:46 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	ft_avoid_leaks_vec3d(t_vec3d	*ptr)
{
	t_vec3d	vec;

	ft_bzero(&vec, sizeof(vec));
	if (!ptr)
		return (vec);
	vec = *ptr;
	free(ptr);
	return (vec);
}

t_vec3d	ft_vec3d_pro_double_no_alloc(t_vec3d *o1, double o2)
{
	t_vec3d	vector;

	ft_set_vec3d(&vector, o1->x * o2, o1->y * o2, o1->z * o2);
	return (vector);
}
