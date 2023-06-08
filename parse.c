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

void	ft_run_is_space(char *str, size_t *pos)
{
	if (!str || !pos)
		return ;
	while (ft_is_space(str[*pos]))
		pos[0]++;
}

/*return -1 if no digit*/
int	ft_run_atof(char *str, size_t *pos)
{
	if (ft_is_plus_or_minus(str[*pos], str[*pos]))
		pos[0]++;
	if ( !ft_isdigit(str[*pos]))
		return (-1);
	while (str[*pos] == '.' || ft_isdigit(str[*pos]))
		pos[0]++;
	return (0);
}

int	ft_parse_double(char *str, size_t *pos, double *value)
{
	ft_run_is_space(str, pos);
	*value = ft_atof(str + *pos);
	return (ft_run_atof(str, pos));
}

int	ft_parse_comma(char *str, size_t *pos)
{
	ft_run_is_space(str, pos);
	if ((str[*pos] != ','))
		return (-1);
	pos[0]++;
	return (0);
}

int	ft_parse_vec3d(char *str, size_t *pos, t_vec3d *vector)
{
	if (ft_parse_double(str, pos, &vector->x))
		return (-1);
	if (ft_parse_comma(str, pos))
		return (-1);
	if (ft_parse_double(str, pos, &vector->y))
		return (-1);
	if (ft_parse_comma(str, pos))
		return (-1);
	if (ft_parse_double(str, pos, &vector->z))
		return (-1);
	return (0);
}

int	ft_parse_end(char *str, size_t pos)
{
	ft_run_is_space(str, &pos);
	if (str[pos] != '\0')
		return (-1);
	return (0);
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
		ft_parse_line(str, img);
		free(str);
	}
	return (0);
}
