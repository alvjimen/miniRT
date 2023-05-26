/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:39:28 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/24 18:17:53 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec4d	*ft_vec4d_init(double x, double y, double z, double w)
{
	t_vec4d	*ptr;

	ptr = malloc(sizeof(t_vec4d));
	if (!ptr)
		return (ptr);
	ptr->x = x;
	ptr->y = y;
	ptr->z = z;
	ptr->w = w;
	return (ptr);
}
