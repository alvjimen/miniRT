/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:51:54 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/11 20:36:33 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_cylinder_ok(t_cone_cylinder	cy)
{
	int err;
	int out;

	out = 0;
	err = cy.normalized_orientation_vector.x > 1;
	err |= cy.normalized_orientation_vector.x < -1;
	err |= cy.normalized_orientation_vector.y > 1;
	err |= cy.normalized_orientation_vector.y < -1;
	err |= cy.normalized_orientation_vector.z > 1;
	err |= cy.normalized_orientation_vector.z < -1;
	if (err)
		write(1, CYNOVRE, ft_strlen(CYNOVRE));
	if (cy.param[0] <= 0)
		write(1, CYDRE, ft_strlen(CYDRE));
	if (cy.param[1] <= 0)
		write(1, CYHRE, ft_strlen(CYHRE));
	if (cy.param[0] <= 0 || cy.param[1] <= 0 || err)
		out = -1;
	err = cy.colour.red > 255 || cy.colour.red < 0;
	err |= cy.colour.green > 255 || cy.colour.green < 0;
	err |= cy.colour.blue > 255 || cy.colour.blue < 0;
	if (err)
		write(1, CYHRE, ft_strlen(CYHRE));
	return (out - err);
}

int	ft_parse_cylinder(char *str, size_t pos, t_data *img)
{
	t_cone_cylinder	cy;

	img->num_cy++;
	pos += 2;
	if (ft_parse_vec3d(str, &pos, &cy.coords, CYCE))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &cy.normalized_orientation_vector, CYNOVE))
		return (-1);
	if (ft_parse_double(str, &pos, &cy.param[0], CYFPE))
		return (-1);
	if (ft_parse_double(str, &pos, &cy.param[1], CYSPE))
		return (-1);
	if (ft_parse_colour(str, &pos, &cy.colour, CYCOLOURE))
		return (-1);
	if (ft_cylinder_ok(cy))
		return (-1);
	cy.node = ft_lstnew(cylinder(cy.coords, cy.normalized_orientation_vector,
				cy.param, cy.colour));
	ft_lstadd_back(&img->world, cy.node);
	if (cy.node && cy.node->content && !ft_parse_end(str, pos, CYELE))
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_parse_cone(char *str, size_t pos, t_data *img)
{
	t_cone_cylinder	cn;

	pos += 2;
	if (ft_parse_vec3d(str, &pos, &cn.coords, CNCE))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &cn.normalized_orientation_vector, CNNOVE))
		return (-1);
	if (ft_parse_double(str, &pos, &cn.param[0], CNFPE))
		return (-1);
	if (ft_parse_double(str, &pos, &cn.param[1], CNSPE))
		return (-1);
	if (ft_parse_colour(str, &pos, &cn.colour, CNCOLOURE))
		return (-1);
	cn.node = ft_lstnew(cone(cn.coords, cn.normalized_orientation_vector,
				cn.param, cn.colour));
	ft_lstadd_back(&img->world, cn.node);
	if (cn.node && cn.node->content && !ft_parse_end(str, pos, CNELE))
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

int ft_valid_img(t_data *img)
{
	int minelement;

	if(!img)
		return (img->err);
	if (!img->numcamera)
		ft_putstr_fd(FENC, 1);
	minelement = !img->num_cy || !img->num_plane || !img->num_sphera;
	if (minelement)
		ft_putstr_fd(FEAL3E, 1);
	if(!img->err && (img->numcamera != 1 || minelement))
		return (-1);
	return (img->err);
}

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
			{
				//if(!img->err)
				return ft_valid_img(img);
				//return (img->err);
			}

			write(1, EFE, ft_strlen(EFE));
			return (-1);
			
		}
		anyline++;
		if (ft_parse_line(str, img))
			img->err = -1;;
//		free(str);
	}
	return (img->err);
}

int	ft_parse_end(char *str, size_t pos, char *msg)
{
	ft_run_is_space(str, &pos);
	if (str[pos] != '\0')
	{
		write(1, msg, ft_strlen(msg));
		return (-1);
	}
	return (0);
}

// if (ft_parse_line(str, img))
// {
// 	free(str);
// 	return (-1);
// }
		