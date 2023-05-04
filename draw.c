/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/04 13:15:19 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_draw_square(t_data *img, int px, int py, int width, int height)
{
	int		counterx = 0;
	int		countery = 0;
	unsigned char	red = 0xFF;
	unsigned char	blue = 0xFF;
	unsigned char	green = 0xFF;
	int		colour;
	colour = red << 16 | blue << 8 | green;
	while (px + counterx < WIN_W && px + counterx >= 0 && width >= counterx)
	{
		countery = 0;
		while (py + countery < WIN_H && py + countery >= 0 && height >= countery)
		{
			my_mlx_pixel_put(img, py + countery, px + counterx, colour);
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
