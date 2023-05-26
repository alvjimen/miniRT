/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:14:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/24 19:19:58 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	sphere(t_element *element, t_vec4d coord, double diameter,
		t_colour colour)
{
	element->type = SPHERE;
	element->coords = coord;
	element->diameter = diameter;
	element->colour = colour;
}
