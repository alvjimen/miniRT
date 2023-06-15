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

	if (argc < 2 && !*argv)
		return (1);
	ft_img(&img, WIN_W, ASPECT_RATIO);
	if (ft_parse_file(argv[1], &img))
		exit (-1);
	ft_draw_without_antialiasing(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
