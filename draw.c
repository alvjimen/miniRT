/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 07:05:03 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_color_double_to_int(double c)
{
	return (c * 255.999);
}

void	ft_draw_background_v2(t_data *img)
{
	int		x;
	int		y;
	int		colour;
	t_ray	*ray;
	t_vec3d	*vector;

	y = 0;
	while (y < img->image_height)
	{
		x = 0;
		while (x < img->image_width)
		{
			vector =  ft_ray_direction(img, x, img->image_height - (y + 1));
			ray = ft_init_ray(img->camera->origin, vector);
			if (!ray)
			{
				free(vector);
				return ;
			}
			colour = ft_ray_color(ray);
			ft_destroy_ray(ray);
			my_mlx_pixel_put(img, x, y, colour);
			x++;
		}
		y++;
	}
}

void	ft_draw_background(t_data *img)
{
	int	x;
	int	y;
	int	colour;

	y = 0;
	while (y < img->image_height)
	{
		x = 0;
		while (x < img->image_width)
		{
			colour = (int)(((double)x / (img->image_width - 1)) * 255.999) << 16
				| (int)(((double)y / (img->image_height - 1)) * 255.999) << 8
				| (int)(0.25 * 255.999);
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
