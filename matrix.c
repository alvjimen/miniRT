/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:54:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/24 19:09:20 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	matrixmultiplication(t_vec4d *origin, t_vec4d *destiny, t_m4x4 *matrix)
{
	double	w;

	destiny->x = (origin->x * matrix->r[0].x) + (origin->y * matrix->r[1].x)
		+ (origin->z * matrix->r[2].x) + (origin->w * matrix->r[3].x);
	destiny->y = (origin->x * matrix->r[0].y) + (origin->y * matrix->r[1].y)
		+ (origin->z * matrix->r[2].y) + (origin->w * matrix->r[3].y);
	destiny->z = (origin->x * matrix->r[0].z) + (origin->y * matrix->r[1].z)
		+ (origin->z * matrix->r[2].z) + (origin->w * matrix->r[3].z);
	w = (origin->x * matrix->r[0].w) + (origin->y * matrix->r[1].w)
		+ (origin->z * matrix->r[2].w) + (origin->w * matrix->r[3].w);
	if (w != 0.0f)
	{
		destiny->x /= w;
		destiny->y /= w;
		destiny->z /= w;
	}
}
