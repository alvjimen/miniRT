/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:49:59 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/05 13:20:15 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H
/*KEYBOARD BINDING*/
# ifdef	__APPLE__
#  define ESC 53
# else
#  define ESC 65307
#  define X 120
#  define Y 121
#  define Z 122
# endif
/*WIN SIZE*/
# define WIN_H 640
# define WIN_W 640
# define ANGLE 1.5707963268f /*90º*/
# define NEAR 0.1f
# define FAR 1000.0f

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "lib/include/libft.h"

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vec3d
{
	float	x;
	float	y;
	float	z;
}	t_vec3d;

typedef struct	s_vec4d
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4d;

typedef struct s_matrix_4d
{
	t_vec4d	matrix[4];
}	t_matrix_4d;

/*coord.c*/
int			coordx_center(int x);
int			coordx_uncenter(int x);
int			coordy_center(int y);
int			coordy_uncenter(int y);
int			key_hook(int keycode);
int			hook_close(void);
/*draw.c*/
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_draw_square(t_data *img, int c, int p, int px, int py);
void		ft_draw_circle(t_data *img, int c, int p, int radius);
/*aspect_ratio.c*/
double		ft_aspect_ratio(void);
/*perspective.c*/
void		rotation_x(double angle, int *y, int *z);
void		rotation_y(double angle, int *x, int *z);
void		rotation_z(double angle, int *x, int *y);
/*angle.c*/
double		ft_degree_to_radians(double degree);
double		ft_radians_to_degree(double radians);
#endif

