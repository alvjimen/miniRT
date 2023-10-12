/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_coordinates_figures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:12:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 16:59:17 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
y = -cos(tetha)
x = -cos(phi)sin(tetha)
z = sin(phi)sin(tetha)

u = phi / (2 * PI)
v = tetha / PI
phi = with atan2(z, -x)
phi = atan2(-z, x) + PI
tetha = acos(-y)
*/
void	ft_sphere_uv(t_hit_record *rec, t_element *sphere)
{
	t_vec3d	p;
	double	theta;
	double	phi;

	p = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(sphere->coords, rec->p));
	theta = acos(-p.y);
	phi = atan2(-p.z, p.x) + M_PI;
	rec->u = phi / (2 * M_PI);
	rec->v = theta / M_PI;
}

/*
 * u = (M_PI + tetha) / (2 * M_PI)
 * v = (h/2 + y) / h
*/
void	ft_plane_uv(t_hit_record *rec, t_element *plane)
{
	t_m3x3	tbn;

	tbn = ft_tbn(rec->normal);
	rec->u = ft_vec3d_dot(ft_vec3d_pro_matrix(rec->p, tbn),
			ft_init_vec3d(1, 0, 0));
	rec->v = ft_vec3d_dot(ft_vec3d_pro_matrix(rec->p, tbn),
			ft_init_vec3d(0, 1, 0));
	rec->u = fmod(rec->u, 17.777778);
	rec->v = fmod(rec->v, 10.0);
	if (rec->u < 0)
		rec->u = rec->u + 17.777778;
	if (rec->v < 0)
		rec->v = rec->v + 10;
	rec->u = ft_dabs((rec->u / 17.777778) - 1);
	rec->v = rec->v / 10;
	if (plane)
		return ;
}

void	ft_cylinder_uv(t_hit_record *rec, t_element *cylinder)
{
	rec->u = 0.5 + atan2(rec->normal.x / cylinder->radius,
			rec->normal.z / cylinder->radius) / (2 * M_PI);
	rec->v = 1 - (rec->q / cylinder->height);
}

void	ft_cone_uv(t_hit_record *rec, t_element *cylinder)
{
	rec->u = ft_dabs(1 - (0.5 + atan2(rec->normal.x / cylinder->radius,
					rec->normal.z / cylinder->radius) / (2 * M_PI)));
	rec->v = 1 - (rec->q / cylinder->height);
}
/*
double	ft_perlin_noise(t_hit_record *rec, t_data *img)
{
	int	i;
	int	j;
	int	k;

	if (!img->perlin_init)
		ft_perlin_init(img);
	i = (int)(4 * rec->p.x) & 0xff;
	j = (int)(4 * rec->p.y) & 0xff;
	k = (int)(4 * rec->p.z) & 0xff;
	return (img->perlin_ranfloat[i ^ j ^ k]);
}
*/
