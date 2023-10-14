/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:02:41 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 16:21:57 by dmacicio         ###   ########.fr       */
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
	if (ft_parse_colour(str, &pos, ft_colour(&colour, SPCE, SPCRE)))
		return (-1);
	if (ft_parse_end(str, pos, SPELE))
		return (-1);
	if (ft_sphere_ok(diameter, colour))
		return (-1);
	ft_putstr_fd("OK!\n", 1);
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
		|| ft_camera_ok(img, &norm_orient_vec, fov) || img->err)
		return (-1);
	img->camera = ft_init_camera(viewpoint, ASPECT_RATIO, fov,
			ft_vec3d_plus_vec3d(viewpoint, norm_orient_vec));
	ft_putstr_fd("OK!\n", 1);
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
