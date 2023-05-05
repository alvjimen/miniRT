/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 11:05:11 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_draw_square(t_data *img, int px, int py, int width, int height)
{
	int		counterx = 0;
	int		countery = 0;
	while (px + counterx < WIN_W && px + counterx >= 0 && width >= counterx)
	{
		countery = 0;
		while (py + countery < WIN_H && py + countery >= 0 && height >= countery)
		{
			my_mlx_pixel_put(img, py + countery, px + counterx, 0xffffff);
			countery++;
		}
		counterx++;
	}
}

int	circle_form(int px, int py, int cx, int cy)
{
	int	resultx;
	int	resulty;

	resultx = cx - px;
	resultx *= resultx;
	resulty = cy - py;
	resulty *= resulty;
	return (resultx + resulty);
}
/*if ((resultx + resulty) <= (radius * radius))*/

void	ft_draw_circle(t_data *img, int cx, int cy, int radius)
{
	int		counterx = 0;
	int		countery = 0;
	while (counterx < WIN_W && counterx >= 0)
	{
		countery = 0;
		while (countery < WIN_H && countery >= 0)
		{
			if (circle_form(counterx, countery, cx, cy) <= (radius * radius))
				my_mlx_pixel_put(img, counterx, countery, 0xff0000);
			countery++;
		}
		counterx++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y *data->line_length + x * 4);
	*(unsigned int *)dst = color;
}
