/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 13:28:34 by dmacicio         ###   ########.fr       */
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

	ft_fix_camera_lookat(&img->camera);
	y = 0;
	while (y < img->display.height)
	{
		x = 0;
		while (x < img->display.width)
		{
			vector = ft_ray_direction(img, x, y, 0);
			ray = ft_init_ray(img->camera.origin, vector);
			img->mirror_limit = 50;
			colour = ft_ray_color(&ray, img);
			my_mlx_pixel_put(&img->display, x, y, ft_write_color(colour, 1));
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
