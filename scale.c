/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:48:21 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 16:59:17 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scale(t_triangle *triangle)
{
	triangle->p[0].x += 1.0f;
	triangle->p[0].x *= 0.5f * WIN_W;
	triangle->p[0].y += 1.0f;
	triangle->p[0].y *= 0.5f * WIN_H;
	triangle->p[1].x += 1.0f;
	triangle->p[1].x *= 0.5f * WIN_W;
	triangle->p[1].y += 1.0f;
	triangle->p[1].y *= 0.5f * WIN_H;
	triangle->p[2].x += 1.0f;
	triangle->p[2].x *= 0.5f * WIN_W;
	triangle->p[2].y += 1.0f;
	triangle->p[2].y *= 0.5f * WIN_H;
}
