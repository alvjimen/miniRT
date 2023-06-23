/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:57:34 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/22 19:10:56 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_find_light(void *node)
{
	t_element	*element;

	element = node;
	if (element && element->type == LIGHT)
		return (0);
	return (1);
}

t_vec3d	ft_reflect(t_vec3d direction, t_vec3d normal)
{
	return (ft_vec3d_minus_vec3d(direction, ft_vec3d_pro_double(direction,
					2 * ft_vec3d_dot(direction, normal))));
}
