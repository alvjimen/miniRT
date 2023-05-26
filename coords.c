/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:06:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/26 13:56:54 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	coordx_center(double x)
{
	return (x + (WIN_W / 2));
}

double	coordx_uncenter(double x)
{
	return (x - (WIN_W / ASPECT_RATIO / 2));
}

double	coordy_center(double y)
{
	return (y + (WIN_W / ASPECT_RATIO / 2));
}

double	coordy_uncenter(double y)
{
	return (y - (WIN_W / 2));
}
