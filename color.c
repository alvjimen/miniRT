/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:16:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/01 15:49:57 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_color_double_to_int_v2(double c)
{
	return (c * 256);
}

int	ft_color_vector_to_int_v2(t_vec3d v)
{
	return (ft_color_double_to_int_v2(clamp(v.x, 0.0, 0.999)) << 16
		| ft_color_double_to_int_v2(clamp(v.y, 0.0, 0.999)) << 8
		| ft_color_double_to_int_v2(clamp(v.z, 0.0, 0.999)));
}

int	ft_write_color(t_vec3d vector, int samplex_per_pixel)
{
	vector = ft_vec3d_div_double(vector, samplex_per_pixel);
	return (ft_color_vector_to_int(vector));
}
