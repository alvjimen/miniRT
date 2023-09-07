/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:02:41 by alvjimen          #+#    #+#             */
/*   Updated: 2023/09/07 15:40:42 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_parse_sphere(char *str, size_t pos, t_data *img)
{
	t_list		*node;
	t_colour	colour;
	t_vec3d		origin;
	double		diameter;

	if (str[pos] != 's' || str[pos + 1] != 'p')
		return (-1);
	ft_bzero(&colour, sizeof(colour));
	pos += 2;
	if (ft_parse_vec3d(str, &pos, &origin))
		return (-1);
	if (ft_parse_double(str, &pos, &diameter))
		return (-1);
	if (ft_parse_colour(str, &pos, &colour))
		return (-1);
	if (ft_parse_end(str, pos))
		return (-1);
	node = ft_lstnew(sphere(origin, diameter, colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content)
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_parse_camera(char *str, size_t pos, t_data *img)
{
	t_vec3d	viewpoint;
	t_vec3d	normalized_orientation_vector;
	double	fov;

	if (str[pos] != 'C')
		return (-1);
	pos++;
	if (ft_parse_vec3d(str, &pos, &viewpoint))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &normalized_orientation_vector))
		return (-1);
	if (ft_parse_double(str, &pos, &fov))
		return (-1);
	if (ft_parse_end(str, pos))
		return (-1);
	img->camera = ft_init_camera(viewpoint, ASPECT_RATIO, fov,
			ft_vec3d_plus_vec3d(viewpoint, normalized_orientation_vector));
	return (0);
}

int	ft_parse_ambient_light(char *str, size_t pos, t_data *img)
{
	t_colour	colour;
	double		intensity;

	if (str[pos] != 'A')
		return (-1);
	pos++;
	if (ft_parse_double(str, &pos, &intensity))
		return (-1);
	if (ft_parse_colour(str, &pos, &colour))
		return (-1);
	if (ft_parse_end(str, pos))
		return (-1);
	img->ambient_light = ambient_light(intensity, colour);
	return (0);
}

int	ft_parse_light(char *str, size_t pos, t_data *img)
{
	t_list		*node;
	t_vec3d		coords;
	t_colour	colour;
	double		brigthness;

	if (str[pos] != 'L')
		return (-1);
	pos++;
	ft_bzero(&colour, sizeof(colour));
	if (ft_parse_vec3d(str, &pos, &coords))
		return (-1);
	if (ft_parse_double(str, &pos, &brigthness))
		return (-1);
	ft_parse_colour(str, &pos, &colour);
	if (ft_parse_end(str, pos))
		return (-1);
	node = ft_lstnew(light(coords, brigthness, colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content)
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_parse_plane(char *str, size_t pos, t_data *img)
{
	t_list		*node;
	t_vec3d		normalized_orientation_vector;
	t_vec3d		coords;
	t_colour	colour;

	if (str[pos] != 'p' || (str[pos] && str[pos + 1] != 'l'))
		return (-1);
	pos += 2;
	if (ft_parse_vec3d(str, &pos, &coords))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &normalized_orientation_vector))
		return (-1);
	if (ft_parse_colour(str, &pos, &colour))
		return (-1);
	if (ft_parse_end(str, pos))
		return (-1);
	node = ft_lstnew(plane(coords, normalized_orientation_vector, colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content)
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}
