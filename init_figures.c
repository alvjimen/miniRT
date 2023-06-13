/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:14:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/12 17:59:36 by alvjimen         ###   ########.fr       */
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

t_element	ambient_light(double intensity, t_colour colour)
{
	t_element	ptr;

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
	element->coords = coords;
	element->orientation_vector = normalized_orientation_vector;
	element->colour = colour;
	element->hittable = 1;
	element->ft_hit = ft_hit_plane;
	return (element);
}

t_element	*cylinder(t_vec3d coords, t_vec3d normalized_orientation_vector,
		double param[2], t_colour colour)
{
	t_element	*element;

	element = ft_calloc(1, sizeof(*element));
	if (!element)
		return (element);
	element->coords = coords;
	element->orientation_vector = normalized_orientation_vector;
	element->diameter = param[0];
	element->height = param[1];
	element->colour = colour;
	element->hittable = 1;
	element->ft_hit = ft_hit_sphere_v2;
	return (element);
}
