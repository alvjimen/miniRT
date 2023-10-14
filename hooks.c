/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:56:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 13:29:16 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_double_normalize(double *nbr)
{
	while (*nbr < 0 || *nbr > 1)
	{
		if (*nbr < 0)
			*nbr += 1;
		else if (*nbr > 1)
			*nbr -= 1;
	}
}

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
	else if (keycode == LEFT_ARROW)
	{
		if (img->element)
			img->element->displacement_u -= img->modifier;
	}
	else if (keycode == RIGHT_ARROW)
	{
		if (img->element)
			img->element->displacement_u += img->modifier;
	}
	else if (keycode == UP_ARROW)
	{
		if (img->element)
			img->element->displacement_v -= img->modifier;
	}
	else if (keycode == DOWN_ARROW)
	{
		if (img->element)
			img->element->displacement_v += img->modifier;
	}
	/* Draw a picture of what u see on the window */
	else if (keycode == F2)
		ft_prt_ppm_file_from_img(&img->display, img->display.width,
			img->display.height, 2);
	/* Redraw on the window */
	else if (keycode == F1)
	{
		img->camera = ft_init_camera(img->camera.lookfrom, ASPECT_RATIO,
				img->camera.fov, img->camera.lookat);
		img->ft_draw(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->display.img, 0, 0);
	}
	/* Printing debugin info*/
	else if (keycode == P)
	{
		printf("%d\n", img->textured);
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
			ft_print_vector("orientation vector",
				img->element->orientation_vector);
			printf("diameter: %f\nheight: %f\n",
				img->element->diameter, img->element->height);
			printf("reflection_index: %f\n", img->element->reflection_index);
		}
		ft_print_vector("vector", img->vector);
		printf("angle in radians: %f\nangle in degree: %f\n\n",
			img->angle, ft_radians_to_degree(img->angle));
	}
	/* Modify lookfrom */
	else if (keycode == C)
		img->camera.lookfrom = ft_vec3d_plus_vec3d(img->camera.lookfrom,
				img->vector);
	/* Modify lookat */
	else if (keycode == L)
		img->camera.lookat = img->vector;
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
	{
		if (img->rotated && img->element)
		{
			if (!img->axis)
				img->element->orientation_vector = ft_rotate_x(
						img->element->orientation_vector, img->angle);
			else
				img->element->orientation_vector = ft_rotate_x(
						img->element->coords, img->angle);
			img->rotated = 0;
			return (0);
		}
		img->vector.x += img->modifier;
	}
	else if (keycode == Y)
	{
		if (img->rotated && img->element)
		{
			if (!img->axis)
				img->element->orientation_vector = ft_rotate_y(
						img->element->orientation_vector, img->angle);
			else
				img->element->orientation_vector = ft_rotate_y(
						img->element->coords, img->angle);
			img->rotated = 0;
			return (0);
		}
		img->vector.y += img->modifier;
	}
	else if (keycode == Z)
	{
		if (img->rotated && img->element)
		{
			if (!img->axis)
				img->element->orientation_vector = ft_rotate_z(
						img->element->orientation_vector, img->angle);
			else
				img->element->orientation_vector = ft_rotate_z(
						img->element->coords, img->angle);
			img->rotated = 0;
			return (0);
		}
		img->vector.z += img->modifier;
	}
	/* Rotate modify the vector */
	else if (keycode == R)
		img->rotated = 1;
	/* move the point of reference */
	else if (keycode == T)
	{
		if (img->element)
		{
			img->element->coords = img->vector;
		}
	}
	/* color change */
	else if (keycode == A)
	{
		img->value_color ^= AMBIANCE;
		ft_img_color(img);
	}
	else if (keycode == D)
	{
		img->value_color ^= DIFFUSE;
		ft_img_color(img);
	}
	else if (keycode == S)
	{
		img->value_color ^= SPECULAR;
		ft_img_color(img);
	}
	else if (keycode == F3)
	{
		printf("%s -> %s\n", "Esc", "End of the program");
		printf("%s -> %s\n", "F1", "Redraw (Update changes)");
		printf("%s -> %s\n", "F2", "Save the picture");
		printf("%s -> %s\n", "F3", "Help menu");
		printf("%s -> %s\n", "SHIFT", "change texture");
		printf("%s -> %s\n", "1", "Antialiasing");
		printf("%s -> %s\n", "2", "-modifier");
		printf("%s -> %s\n", "3", "2modifier");
		printf("%s -> %s\n", "4", "modifier/2");
		printf("%s -> %s\n", "5", "angle+=ft_degree_to_radians(modifier)");
		printf("%s -> %s\n", "P", "Printing debug info");
		printf("%s -> %s\n", "V", "set vector to {0, 0, 0}");
		printf("%s -> %s\n", "X", "img->vector->x += modifier");
		printf("%s -> %s\n", "Y", "img->vector->y += modifier");
		printf("%s -> %s\n", "Z", "img->vector->z += modifier");
		printf("%s -> %s\n", "C", "Change camera.origin += img->vector");
		printf("%s -> %s\n", "L", "Change camera.lookat += img->vector");
		printf("%s -> %s\n", "W", "Change diameter += modifier");
		printf("%s -> %s\n", "H", "Change height += modifier");
		printf("%s -> %s\n", "R", "Next type X|Y|Z will be the rotation axis");
		printf("%s -> %s\n", "G", "Toggle axis for rotate");
		printf("%s -> %s\n", "T", "Change element->coords = img->vector");
		printf("%s -> %s\n", "A", "Toggle ambient light");
		printf("%s -> %s\n", "D", "Toggle diffuse light");
		printf("%s -> %s\n", "S", "Toggle specular light");
		printf("%s -> %s\n", "Arrows", "Move the texture");
		printf("%s -> %s\n", "M", "Reflection index");
	}
	else if (keycode == M)
	{
		if (img->element)
		{
			img->element->reflection_index = clamp(img->modifier
				+ img->element->reflection_index, 0, 1);
		}
	}
	/* adding texture */
	else if (keycode == SHIFT)
	{
		img->textured = (img->textured + 1) % (NORMAL_IMG + 1);
		ft_texture(img);
	}
	else if (keycode == J)
	{
		if (img->element)
		{
			if (!img->textured)
				img->element->textured = 0;
			else
				img->element->textured = 1;
			img->element->ft_texture = img->ft_texture;
		}
	}
	else if (keycode == G)
		img->axis ^= 1;
	else if (keycode == V)
		img->vector = ft_init_vec3d(0, 0, 0);
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
		img->element = ft_hittable_element(&ray, img, &rec);
		ft_print_vector("point", rec.p);
		printf("rec->u: %f\trec->v: %f\n", rec.u, rec.v);
		ft_print_vector("normal", rec.normal);
		ft_print_vector("color", ft_ray_color(&ray, img, 3));
	}
	return (0);
}
