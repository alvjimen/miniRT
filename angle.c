/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:30:04 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 13:23:10 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	ft_degree_to_radians(double degree)
{
	return (degree * (M_PI / 180));
}

double	ft_radians_to_degree(double radians)
{
	return (radians / (M_PI/ 180));
}
