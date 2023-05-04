/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:06:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/04 19:57:27 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/*>> 1 is equal to / 2*/
int	coordx_center(int x)
{
	return (x + (WIN_W >> 1));
}

int	coordx_uncenter(int x)
{
	return (x - (WIN_W >> 1));
}

int	coordy_center(int y)
{
	return (y + (WIN_H >> 1));
}

int	coordy_uncenter(int y)
{
	return (y - (WIN_W >> 1));
}
