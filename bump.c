/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:54:02 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/07 15:12:18 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

//int				get_mlx_pixel_colour(t_mlx_img *img, int x, int y);
//t_vec3d			ft_pixel_to_raw_color_vec3d(int pixel, int endian;
t_vec3d	ft_raw_vec3d_to_normalized(t_vec3d raw)
{
	t_vec3d	m1_to_1;
	t_vec3d	v_0_to_2;
	t_vec3d	v_0_to_1;

	m1_to_1 = ft_vec3d_div_double(raw, 255);
	v_0_to_2 = ft_vec3d_plus_vec3d(m1_to_1, ft_init_vec3d(1, 1, 1));
	v_0_to_1 = ft_vec3d_div_double(v_0_to_2, 2);
	v_0_to_2 = ft_vec3d_pro_double(v_0_to_2, 2);
	v_0_to_1 = ft_vec3d_minus_vec3d(v_0_to_2, ft_init_vec3d(1, 1, 1));
	return (v_0_to_1);
}

t_vec3d	ft_bu(t_mlx_img *img, int x, int y)
{
	t_vec3d	ou;
	t_vec3d	ou1;
	t_vec3d	ou2;

	ou1 = ft_pixel_to_raw_color_vec3d(get_mlx_pixel_colour(img, x, y),
			img->endian);
	if (x == img->line_length)
		x = -1;
	ou2 = ft_pixel_to_raw_color_vec3d(get_mlx_pixel_colour(img, x + 1, y),
			img->endian);
	ou = ft_vec3d_minus_vec3d(ou1, ou2);
	ou = ft_raw_vec3d_to_normalized(ou);
//	ou = ft_vec3d_div_double(ou, 2);
	return (ou);
}

t_vec3d	ft_bv(t_mlx_img *img, int x, int y)
{
	t_vec3d	ov;
	t_vec3d	ov1;
	t_vec3d	ov2;

	ov1 = ft_pixel_to_raw_color_vec3d(get_mlx_pixel_colour(img, x, y),
			img->endian);
	if (y == 0)
		y = img->height;
	ov2 = ft_pixel_to_raw_color_vec3d(get_mlx_pixel_colour(img, x, y - 1),
			img->endian);
	ov = ft_vec3d_minus_vec3d(ov1, ov2);
	ov = ft_raw_vec3d_to_normalized(ov);
//	ov = ft_vec3d_div_double(ov, 2);
	return (ov);
}

t_vec3d	ft_bump(int x, int y, t_data *img, t_hit_record *rec)
{
	t_vec3d			bu;
	t_vec3d			bv;
	t_vec3d			normal;
	const t_m3x3	tbn = ft_tbn(rec->normal);

	bu = ft_bu(&img->bump, x, y);
	bu = ft_vec3d_cross(bu, rec->normal);
	bv = ft_bv(&img->bump, x, y);
	bu = ft_vec3d_cross(bv, rec->normal);
	bu = ft_init_vec3d(1, 0, bu.x);
	bv = ft_init_vec3d(0, 1, bv.y);
	normal = ft_vec3d_cross(bu, bv);
	normal = ft_vec3d_unit_lenght(normal);
	normal = ft_vec3d_pro_matrix(normal, tbn);
	normal = ft_vec3d_unit_lenght(normal);
	return (normal);
}
