/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/12 18:10:27 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	main(int argc, char	*argv[])
{
	t_data		img;
	size_t		pos;
	double		val;

	pos = 0;
	ft_parse_double("-100.5", &pos, &val);
	if (argc < 2 && !*argv)
		return (1);
	ft_img(&img, WIN_W, ASPECT_RATIO);
	//img.camera = ft_init_camera(ft_init_vec3d(-2, 2, 1), ASPECT_RATIO, 90,
	//		ft_init_vec3d(0, 0, -1));
	//	ft_world(&img);
	if (ft_parse_file(argv[1], &img))
		exit (-1);
	//ft_draw_antialiasing(&img);
	ft_draw_without_antialiasing(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
