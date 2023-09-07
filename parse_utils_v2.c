/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:51:54 by alvjimen          #+#    #+#             */
/*   Updated: 2023/09/07 17:09:22 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_parse_cylinder(char *str, size_t pos, t_data *img)
{
	t_list		*node;
	t_vec3d		normalized_orientation_vector;
	t_vec3d		coords;
	double		param[2];
	t_colour	colour;

	if (str[pos] != 'c' || str[pos + 1] != 'y')
		return (-1);
	pos += 2;
	if (ft_parse_vec3d(str, &pos, &coords))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &normalized_orientation_vector))
		return (-1);
	if (ft_parse_double(str, &pos, &param[0]))
		return (-1);
	if (ft_parse_double(str, &pos, &param[1]))
		return (-1);
	if (ft_parse_colour(str, &pos, &colour))
		return (-1);
	node = ft_lstnew(cylinder(coords, normalized_orientation_vector, param,
				colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content && !ft_parse_end(str, pos))
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_parse_cone(char *str, size_t pos, t_data *img)
{
	t_list		*node;
	t_vec3d		normalized_orientation_vector;
	t_vec3d		coords;
	double		param[2];
	t_colour	colour;

	if (str[pos] != 'c' || str[pos + 1] != 'o')
		return (-1);
	pos += 2;
	if (ft_parse_vec3d(str, &pos, &coords))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &normalized_orientation_vector))
		return (-1);
	if (ft_parse_double(str, &pos, &param[0]))
		return (-1);
	if (ft_parse_double(str, &pos, &param[1]))
		return (-1);
	if (ft_parse_colour(str, &pos, &colour))
		return (-1);
	node = ft_lstnew(cone(coords, normalized_orientation_vector, param,
				colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content && !ft_parse_end(str, pos))
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_parse_line(char *str, t_data *img)
{
	size_t	pos;

	pos = 0;
	ft_run_is_space(str, &pos);
	if (str[pos] == '\0')
		return (0);
	else if (str[pos] == 'C')
		return (ft_parse_camera(str, pos, img));
	else if (str[pos] == 'L')
		return (ft_parse_light(str, pos, img));
	else if (str[pos] == 'A')
		return (ft_parse_ambient_light(str, pos, img));
	else if (str[pos] == 's' && str[pos + 1] == 'p')
		return (ft_parse_sphere(str, pos, img));
	else if (str[pos] == 'p' && str[pos + 1] == 'l')
		return (ft_parse_plane(str, pos, img));
	else if (str[pos] == 'c' && str[pos + 1] == 'y')
		return (ft_parse_cylinder(str, pos, img));
	else if (str[pos] == 'c' && str[pos + 1] == 'o')
		return (ft_parse_cone(str, pos, img));
	return (-1);
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

int	ft_parse_end(char *str, size_t pos)
{
	ft_run_is_space(str, &pos);
	if (str[pos] != '\0')
		return (-1);
	return (0);
}
