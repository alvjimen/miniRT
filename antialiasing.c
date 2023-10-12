/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:42:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 16:59:17 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_antialiasing(t_data *img, int x, int y)
{
	t_ray	ray;
	t_vec3d	vector;
	t_vec3d	acum;
	int		samples;

	samples = 0;
	ft_bzero(&acum, sizeof(acum));
	while (samples++ < img->samplex_per_pixel)
	{
		vector = ft_ray_direction(img, x, y, 1);
		ray = ft_init_ray(img->camera.origin, vector);
		acum = ft_vec3d_plus_vec3d(acum, ft_ray_color(&ray, img));
	}
	return (ft_write_color(acum, img->samplex_per_pixel));
}

void	ft_draw_antialiasing(t_data *img)
{
	int		x;
	int		y;
	int		colour;

	y = 0;
	while (y < img->display.height)
	{
		x = 0;
		while (x < img->display.width)
		{
			colour = ft_antialiasing(img, x, y);
			my_mlx_pixel_put(&img->display, x, y, colour);
			x++;
		}
		y++;
	}
}
