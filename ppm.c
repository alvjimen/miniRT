/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:26:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/07 18:30:18 by alvjimen         ###   ########.fr       */
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
// TODO depends of the endian if endian == 1 R 1 G 2 B 3

void	ft_draw_ppm_pixel(int colour, int fd, int endian)
{
	if (!endian)
	{
		ft_putnbr_fd(colour >> 16 & 0xff, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(colour >> 8 & 0xff, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(colour & 0xff, fd);
	}
	else
	{
		ft_putnbr_fd(colour >> 8 & 0xff, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(colour >> 16 & 0xff, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(colour >> 24 & 0xff, fd);
	}
	ft_putchar_fd('\n', fd);
}

void	ft_clamp_mlx_pixel(t_mlx_img *img, int *x, int *y)
{
	if (img->width < *x)
		*x = img->width;
	else if (0 > *x)
		x = 0;
	if (img->line_length < *y)
		*y = img->line_length;
	else if (0 > *y)
		*y = 0;
}

int	get_mlx_pixel_colour(t_mlx_img *img, int x, int y)
{
	char	*dst;
	int		colour;

	ft_clamp_mlx_pixel(img, &x, &y);
	dst = img->address + y * img->line_length + x * (img->bits_per_pixel / 8);
	colour = *(int *)dst;
	return (colour);
}

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
