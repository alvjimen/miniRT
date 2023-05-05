/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:49:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 13:01:53 by alvjimen         ###   ########.fr       */
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
