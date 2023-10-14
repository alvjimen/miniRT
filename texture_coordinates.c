/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:45:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 18:46:48 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
void	ft_perlin_init(t_data *img)
{
	int		counter;

	counter = -1;
	while (++counter < 256)
		img->perlin_ranfloat[counter] = random_double(0, 1);
	img->perlin_init = 1;
}

void	ft_checker_texture(t_hit_record *rec, t_element *sphere, t_data *img)
{
	if (sphere)
		ft_perlin_init(img);
	else
		ft_perlin_init(img);
	ft_bzero(&rec->colour, sizeof(rec->colour));
		rec->colour.red = ft_perlin_noise(rec, img) * 255;
		rec->colour.green = ft_perlin_noise(rec, img) * 255;
		rec->colour.blue = ft_perlin_noise(rec, img) * 255;
}
*/
/*
u = i / (Nx - 1);
v = j / (Ny - 1);
*/
void	ft_checkerboard(t_hit_record *rec, t_element *element, t_data *img)
{
	if (((fmod(ft_dabs(rec->v), 0.05) < 0.025)
			== (fmod(ft_dabs(rec->u), 0.05) < 0.025)))
		ft_bzero(&rec->colour, sizeof(rec->colour));
	else
	{
		rec->colour.red = 255;
		rec->colour.green = 255;
		rec->colour.blue = 255;
	}
	if (element || img)
		return ;
}

/*
void	ft_checkerboard(t_hit_record *rec, t_element *element, t_data *img)
{
	t_vec3d	p;
	double	sines;

	p = ft_vec3d_unit_lenght(rec->normal);
	sines = sin(p.x * 10) * sin(p.y * 10) * sin(p.z * 10);
	if (sines < 0)
		ft_bzero(&rec->colour, sizeof(rec->colour));
	else
		rec->colour.red = 255;
	if (element || img)
		return ;
}
*/

/*
 * t_vec3d	ft_raw_vec3d_to_normalized(t_vec3d raw)
{
	t_vec3d	zer0_to_2;

	zer0_to_2 = ft_vec3d_div_double(raw, 255/2);
	return (ft_vec3d_plus_vec3d(zer0_to_2, ft_init_vec3d(1, 1, 1)));
}
*/
// https://stackoverflow.com/questions/41015574/raytracing-normal-mapping
t_vec3d	ft_new_normal(int x, int y, t_data *img, t_hit_record *rec)
{
	const int		pixel = get_mlx_pixel_colour(&img->normal, x, y);
	const t_m3x3	tbn = ft_tbn(rec->normal);
	t_vec3d			bump;

	bump = ft_pixel_to_raw_color_vec3d(pixel, img->bump.endian);
	bump = ft_vec3d_minus_vec3d(ft_vec3d_pro_double(ft_vec3d_unit_lenght(bump),
				2), ft_init_vec3d(1, 1, 1));
	bump = ft_vec3d_unit_lenght(ft_vec3d_pro_matrix(bump, tbn));
	return (bump);
}

void	ft_texture(t_data *img)
{
	if (img->textured == CHECKER)
		img->ft_texture = ft_checkerboard;
	if (img->textured == IMG)
		img->ft_texture = ft_checker_texture_image;
	if (img->textured == BUMP)
		img->ft_texture = ft_checker_bump;
	if (img->textured == NORMAL)
		img->ft_texture = ft_checker_normal;
	if (img->textured == BUMP_IMG)
		img->ft_texture = ft_checker_bump_image;
	if (img->textured == NORMAL_IMG)
		img->ft_texture = ft_checker_normal_image;
}
//https://stackoverflow.com/questions/41015574/raytracing-normal-mapping
// I should make to create a function for all rec->u, rec->v i, j

void	ft_checker_normal(t_hit_record *rec, t_element *element, t_data *img)
{
	int	i;
	int	j;

	rec->u = clamp(rec->u, 0.0, 1.0) + element->displacement_u;
	rec->v = clamp(rec->v, 0.0, 1.0) + element->displacement_v;
	ft_double_normalize(&rec->u);
	ft_double_normalize(&rec->v);
	i = rec->u * img->normal.width;
	j = rec->v * img->normal.height;
	if (i >= img->normal.width)
		i = img->normal.width - 1;
	if (j >= img->normal.height)
		j = img->normal.height - 1;
	rec->normal = ft_new_normal(i, j, img, rec);
	if (element)
		return ;
}

void	ft_checker_bump(t_hit_record *rec, t_element *element,
		t_data *img)
{
	int	i;
	int	j;

	rec->u = clamp(rec->u, 0.0, 1.0) + element->displacement_u;
	rec->v = clamp(rec->v, 0.0, 1.0) + element->displacement_v;
	ft_double_normalize(&rec->u);
	ft_double_normalize(&rec->v);
	i = rec->u * img->bump.width;
	j = rec->v * img->bump.height;
	if (i >= img->bump.width)
		i = img->bump.width - 1;
	if (j >= img->bump.height)
		j = img->bump.height - 1;
	rec->normal = ft_bump(i, j, img, rec);
	if (element)
		return ;
}
