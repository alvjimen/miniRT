/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:51:54 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/14 16:46:56 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_cylinder_ok(t_cone_cylinder	cy)
{
	int	err;
	int	out;

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
	if (ft_parse_colour(str, &pos, ft_colour(&cy.colour, CYCOLE, CYCOLRE)))
		return (-1);
	if (ft_cylinder_ok(cy))
		return (-1);
	ft_putstr_fd("OK!\n", 1);
	cy.node = ft_lstnew(cylinder(cy.coords, cy.normalized_orientation_vector,
				cy.param, cy.colour));
	ft_lstadd_back(&img->world, cy.node);
	if (cy.node && cy.node->content && !ft_parse_end(str, pos, CYELE))
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_cone_ok(t_cone_cylinder	cn)
{
	int	err;
	int	out;

	out = 0;
	err = cn.normalized_orientation_vector.x > 1;
	err |= cn.normalized_orientation_vector.x < -1;
	err |= cn.normalized_orientation_vector.y > 1;
	err |= cn.normalized_orientation_vector.y < -1;
	err |= cn.normalized_orientation_vector.z > 1;
	err |= cn.normalized_orientation_vector.z < -1;
	if (err)
		ft_putstr_fd(CNNOVRE, 1);
	if (cn.param[0] <= 0)
		ft_putstr_fd(CNDRE, 1);
	if (cn.param[1] <= 0)
		ft_putstr_fd(CNHRE, 1);
	if (cn.param[0] <= 0 || cn.param[1] <= 0 || err)
		out = -1;
	return (out - err);
}

int	ft_parse_cone(char *str, size_t pos, t_data *img)
{
	t_cone_cylinder	cn;

	pos += 2;
	if (ft_parse_vec3d(str, &pos, &cn.coords, CNCE))
		return (-1);
	if (ft_parse_vec3d(str, &pos, &cn.normalized_orientation_vector, CNNOVE))
		return (-1);
	if (ft_parse_double(str, &pos, &cn.param[0], CNDE))
		return (-1);
	if (ft_parse_double(str, &pos, &cn.param[1], CNHE))
		return (-1);
	if (ft_parse_colour(str, &pos, ft_colour(&cn.colour, CNCOLE, CNCOLRE)))
		return (-1);
	if (ft_cone_ok(cn))
		return (-1);
	ft_putstr_fd("OK!\n", 1);
	cn.node = ft_lstnew(cone(cn.coords, cn.normalized_orientation_vector,
				cn.param, cn.colour));
	ft_lstadd_back(&img->world, cn.node);
	if (cn.node && cn.node->content && !ft_parse_end(str, pos, CNELE))
		return (0);
	ft_lstclear(&img->world, free);
	return (1);
}

int	ft_parse_line(char *str, t_data *img, int line)
{
	size_t	pos;

	ft_putstr_fd("Línea ", 1);
	ft_putnbr_fd(line, 1);
	ft_putstr_fd(": ", 1);
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
