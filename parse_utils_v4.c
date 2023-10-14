/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_v4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:13:58 by dmacicio          #+#    #+#             */
/*   Updated: 2023/10/14 16:51:02 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_colour	*ft_colour(t_colour *c, char *ce, char *cre)
{
	c->ce = ce;
	c->cre = cre;
	return (c);
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
		err = ft_parse_colour(str, &pos, ft_colour(&colour, ALCE, ALCRE));
	if (!err)
		err = ft_parse_end(str, pos, ALELE);
	if (!err)
		err = ft_ambient_light_ok(intensity, colour);
	if (!err)
		ft_putstr_fd("OK!\n", 1);
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
		ft_putstr_fd(c.cre, 1);
		err = -1;
	}
	if (brighness > 1 || brighness < 0)
	{
		ft_putstr_fd(LBRE, 1);
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
	ret = ft_parse_vec3d(str, &pos, &coords, LCE) < 0;
	ret = (ret || ft_parse_double(str, &pos, &brigthness, LBE) < 0);
	if (!ret)
		ret = ft_parse_colour(str, &pos, ft_colour(&colour, LCOLE, LCOLRE)) < 0;
	ret = (ret || ft_parse_end(str, pos, LELE) < 0);
	ret = (ret || ft_valid_light(brigthness, colour) < 0);
	if (!ret)
		ft_putstr_fd("OK!\n", 1);
	if (ret || img->err)
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
		ft_putstr_fd(c.cre, 1);
		err = -1;
	}
	if (nov.x > 1 || nov.x < -1 || nov.y > 1 || nov.y < -1
		|| nov.z > 1 || nov.z < -1)
	{
		ft_putstr_fd(PNOVRE, 1);
		err = -1;
	}
	return (err);
}
