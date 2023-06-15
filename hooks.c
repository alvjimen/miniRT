/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:56:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/25 18:18:52 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_print_vector(const char *str, t_vec3d vector)
{
	printf(str);
	printf(": x: %f, y: %f, z: %f\n", vector.x, vector.y, vector.z);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == F2)
		ft_prt_ppm_file_from_img(img, img->image_width, img->image_height, 2);
	else if (keycode == F1)
	{
		img->camera = ft_init_camera(img->camera.lookfrom, ASPECT_RATIO,
				img->camera.fov, img->camera.lookat);
		img->ft_draw(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		printf("End of redraw\n");
	}
	else if (keycode == P)
		(ft_print_vector("lookfrom", img->camera.lookfrom), ft_print_vector("lookat", img->camera.lookat));
	else if (keycode == W)
		img->camera.lookfrom.z -= 0.1;
	else if (keycode == S)
		img->camera.lookfrom.z += 0.1;
	else if (keycode == A)
		img->camera.lookfrom.x -= 0.1;
	else if (keycode == D)
		img->camera.lookfrom.x += 0.1;
	else if (keycode == Q)
		img->camera.lookfrom.y -= 0.1;
	else if (keycode == E)
		img->camera.lookfrom.y += 0.1;
	else if (keycode == J)
		img->camera.lookat.x -= 0.1;
	else if (keycode == L)
		img->camera.lookat.x += 0.1;
	else if (keycode == I)
		img->camera.lookat.z -= 0.1;
	else if (keycode == K)
		img->camera.lookat.z += 0.1;
	else if (keycode == O)
		img->camera.lookat.y -= 0.1;
	else if (keycode == U)
		img->camera.lookat.y += 0.1;
	else
		printf("Keycode: %d\n", keycode);
	return (0);
}

int	hook_close(void)
{
	exit(0);
}
