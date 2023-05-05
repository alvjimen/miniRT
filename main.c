/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 13:19:15 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	

	mlx = mlx_init();
	mlx_win  = mlx_new_window(mlx, WIN_W, WIN_H, "Hello World");
	img.img = mlx_new_image(mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	ft_draw_square(&img, 0, 0, WIN_H, WIN_W);
	ft_draw_circle(&img, coordx_center(0), coordy_center(0), 10);
	printf("%f\n", ft_degree_to_radians(90));
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_hook(mlx_win, 17, 0, hook_close, &img);
	mlx_loop(mlx);
}
