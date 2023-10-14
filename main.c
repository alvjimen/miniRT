/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 16:42:30 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_leaks(void)
{
	system("leaks graphics");
}

int	main(int argc, char	*argv[])
{
	t_data		img;

	if (argc < 2 && !*argv)
		return (1);
	ft_leaks();
	ft_bzero(&img, sizeof(img));
	ft_img(&img, WIN_W, ASPECT_RATIO);
	if (ft_load_img(&img) || ft_parse_file(argv[1], &img))
		exit (-1);
	img.value_color = AMBIANCE | DIFFUSE | SPECULAR;
	ft_img_color(&img);
	ft_draw_without_antialiasing(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.display.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
