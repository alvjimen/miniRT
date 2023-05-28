/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:58:29 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/24 19:10:24 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	normalize_coord(double coord, double min_coord, double max_coord)
{
	return (2 * ((coord - min_coord) / (max_coord - min_coord) - 0.5));
}
/*this return a number between -1 and 1 if is not for -0.5 it was between 0
  and 2*/

double	unnormalize_coord(double n_coord, double min_coord, double max_coord)
{
	return ((n_coord / 2 + 0.5) * (max_coord - min_coord) + min_coord);
}