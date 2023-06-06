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

void	sphere(t_element *element, t_vec3d coord, double diameter,
		t_colour colour)
{
	element->type = SPHERE;
	element->coords = coord;
	element->diameter = diameter;
	element->radius = diameter / 2;
	element->colour = colour;
	element->hittable = 1;
	element->ft_hit = ft_hit_sphere_v2;
}

/*
int	ft_parse_camera(char *line)
{
	if (ERROR)
		return (-1):
	return (0);
}
*/
