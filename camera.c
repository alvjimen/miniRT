/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:04:11 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/21 08:35:06 by alvjimen         ###   ########.fr       */
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
	mlx_mouse_hook(img->mlx_win, hook_mouse, img);
	img->image_width = image_width;
	img->image_height = image_height;
	img->aspect_ratio = aspect_ratio;
	img->samplex_per_pixel = 100;
	img->ft_draw = ft_draw_without_antialiasing;
}

t_camera	ft_init_camera(t_vec3d lookfrom, const double aspect_ratio,
		const double fov, t_vec3d lookat)
{
	t_camera	ptr;
	t_vec3d		w;
	t_vec3d		u;
	t_vec3d		v;
	t_vec3d		vup;

	/* Added for navigate and save the values that got */
	ptr.lookfrom = lookfrom;
	ptr.lookat = lookat;
	/* End */
	ptr.aspect_ratio = aspect_ratio;
	ptr.fov = fov;
	ptr.origin = lookfrom;
	ptr.theta = ft_degree_to_radians(fov);
	ptr.h = tan(ptr.theta / 2);
	ptr.viewport_height = 2.0 * ptr.h;
	ptr.viewport_width = aspect_ratio * ptr.viewport_height;
	ptr.focal_length = 1.0;
	/*Recalculate for move lookat 1*/
	w = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(lookfrom, lookat));
	/*End*/
	vup = ft_init_vec3d(0, 1, 0);
	/*Recalculate for move camera 2*/
	u = ft_vec3d_unit_lenght(ft_vec3d_cross(vup, w));
	v = ft_vec3d_cross(w, u);
	ptr.horizontal = ft_vec3d_pro_double(u, ptr.viewport_width);
	ptr.vertical = ft_vec3d_pro_double(v, ptr.viewport_height);
	ptr.lower_left_corner = ft_vec3d_minus_vec3d(lookfrom,
			ft_vec3d_plus_vec3d(ft_vec3d_div_double(ptr.horizontal, 2.0),
				ft_vec3d_plus_vec3d(ft_vec3d_div_double(
						ptr.vertical, 2.0), w)));
	/*End*/
	ptr.t_min = 0.0;//0.2
	ptr.t_max = INFINITY;
	return (ptr);
}
