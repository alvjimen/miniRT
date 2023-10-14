/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_coordinates_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:27:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 19:25:12 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_error_read_image_file(char *path)
{
	ft_putstr_fd("Error reading ", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(" file.\n", 1);
	return (-1);
}

int	ft_error_getting_image_address(char *path)
{
	ft_putstr_fd("Error getting ", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(" imagen address.\n", 1);
	return (-1);
}

static int	ft_load_img_aux(t_data *img, t_mlx_img *target, char *path)
{
	if (!target->img)
	{
		target->img = mlx_xpm_file_to_image(img->mlx, path,
				&target->width, &target->height);
		if (!target->img)
			return (ft_error_read_image_file(path));
		target->address = mlx_get_data_addr(target->img,
				&target->bits_per_pixel, &target->line_length,
				&target->endian);
		if (!target->address)
			return (ft_error_getting_image_address(path));
		target->endian = img->display.endian;
		return (0);
	}
	return (0);
}

int	ft_load_img(t_data *img)
{
	if (ft_load_img_aux(img, &img->img, XPM_PATH))
		return (-1);
	if (ft_load_img_aux(img, &img->bump, XPM_BUMP_PATH))
		return (-1);
	if (ft_load_img_aux(img, &img->normal, XPM_NORMAL_PATH))
		return (-1);
	return (0);
}

void	ft_checker_texture_image(t_hit_record *rec, t_element *element,
		t_data *img)
{
	int		i;
	int		j;
	char	*pixel;

	if (!element && !rec)
		return ;
	rec->u = clamp(rec->u, 0.0, 1.0) + element->displacement_u;
	rec->v = clamp(rec->v, 0.0, 1.0) + element->displacement_v;
	ft_double_normalize(&rec->u);
	ft_double_normalize(&rec->v);
	i = rec->u * img->img.width;
	j = rec->v * img->img.height;
	if (i >= img->img.width)
		i = img->bump.width - 1;
	if (j >= img->img.height)
		j = img->img.height - 1;
	pixel = &img->img.address[j * img->img.line_length + i
		* (img->img.bits_per_pixel / 8)];
	rec->colour.alpha = pixel[3];
	rec->colour.red = pixel[2];
	rec->colour.green = pixel[1];
	rec->colour.blue = pixel[0];
}
