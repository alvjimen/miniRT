/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:14:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/06 19:35:36 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_element	*sphere(t_vec3d coord, double diameter,
		t_colour colour)
{
	t_element	*element;

	element = ft_calloc(1, sizeof(*element));
	if (!element)
		return (element);
	element->type = SPHERE;
	element->coords = coord;
	element->diameter = diameter;
	element->radius = diameter / 2;
	element->colour = colour;
	element->hittable = 1;
	element->ft_hit = ft_hit_sphere_v2;
	return (element);
}
