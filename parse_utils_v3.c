/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_v3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:04:25 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 12:39:12 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_common_cylinder_cone(char *str, size_t *pos, t_cone_cylinder	*cy_co,
	char *coordmsg, char *norm_orient_vect_msg)
{	
	if (ft_parse_vec3d(str, pos, &cy_co->coords, coordmsg))
		return (-1);
	if (ft_parse_vec3d(str, pos, &cy_co->normalized_orientation_vector, norm_orient_vect_msg))
		return (-1);
	return (0);
}
