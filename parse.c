/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:02:41 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/11 18:52:43 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_sphere_ok(double diameter, t_colour c)
{
	int	err;

	err = (c.red < 0 || c.green < 0 || c.blue < 0);
	if (err || (c.red > 255 || c.green > 255 || c.blue > 255))
	{
		write(1, SPCRE, ft_strlen(SPCRE));
		err = -1;
	}
	if (diameter <= 0)
	{
		write(1, SPDRE, ft_strlen(SPDRE));
		err = -1;
	}
	return (err);
}

int	ft_parse_sphere(char *str, size_t pos, t_data *img)
{
	t_list		*node;
	t_colour	colour;
	t_vec3d		origin;
	double		diameter;

	img->num_sphera++;
	ft_bzero(&colour, sizeof(colour));
	pos += 2;
	if (ft_parse_vec3d(str, &pos, &origin, SPOE))
		return (-1);
	if (ft_parse_double(str, &pos, &diameter, SPDE))
		return (-1);
	if (ft_parse_colour(str, &pos, &colour, SPCE))
		return (-1);
	if (ft_parse_end(str, pos, SPELE))
		return (-1);
	if (ft_sphere_ok(diameter, colour))
		return (-1);
	node = ft_lstnew(sphere(origin, diameter, colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content)
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_camera_ok(t_data *img, t_vec3d *nov, double fov)
{
	int	err;

	err = 0;
	if (nov->x > 1 || nov->x < -1 || nov->y > 1 || nov->y < -1
		|| nov->z > 1 || nov->z < -1)
	{
		write(1, CNOVRE, ft_strlen(CNOVRE));
		img->err = -1;
	}
	if (fov > (double)180 || (double)fov < 0)
	{
		write(1, CFOVRE, ft_strlen(CFOVRE));
		err = -1;
	}
	return (err);
}

int	ft_parse_camera(char *str, size_t pos, t_data *img)
{
	t_vec3d	viewpoint;
	t_vec3d	norm_orient_vec;
	double	fov;

	if (0 != img->numcamera)
	{
		ft_putstr_fd(FEMTOC, 1);
		return (-1);
	}
	img->numcamera++;
	pos++;
	if (ft_parse_vec3d(str, &pos, &viewpoint, CVE))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &norm_orient_vec, CNOVE))
		return (-1);
	if (ft_parse_double(str, &pos, &fov, CFOVE))
		return (-1);
	if (ft_parse_end(str, pos, CELE)
		|| ft_camera_ok(img, &norm_orient_vec, fov))
		return (-1);
	if (img->err)
		return (-1);
	img->camera = ft_init_camera(viewpoint, ASPECT_RATIO, fov,
			ft_vec3d_plus_vec3d(viewpoint, norm_orient_vec));
	return (0);
}

int	ft_ambient_light_ok(double intensity, t_colour c)
{
	int	err;

	err = (c.red < 0 || c.green < 0 || c.blue < 0);
	if (err || (c.red > 255 || c.green > 255 || c.blue > 255))
	{
		write(1, ALCRE, ft_strlen(ALCRE));
		err = -1;
	}
	if (intensity > 1 || intensity < 0)
	{
		write(1, ALIRE, ft_strlen(ALIRE));
		err = -1;
	}
	return (err);
}

int	ft_parse_ambient_light(char *str, size_t pos, t_data *img)
{
	t_colour	colour;
	double		intensity;
	int			err;

	if (0 != img->num_ambient_light)
	{
		ft_putstr_fd(FEMTOAL, 1);
		return (-1);
	}
	img->num_ambient_light++;
	pos++;
	err = ft_parse_double(str, &pos, &intensity, ALIE);
	if (!err)
		err = ft_parse_colour(str, &pos, &colour, ALCE);
	if (!err)
		err = ft_parse_end(str, pos, ALELE);
	if (!err)
		err = ft_ambient_light_ok(intensity, colour);
	if (err || img->err)
		return (-1);
	img->ambient_light = ambient_light(intensity, colour);
	return (0);
}

int	ft_valid_light(double brighness, t_colour c)
{
	int	err;

	err = (c.red < 0 || c.green < 0 || c.blue < 0);
	if (err || (c.red > 255 || c.green > 255 || c.blue > 255))
	{
		write(1, LCRE, ft_strlen(LCRE));
		err = -1;
	}
	if (brighness > 1 || brighness < 0)
	{
		write(1, LBRE, ft_strlen(LBRE));
		err = -1;
	}
	return (err);
}

int	ft_parse_light(char *str, size_t pos, t_data *img)
{
	t_list		*node;
	t_vec3d		coords;
	t_colour	colour;
	double		brigthness;
	int			ret;

	pos++;
	ft_bzero(&colour, sizeof(colour));
	ret = ft_parse_vec3d(str, &pos, &coords, LCE) == -1;
	ret = (1 == ret) || -1 == ft_parse_double(str, &pos, &brigthness, LBE);
	ret = (1 == ret) || -1 == ft_parse_colour(str, &pos, &colour, LCOLOURE);
	ret = (1 == ret) || -1 == ft_parse_end(str, pos, LELE);
	ret = (1 == ret) || -1 == ft_valid_light(brigthness, colour);
	if(ret || img->err)
		return (-1);
	node = ft_lstnew(light(coords, brigthness, colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content)
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_plane_ok(t_vec3d nov, t_colour c)
{
	int	err;

	err = (c.red < 0 || c.green < 0 || c.blue < 0);
	if (err || (c.red > 255 || c.green > 255 || c.blue > 255))
	{
		write(1, PCRE, ft_strlen(PCRE));
		err = -1;
	}
	if (nov.x > 1 || nov.x < -1 || nov.y > 1 || nov.y < -1
		|| nov.z > 1 || nov.z < -1)
	{
		write(1, PNOVRE, ft_strlen(PNOVRE));
		err = -1;
	}
	return (err);
}

int	ft_parse_plane(char *str, size_t pos, t_data *img)
{
	t_list		*node;
	t_vec3d		normalized_orientation_vector;
	t_vec3d		coords;
	t_colour	colour;

	img->num_plane++;
	pos += 2;
	if (ft_parse_vec3d(str, &pos, &coords, PCE))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &normalized_orientation_vector, PNOVE))
		return (-1);
	if (ft_parse_colour(str, &pos, &colour, PCOLOURE))
		return (-1);
	if (ft_parse_end(str, pos, PELE))
		return (-1);
	if (ft_plane_ok(normalized_orientation_vector, colour))
		return (-1);
	node = ft_lstnew(plane(coords, normalized_orientation_vector, colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content)
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}
