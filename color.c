/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:16:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 13:25:29 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_color_double_to_int(double c)
{
	return (c * 256);
}

static int	ft_color_vector_to_int(t_vec3d v)
{
	return (ft_color_double_to_int(clamp(v.x, 0.0, 0.999999999)) << 16
		| ft_color_double_to_int(clamp(v.y, 0.0, 0.999999999)) << 8
		| ft_color_double_to_int(clamp(v.z, 0.0, 0.999999999)));
}

t_vec3d	ft_pixel_to_raw_color_vec3d(int pixel, int endian)
{
	if (!endian)
		return (ft_init_vec3d(pixel >> 16 & 0xff, pixel >> 8 & 0xff,
				pixel & 0xff));
	return (ft_init_vec3d(pixel >> 8 & 0xff, pixel >> 16 & 0xff,
			pixel >> 24 & 0xff));
}

t_vec3d	ft_colour_to_vec3d(t_colour colour)
{
	return (ft_vec3d_div_double(ft_init_vec3d(colour.red, colour.green,
				colour.blue), 255));
}

int	ft_write_color(t_vec3d vector, int samplex_per_pixel)
{
	vector = ft_vec3d_div_double(vector, samplex_per_pixel);
	return (ft_color_vector_to_int(vector));
}
