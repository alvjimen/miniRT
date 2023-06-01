/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/01 13:34:01 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	main(void)
{
	t_data		img;

	ft_img(&img, WIN_W, ASPECT_RATIO);
	img.camera = ft_init_camera(ft_init_vec3d(0, 0, 0), ASPECT_RATIO);
	if (!img.camera)
		return (1);
	ft_world(&img);
	//ft_draw_background_v2(&img);
	ft_draw_background_v3(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
