/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/01 15:52:29 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_color_double_to_int(double c)
{
	return (c * 255.999);
}

int	ft_color_vector_to_int(t_vec3d v)
{
	return (ft_color_double_to_int((v.x + 1) * 0.5) << 16
		| ft_color_double_to_int((v.y + 1) * 0.5) << 8
		| ft_color_double_to_int((v.z + 1) * 0.5));
}

void	ft_draw_background_v2(t_data *img)
{
	int		x;
	int		y;
	int		colour;
	t_ray	ray;
	t_vec3d	vector;

	y = 0;
	while (y < img->image_height)
	{
		x = 0;
		while (x < img->image_width)
		{
			vector = ft_ray_direction_v3(img, x, img->image_height - (y + 1));
			ray = ft_init_ray(img->camera->origin, vector);
			colour = ft_ray_color_v2(&ray, img);
			my_mlx_pixel_put(img, x, y, colour);
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * 4);
	*(unsigned int *)dst = color;
}
