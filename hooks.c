/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:56:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/25 18:18:52 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

int	key_hook(int keycode, t_data *img)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == S)
		ft_prt_ppm_file_from_img(img, img->image_width, img->image_height, 2);
	else
		printf("Keycode: %d\n", keycode);
	return (0);
}

int	hook_close(void)
{
	/*printf("Closing the window\n");*/
	exit(0);
}
