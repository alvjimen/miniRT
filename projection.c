/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:14:44 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/24 16:25:29 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	*ft_get_matrix_projection(double fovangle)
{
	t_m4x4	*project;
	double	f;
	double	a;

	project = ft_calloc(1, sizeof(t_m4x4));
	if (!project)
		return (NULL);
	f = 1 / tan(fovangle / 2);
	a = aspect_ratio_h();
	project->r[0].x = f * a;
	project->r[1].y = f;
	project->r[2].z = FAR / (FAR - NEAR);
	project->r[2].w = 1;
	project->r[3].z = (-FAR * NEAR) / (FAR - NEAR);
	project->r[3].w = 0;
	return (project);
}
