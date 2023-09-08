/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_v3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:04:25 by alvjimen          #+#    #+#             */
/*   Updated: 2023/09/08 17:12:07 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	ft_common_cylinder_cone(char *str, size_t *pos, t_vec3d *coords,
		t_vec3d *normalized_orientation_vector)
{
	if (ft_parse_vec3d(str, pos, coords))
		return (-1);
	if (ft_parse_vec3d(str, pos, normalized_orientation_vector))
		return (-1);
	return (0);
}
