/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:47:36 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 13:35:43 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_parse_double(char *str, size_t *pos, double *value, char *msg)
{
	ft_run_is_space(str, pos);
	if (ft_is_valid_double(str + *pos))
	{
		write(1, msg, ft_strlen(msg));
		return (-1);
	}
	*value = ft_atof(str + *pos);
	return (ft_run_atof(str, pos));
}

int	ft_parse_unsigned_char(char *str, size_t *pos, unsigned char *val, char *m)
{
	int	value_to_convert;

	ft_run_is_space(str, pos);
	if (ft_is_valid_double(str + *pos))
	{
		write(1, m, ft_strlen(m));
		return (-1);
	}
	value_to_convert = ft_atoi(str + *pos);
	if(value_to_convert < 0)
		value_to_convert = 255 - value_to_convert;
	*val = (unsigned char) value_to_convert;
	return (ft_run_atoi(str, pos));
}

int	ft_parse_comma(char *str, size_t *pos)
{
	ft_run_is_space(str, pos);
	if ((str[*pos] != ','))
		return (-1);
	pos[0]++;
	return (0);
}

int	ft_parse_colour(char *str, size_t *pos, t_colour *colour, char *msg)
{
	if (ft_parse_unsigned_char(str, pos, &colour->red, msg))
		return (-1);
	if (ft_parse_comma(str, pos))
		return (-1);
	if (ft_parse_unsigned_char(str, pos, &colour->green, msg))
		return (-1);
	if (ft_parse_comma(str, pos))
		return (-1);
	if (ft_parse_unsigned_char(str, pos, &colour->blue, msg))
		return (-1);
	return (0);
}

int	ft_parse_vec3d(char *str, size_t *pos, t_vec3d *vector, char *msg)
{
	int ret = ft_parse_double(str, pos, &vector->x, msg) == -1;
	ret = (1 == ret) || ft_parse_comma(str, pos) == -1;
	ret = (1 == ret) || ft_parse_double(str, pos, &vector->y, msg) == -1;
	ret = (1 == ret) || ft_parse_comma(str, pos) == -1;
	ret = (1 == ret) || ft_parse_double(str, pos, &vector->z, msg) == -1;
	if (ret)
		return (-1);
	// if (ft_parse_double(str, pos, &vector->x))
	// 	return (-1);
	// if (ft_parse_comma(str, pos))
	// 	return (-1);
	// if (ft_parse_double(str, pos, &vector->y))
	// 	return (-1);
	// if (ft_parse_comma(str, pos))
	// 	return (-1);
	// if (ft_parse_double(str, pos, &vector->z))
	// 	return (-1);
	return (0);
}
