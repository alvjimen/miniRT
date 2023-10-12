/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_fun_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:42:31 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/09 18:32:21 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_vec3d	ft_color_ambient_light(t_hit_record *rec, t_ray *ray, t_data *img)
{
	return (ft_ambient_light(rec, ray, img));
}

t_vec3d	ft_color_diffuse_light(t_hit_record *rec, t_ray *ray, t_data *img)
{
	return (ft_calculate_lights(rec, ray, img, ft_diffuse_light));
}

t_vec3d	ft_color_specular_light(t_hit_record *rec, t_ray *ray, t_data *img)
{
	return (ft_calculate_lights(rec, ray, img, ft_specular_light));
}

t_vec3d	ft_color_ambient_diffuse_light(t_hit_record *rec, t_ray *ray,
		t_data *img)
{
	return (ft_vec3d_plus_vec3d(ft_color_diffuse_light(rec, ray, img),
			ft_color_ambient_light(rec, ray, img)));
}

t_vec3d	ft_color_specular_ambient_light(t_hit_record *rec, t_ray *ray,
		t_data *img)
{
	return (ft_vec3d_plus_vec3d(ft_color_specular_light(rec, ray, img),
			ft_color_ambient_light(rec, ray, img)));
}
