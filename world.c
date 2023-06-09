/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:53:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/06 16:04:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_world(t_data *img)
{
	t_list		*node;
	t_colour	colour;

	ft_bzero(&colour, sizeof(colour));
	node = ft_lstnew(sphere(ft_init_vec3d(0.0, 0.0, -1), 1, colour));
	ft_lstadd_back(&img->world, node);
	if (!node || !node->content)
	{
		ft_lstclear(&img->world, free);
		return (1);
	}
	node = ft_lstnew(sphere(ft_init_vec3d(0.0, -100.5, -1), 200, colour));
	ft_lstadd_back(&img->world, node);
	if (!node || !node->content)
	{
		ft_lstclear(&img->world, free);
		return (1);
	}
	return (0);
}
