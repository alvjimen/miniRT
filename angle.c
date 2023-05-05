/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:30:04 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 11:35:42 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	ft_degree_to_radians(double degree)
{
	return (degree * (180 / M_PI));
}

double	ft_radians_to_degree(double radians)
{
	return (radians / (180 / M_PI));
}
