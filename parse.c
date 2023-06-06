/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:02:41 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/06 19:46:45 by alvjimen         ###   ########.fr       */
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
	if (!ft_isdigit(str[*pos]))
		return (-1);
	while (str[*pos] == '.' || ft_isdigit(str[*pos]))
		pos[0]++;
	return (0);
}

int	ft_parse_camera(char *line, size_t pos, t_data *img)
{
	t_vec3d	viewpoint;
	t_vec3d	normalized_orientation_vector;
	double		fov;

	if (line[pos] != 'C')
		return (-1);
	ft_run_is_space(line, &pos);
	viewpoint.x = ft_atof(line + pos);
	ft_run_is_space(line, &pos);
	ft_run_atof(line, &pos);
	ft_run_is_space(line, &pos);
	viewpoint.y = ft_atof(line + pos);
	ft_run_atof(line, &pos);
	ft_run_is_space(line, &pos);
	viewpoint.z = ft_atof(line + pos);
	ft_run_atof(line, &pos);

	ft_run_is_space(line, &pos);
	normalized_orientation_vector.x = ft_atof(line + pos);
	ft_run_atof(line, &pos);
	ft_run_is_space(line, &pos);
	normalized_orientation_vector.y = ft_atof(line + pos);
	ft_run_atof(line, &pos);
	ft_run_is_space(line, &pos);
	normalized_orientation_vector.z = ft_atof(line + pos);
	ft_run_atof(line, &pos);
	ft_run_is_space(line, &pos);
	fov = ft_atof(line + pos);
	img->camera = ft_init_camera(viewpoint, ASPECT_RATIO, fov,
			normalized_orientation_vector);
	return (0);
}

int	ft_parse_line(char *line, t_data *img)
{
	size_t	pos;

	pos = 0;
	ft_run_is_space(line, &pos);
	if (line[pos] == '\0')
		return (0);
	if (line[pos] == 'C')
		return (ft_parse_camera(line, pos, img));
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
			return (-1);
		ft_parse_line(str, img);
		free(str);
	}
	return (0);
}
