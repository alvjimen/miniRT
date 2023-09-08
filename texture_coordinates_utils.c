/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_coordinates_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:27:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/09/08 16:31:10 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_load_img(t_data *img)
{
	if (!img->xpm)
	{
		img->xpm = mlx_xpm_file_to_image(img->mlx, XPM_PATH,
				&img->xpm_width, &img->xpm_height);
		if (!img->xpm)
			exit (1);
		img->xpm_address = mlx_get_data_addr(img->xpm,
				&img->xpm_bits_per_pixel, &img->xpm_line_length,
				&img->xpm_endian);
		if (!img->xpm_address)
			exit (1);
	}
	if (!img->xpm_bump)
	{
		img->xpm_bump = mlx_xpm_file_to_image(img->mlx, XPM_BUMP_PATH,
				&img->xpm_bump_width, &img->xpm_bump_height);
		if (!img->xpm_bump)
			exit (1);
		img->xpm_bump_address = mlx_get_data_addr(img->xpm_bump,
				&img->xpm_bump_bits_per_pixel, &img->xpm_bump_line_length,
				&img->xpm_bump_endian);
		if (!img->xpm_bump_address)
			exit (1);
	}
}

void	ft_checker_texture_image(t_hit_record *rec, t_element *sphere,
		t_data *img)
{
	int		i;
	int		j;
	char	*pixel;

	if (!sphere && !rec)
		return ;
	ft_load_img(img);
	rec->u = clamp(rec->u, 0.0, 1.0);
	rec->v = clamp(rec->v, 0.0, 1.0);
	i = rec->u * img->xpm_width;
	j = rec->v * img->xpm_height;
	if (i >= img->xpm_width)
		i = img->xpm_width - 1;
	if (j >= img->xpm_height)
		j = img->xpm_height - 1;
	pixel = &img->xpm_address[j * img->xpm_line_length + i
		* (img->xpm_bits_per_pixel / 8)];
	rec->colour.alpha = pixel[3];
	rec->colour.red = pixel[2];
	rec->colour.green = pixel[1];
	rec->colour.blue = pixel[0];
}
