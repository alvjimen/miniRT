/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/07/06 13:18:17 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	main(int argc, char	*argv[])
{
	t_data		img;

	if (argc < 2 && !*argv)
		return (1);
	ft_bzero(&img, sizeof(img));
	ft_img(&img, WIN_W, ASPECT_RATIO);
	ft_load_img(&img);
	if (ft_parse_file(argv[1], &img))
		exit (-1);
	img.value_color = AMBIANCE | DIFFUSE | SPECULAR;
	img.textured = CHECKER;
	ft_texture(&img);
	ft_img_color(&img);
	ft_draw_without_antialiasing(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
