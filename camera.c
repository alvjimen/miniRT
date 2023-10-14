/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:03:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 18:17:38 by dmacicio         ###   ########.fr       */
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
	img->mirror_limit = 50;
	img->display.img = mlx_new_image(img->mlx, image_width, image_height);
	img->display.address = mlx_get_data_addr(img->display.img,
			&img->display.bits_per_pixel, &img->display.line_length,
			&img->display.endian);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_hook(img->mlx_win, 17, 0, hook_close, img);
	mlx_mouse_hook(img->mlx_win, hook_mouse, img);
	img->display.width = image_width;
	img->display.height = image_height;
	img->aspect_ratio = aspect_ratio;
	img->samplex_per_pixel = 100;
	img->ft_draw = ft_draw_without_antialiasing;
	img->modifier = 0.1;
}

t_camera	ft_set_camera_vars(t_vec3d lookfrom, const double aspect_ratio,
		const double fov, t_vec3d lookat)
{
	t_camera	ptr;

	ft_bzero(&ptr, sizeof(ptr));
	ptr.lookfrom = lookfrom;
	ptr.lookat = lookat;
	ptr.aspect_ratio = aspect_ratio;
	ptr.fov = fov;
	ptr.origin = lookfrom;
	ptr.theta = ft_degree_to_radians(fov);
	ptr.h = tan(ptr.theta / 2);
	ptr.viewport_height = 2.0 * ptr.h;
	ptr.viewport_width = aspect_ratio * ptr.viewport_height;
	ptr.focal_length = 1.0;
	return (ptr);
}

t_camera	ft_init_camera(t_vec3d lookfrom, const double aspect_ratio,
		const double fov, t_vec3d lookat)
{
	t_camera		ptr;
	const t_vec3d	w = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(lookfrom,
				lookat));
	const t_vec3d	vup = ft_init_vec3d(0, 1, 0);
	const t_vec3d	u = ft_vec3d_unit_lenght(ft_vec3d_cross(vup, w));
	const t_vec3d	v = ft_vec3d_cross(w, u);

	ptr = ft_set_camera_vars(lookfrom, aspect_ratio, fov, lookat);
	ptr.horizontal = ft_vec3d_pro_double(u, ptr.viewport_width);
	ptr.vertical = ft_vec3d_pro_double(v, ptr.viewport_height);
	ptr.lower_left_corner = ft_vec3d_minus_vec3d(lookfrom,
			ft_vec3d_plus_vec3d(ft_vec3d_div_double(ptr.horizontal, 2.0),
				ft_vec3d_plus_vec3d(ft_vec3d_div_double(
						ptr.vertical, 2.0), w)));
	ptr.t_min = 0.0;
	ptr.t_max = INFINITY;
	return (ptr);
}

void	ft_fix_camera_lookat(t_camera *camera)
{
	if (camera->lookat.x == 0 && camera->lookat.z == 0)
		camera->lookat.x += 0.00000001;
}
//	ptr.t_min = 0.00001;
