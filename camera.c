/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:04:11 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 16:55:05 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_img(t_data *img, const int image_width, const double aspect_ratio)
{
	const int	image_height = (int)image_width / aspect_ratio;

	ft_bzero(img, sizeof(t_data));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, image_width, image_height,
			"miniRT");
	img->img = mlx_new_image(img->mlx, image_width, image_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_hook(img->mlx_win, 17, 0, hook_close, img);
	img->image_width = image_width;
	img->image_height = image_height;
	img->aspect_ratio = aspect_ratio;
}

t_camera	*ft_init_camera(t_vec3d *origin, const double aspect_ratio)
{
	t_camera	*ptr;

	if (!origin)
		return (NULL);
	ptr = ft_calloc(1, sizeof(*ptr));
	if (!ptr)
		return (ptr);
	ptr->origin = origin;
	ptr->viewport_height = 2.0;
	ptr->viewport_width = aspect_ratio * ptr->viewport_height;
	ptr->focal_length = 1.0;
	ptr->t_max = INFINITY;
	ptr->lower_left_corner = ft_init_vec3d(origin->x
			- (ptr->viewport_width / 2),
			origin->y - (ptr->viewport_height / 2),
			origin->z - ptr->focal_length);
	return (ptr);
}
