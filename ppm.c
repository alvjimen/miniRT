/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:26:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 18:48:57 by dmacicio         ###   ########.fr       */
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
