/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:56:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/27 17:18:41 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	ft_print_vector(const char *str, t_vec3d vector)
{
	printf("%s: x: %f, y: %f, z: %f\n",
		str, vector.x, vector.y, vector.z);
}

void	debug(void)
{
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == ESC)
		exit(0);
	/* Draw a picture of what u see on the window */
	if (keycode == F2)
		ft_prt_ppm_file_from_img(img, img->image_width, img->image_height, 2);
	/* Redraw on the window */
	else if (keycode == F1)
	{
		img->camera = ft_init_camera(img->camera.lookfrom, ASPECT_RATIO,
				img->camera.fov, img->camera.lookat);
		img->ft_draw(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	/* Printing debugin info*/
	else if (keycode == P)
	{
		ft_print_vector("lookfrom", img->camera.lookfrom);
		ft_print_vector("lookat", img->camera.lookat);
		printf("modifier value: %f\n", img->modifier);
		if (img->element)
		{
			printf("element selected: ");
			if (img->element->type == SPHERE)
				printf("SPHERE\n");
			else if (img->element->type == PLANE)
				printf("PLANE\n");
			else if (img->element->type == CYLINDER)
				printf("CYLINDER\n");
			else if (img->element->type == CONE)
				printf("CONE\n");
			ft_print_vector("point", img->element->coords);
			ft_print_vector("orientation vector", img->element->orientation_vector);
			printf("diameter: %f\nheight: %f\n",
					img->element->diameter, img->element->height);
		}
		ft_print_vector("vector", img->vector);
		printf("angle in radians: %f\nangle in degree: %f\n",
				img->angle, ft_radians_to_degree(img->angle));
	}
	/* Modify lookfrom */
	else if (keycode == C)
		img->camera.lookfrom= ft_vec3d_plus_vec3d(img->camera.lookfrom, img->vector);
	/* Modify lookat */
	else if (keycode == L)
		img->camera.lookat = ft_vec3d_plus_vec3d(img->camera.lookat, img->vector);
	/*change the pointer to f from antialiasing
	 * to not antialiasing and reverse */
	else if (keycode == N1)
	{
		if (img->ft_draw == ft_draw_without_antialiasing)
			img->ft_draw = ft_draw_antialiasing;
		else
			img->ft_draw = ft_draw_without_antialiasing;
	}
	/* modify the modifier */
	else if (keycode == N2)
		img->modifier = -img->modifier;
	else if (keycode == N3)
		img->modifier *= 2;
	else if (keycode == N4)
		img->modifier /= 2;
	else if (keycode == N5)
		img->angle += ft_degree_to_radians(img->modifier);
	/* modify primitives */
	else if (keycode == W)
	{
		if (img->element)
		{
			img->element->diameter += img->modifier;
			img->element->radius = img->element->diameter / 2;
		}
	}
	else if (keycode == H)
	{
		if (img->element)
		{
			img->element->height += img->modifier;
		}
	}
	/* modify vector */
	else if (keycode == X)
		img->vector.x += img->modifier;
	else if (keycode == Y)
		img->vector.y += img->modifier;
	else if (keycode == Z)
		img->vector.z += img->modifier;
	/* Rotate modify the vector */
	else if (keycode == R)
	{
		if (img->element)
		{
			img->element->orientation_vector =
				ft_rotate_x(img->element->orientation_vector, img->angle);
		}
	}
	/* move the point of reference */
	else if (keycode == T)
	{
		if (img->element)
		{
			img->element->coords = img->vector;
		}
	}
	else
		printf("Keycode: %d\n", keycode);
	return (0);
}

int	hook_close(void)
{
	exit(0);
}

int	hook_mouse(int button, int x, int y, void *param)
{
	t_data			*img;
	t_vec3d			vector;
	t_ray			ray;
	t_hit_record	rec;

	img = param;
	img->mouse.x = x;
	img->mouse.y = y;
	if (button == L_CLICK)
	{
		vector = ft_ray_direction(img, x, y, 0);
		ray = ft_init_ray(img->camera.origin, vector);
		debug();
		img->element = ft_hittable_element(&ray, &img->camera,
				&rec, img->world);
		ft_print_vector("color", ft_ray_color(&ray, img));
	}
	return (0);
}
