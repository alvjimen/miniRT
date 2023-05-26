/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aspect_ratio.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:30:52 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/26 13:57:11 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

double	aspect_ratio_h(void)
{
	return ((double)WIN_W / ASPECT_RATIO / WIN_W);
}

double	aspect_ratio_w(void)
{
	return ((double)WIN_W / WIN_W / ASPECT_RATIO);
}
