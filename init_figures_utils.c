/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:47:34 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/09 17:53:06 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_element	*cylinder(t_vec3d coords, t_vec3d normalized_orientation_vector,
		double param[2], t_colour colour)
{
	t_element	*element;

	element = ft_calloc(1, sizeof(*element));
	if (!element)
		return (element);
	element->type = CYLINDER;
	element->coords = coords;
	element->orientation_vector = normalized_orientation_vector;
	element->diameter = param[0];
	element->radius = element->diameter / 2;
	element->height = param[1];
	element->colour = colour;
	element->reflection_index = 0;
	element->hittable = 1;
	element->ft_hit = ft_hit_cylinder;
	return (element);
}

t_element	*cone(t_vec3d coords, t_vec3d normalized_orientation_vector,
		double param[2], t_colour colour)
{
	t_element	*element;

	element = ft_calloc(1, sizeof(*element));
	if (!element)
		return (element);
	element->type = CONE;
	element->coords = coords;
	element->orientation_vector = normalized_orientation_vector;
	element->diameter = param[0];
	element->radius = element->diameter / 2;
	element->height = param[1];
	element->colour = colour;
	element->reflection_index = 0;
	element->hittable = 1;
	element->ft_hit = ft_hit_cone;
	return (element);
}
