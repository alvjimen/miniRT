/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_coordinates_utils_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:46:14 by dmacicio          #+#    #+#             */
/*   Updated: 2023/10/14 18:47:07 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_checker_normal_image(t_hit_record *rec, t_element *sphere,
		t_data *img)
{
	ft_checker_normal(rec, sphere, img);
	ft_checker_texture_image(rec, sphere, img);
}

void	ft_checker_bump_image(t_hit_record *rec, t_element *sphere,
		t_data *img)
{
	ft_checker_bump(rec, sphere, img);
	ft_checker_texture_image(rec, sphere, img);
}
