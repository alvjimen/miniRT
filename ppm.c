/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:26:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/25 17:08:32 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_draw_ppm_header(int width, int height, int fd)
{
	ft_putstr_fd("P3\n", fd);
	ft_putnbr_fd(width, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(height, fd);
	ft_putstr_fd("\n255\n", fd);
}

void	ft_draw_ppm_pixel(int colour, int fd)
{
	ft_putnbr_fd(colour >> 16 & 0xff, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(colour >> 8 & 0xff, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(colour & 0xff, fd);
	ft_putchar_fd('\n', fd);
}

int	get_mlx_pixel_colour(t_data *img, int x, int y)
{
	char	*dst;
	int		colour;

	dst = img->addr + (y * img->line_length + x * 4);
	colour = *(int *)dst;
	return (colour);
}

static void	ft_draw_all_pixels_to_ppm_from_img(t_data	*img, int width,
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
			ft_draw_ppm_pixel(get_mlx_pixel_colour(img, x, y), fd);
			x++;
		}
		y++;
	}
}

void	ft_prt_ppm_file_from_img(t_data *img, int width, int height, int fd)
{
	ft_draw_ppm_header(width, height, fd);
	ft_draw_all_pixels_to_ppm_from_img(img, width, height, fd);
}
