/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:55:28 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/24 19:09:35 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Znear = 1 /tan(tetha / 2); tetha is equal fov angle*/
/* Viewing frusbum
	Yp Yproyected Y
	Yp / znear = Y / Z >> Yp = Y * znear / Z
	Yp = Y / tan(tetha /2) * Z
	Xp Xproyected X
	Xp / znear = x / z;
	>> XP = X / tan(tetha /2) * Z
	*/
