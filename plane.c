/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:33:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/30 18:33:39 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	is_plane_point(t_vec4d *p, t_element *plane)
{
	t_vec4d	pminusq;

	pminusq = p - plane->coords;
	return (plane->orientation_vector * pminusq == 0);
}
