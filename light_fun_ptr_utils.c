/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_fun_ptr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:41:46 by alvjimen          #+#    #+#             */
/*   Updated: 2023/09/14 12:18:36 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	ft_color_specular_diffuse_light(t_hit_record *rec, t_ray *ray,
		t_data *img)
{
	return (ft_vec3d_plus_vec3d(ft_color_specular_light(rec, ray, img),
			ft_color_diffuse_light(rec, ray, img)));
}

t_vec3d	ft_color_diffuse_specular_ambiance_light(t_hit_record *rec, t_ray *ray,
		t_data *img)
{
	return (ft_vec3d_plus_vec3d(
					ft_color_specular_diffuse_light(rec, ray, img),
					ft_color_ambient_light(rec, ray, img)));
}
