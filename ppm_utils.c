/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:42:07 by dmacicio          #+#    #+#             */
/*   Updated: 2023/10/14 18:48:57 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_draw_all_pixels_to_ppm_from_img(t_mlx_img	*img, int width,
		int height, int fd)
{
	int		x;
	int		y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ft_draw_ppm_pixel(get_mlx_pixel_colour(img, x, y), fd, img->endian);
			x++;
		}
		y++;
	}
}

void	ft_prt_ppm_file_from_img(t_mlx_img *img, int width, int height, int fd)
{
	ft_draw_ppm_header(width, height, fd);
	ft_draw_all_pixels_to_ppm_from_img(img, width, height, fd);
}
