/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:06:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 11:01:18 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	coordx_center(int x)
{
	return (x + (WIN_W / 2));
}

int	coordx_uncenter(int x)
{
	return (x - (WIN_W / 2));
}

int	coordy_center(int y)
{
	return (y + (WIN_H / 2));
}

int	coordy_uncenter(int y)
{
	return (y - (WIN_W / 2));
}