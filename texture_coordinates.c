/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:45:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/09/08 16:30:42 by alvjimen         ###   ########.fr       */
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

void	ft_checkerboard_v2(t_hit_record *rec, t_element *element, t_data *img)
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
t_vec3d	ft_new_normal(int x, int y, t_data *img, t_hit_record *rec)
{
	unsigned char	*pixel;
	t_m3x3			tbn;
	t_vec3d			bump;
	t_vec3d			t;
	t_vec3d			b;

	t = ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 1, 0));
	if (!ft_vec3d_squared_len(t))
		t = ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 0, 1));
	t = ft_vec3d_unit_lenght(t);
	b = ft_vec3d_unit_lenght(ft_vec3d_cross(rec->normal, t));
	pixel = ((void *)&img->xpm_bump_address[y * img->xpm_bump_line_length
			+ x * (img->xpm_bump_bits_per_pixel / 8)]);
	bump = ft_init_vec3d(pixel[2], pixel[1], pixel[0]);
	bump = ft_vec3d_minus_vec3d(
			ft_vec3d_pro_double(ft_vec3d_div_double(bump,
					255), 2), ft_init_vec3d(1, 1, 1));
	tbn = ft_init_m3x3(t, b, rec->normal);
	bump = ft_vec3d_unit_lenght(ft_vec3d_pro_matrix(bump, tbn));
	return (bump);
}

void	ft_texture(t_data *img)
{
	if (img->textured == CHECKER)
		img->ft_texture = ft_checkerboard_v2;
	if (img->textured == IMG)
		img->ft_texture = ft_checker_texture_image;
	if (img->textured == BUMP)
		img->ft_texture = ft_checker_bump;
	if (img->textured == BUMP_IMG)
		img->ft_texture = ft_checker_bump_image;
}
//https://stackoverflow.com/questions/41015574/raytracing-normal-mapping

void	ft_checker_bump(t_hit_record *rec, t_element *sphere,
		t_data *img)
{
	int	i;
	int	j;

	rec->u = clamp(rec->u, 0.0, 1.0);
	rec->v = clamp(rec->v, 0.0, 1.0);
	i = rec->u * img->xpm_bump_width;
	j = rec->v * img->xpm_bump_height;
	if (i >= img->xpm_bump_width)
		i = img->xpm_bump_width - 1;
	if (j >= img->xpm_bump_height)
		j = img->xpm_bump_height - 1;
	rec->normal = ft_new_normal(i, j, img, rec);
	if (sphere)
		return ;
}

void	ft_checker_bump_image(t_hit_record *rec, t_element *sphere,
		t_data *img)
{
	ft_checker_bump(rec, sphere, img);
	ft_checker_texture_image(rec, sphere, img);
}
