/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_v3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:04:25 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 16:51:15 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_parse_file(char *file, t_data *img)
{
	int		fd;
	char	*str;
	int		anyline;

	fd = open(file, O_RDONLY);
	if (fd < 0 || fd > FD_SETSIZE)
		return (-1);
	str = (void *)1;
	img->err = 0;
	anyline = 0;
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
		{
			if (anyline)
				return (ft_valid_img(img));
			ft_putstr_fd(EFE, 1);
			return (-1);
		}
		anyline++;
		img->err += ft_parse_line(str, img, anyline);
		free(str);
	}
	return (img->err);
}

int	ft_parse_end(char *str, size_t pos, char *msg)
{
	ft_run_is_space(str, &pos);
	if (str[pos] != '\0')
	{
		ft_putstr_fd(msg, 1);
		return (-1);
	}
	return (0);
}

int	ft_valid_img(t_data *img)
{
	if (!img)
		return (img->err);
	if (!img->numcamera)
		ft_putstr_fd(FENC, 1);
	if (!img->err && img->numcamera != 1)
		return (-1);
	return (img->err);
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
	if (ft_parse_colour(str, &pos, ft_colour(&colour, PCOLE, PCOLRE)))
		return (-1);
	if (ft_parse_end(str, pos, PELE))
		return (-1);
	if (ft_plane_ok(normalized_orientation_vector, colour))
		return (-1);
	ft_putstr_fd("OK!\n", 1);
	node = ft_lstnew(plane(coords, normalized_orientation_vector, colour));
	ft_lstadd_back(&img->world, node);
	if (node && node->content)
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}
