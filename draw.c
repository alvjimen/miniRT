/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/20 14:39:24 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_draw_without_antialiasing(t_data *img)
{
	int		x;
	int		y;
	t_vec3d	colour;
	t_ray	ray;
	t_vec3d	vector;

	y = 0;
	while (y < img->image_height)
	{
		x = 0;
		while (x < img->image_width)
		{
			vector = ft_ray_direction(img, x, y, 0);
			ray = ft_init_ray(img->camera.origin, vector);
			colour = ft_ray_color(&ray, img);
			my_mlx_pixel_put(img, x, y, ft_write_color(colour, 1));
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
