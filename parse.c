/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:02:41 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/08 18:17:21 by alvjimen         ###   ########.fr       */
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
	double		fov;

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
			normalized_orientation_vector);
	return (0);
}

int	ft_parse_line(char *str, t_data *img)
{
	size_t	pos;

	pos = 0;
	ft_run_is_space(str, &pos);
	if (str[pos] == '\0')
		return (0);
	if (str[pos] == 'C')
		return (ft_parse_camera(str, pos, img));
	else if (str[pos] == 's' && str[pos + 1] == 'p')
		return (ft_parse_sphere(str, pos, img));
	return (0);
}

int	ft_parse_file(char *file, t_data *img)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0 || fd > FD_SETSIZE)
		return (-1);
	str = (void *)1;
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			return (0);
		if (ft_parse_line(str, img))
		{
			free(str);
			return (-1);
		}
		free(str);
	}
	return (0);
}