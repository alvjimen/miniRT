/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:14:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 13:29:44 by dmacicio         ###   ########.fr       */
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
	element->ft_hit = ft_hit_sphere;
	element->reflection_index = 0;
	return (element);
}

t_element	ambient_light(double intensity, t_colour colour)
{
	t_element	ptr;

	ptr.type = AMBIENT_LIGHT;
	ptr.light_ratio = intensity;
	ptr.colour = colour;
	return (ptr);
}

t_element	*light(t_vec3d origin, double brightness, t_colour colour)
{
	t_element	*element;

	element = ft_calloc(1, sizeof(*element));
	if (!element)
		return (element);
	element->type = LIGHT;
	element->coords = origin;
	element->light_ratio = brightness;
	element->colour = colour;
	return (element);
}

t_element	*plane(t_vec3d coords, t_vec3d normalized_orientation_vector,
		t_colour colour)
{
	t_element	*element;

	element = ft_calloc(1, sizeof(*element));
	if (!element)
		return (element);
	element->type = PLANE;
	element->coords = coords;
	element->orientation_vector = normalized_orientation_vector;
	element->colour = colour;
	element->hittable = 1;
	element->ft_hit = ft_hit_plane;
	element->reflection_index = 0;
	return (element);
}
