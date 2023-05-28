/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:53:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 16:56:08 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_world(t_data *img)
{
	t_list		*node;
	t_element	*element;
	t_colour	colour;
	
	ft_bzero(&colour, sizeof(colour));
	element = ft_alloc_struct(sizeof(*element));
	if (!element)
		exit(1);
	ft_set_vec3d(&element->coords, 0, 0, -1);
	sphere(element, element->coords, 1, colour);
	node = ft_lstnew(element);
	if (!node)
		exit(1);
	ft_lstadd_back(&img->world, node);
	element = ft_alloc_struct(sizeof(*element));
	if (!element)
		exit(1);
	ft_set_vec3d(&element->coords, 0, -100, -1);
	sphere(element, element->coords, 200, colour);
	node = ft_lstnew(element);
	if (!node)
		exit(1);
	ft_lstadd_back(&img->world, node);
}
