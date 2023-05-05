/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:49:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 14:43:42 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	normalize_x(int px)
{
	/*projection formula (h/w)fx, fy, z*/
	/*f 1 /tan(angle/2)*/
	double x = 1 / tan(ANGLE/2);
}
/*aspect ratio z*/

/*zfar / (zfar - znear)*/
/*q = zfar/(zfar-znear)*/
/*afx/z, fy/z, z * q - Znear * q */
void	projection_matrix(t_matrix_4d *matProj)
{
	float	ffovrad;

	/*angle is in radians*/
	/* 1 / tan(angle / 2)*/
	ffovrad = 1.0f / tan(ANGLE * 0.5f);/*f is the same*/
	ft_bzero(&matProj, sizeof(matProj));
	matProj.m[0].x = ft_aspect_ratio() * ffovrad;
	matProj.m[1].y = ffovrad;
	matProj.m[2].z = FAR / (FAR - NEAR);
	matProj.m[3].z = (-FAR * NEAR)/ (FAR - NEAR);
	matProj.m[2].w = 1.0f;
}
	/*	This is equal to this matrix
		[af, 0, 0,							  0]
		[ 0, f, 0,							  0]
		[ 0, 0, far/(far - near),			  1]
		[ 0, 0, (-farr * near)/ (FAR - NEAR), 0]
	*/
