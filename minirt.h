/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:49:59 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/05 20:26:16 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H
/*KEYBOARD BINDING*/
# ifdef	__APPLE__
#  define ESC 53
#  define S 1
# else
#  define ESC 65307
#  define S 115
# endif
/*WIN SIZE*/
# define ASPECT_RATIO 1.7777777777777777 // 16.0 / 9.0
# define WIN_W 640.0
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef enum e_type
{
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

typedef struct s_camera
{
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	double	t_min;
	double	t_max;
	double	theta;
	double	h;
	t_vec3d	lower_left_corner;
	t_vec3d	origin;
	t_vec3d	horizontal;
	t_vec3d	vertical;
}	t_camera;

typedef struct s_colour
{
	unsigned char	alpha;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_colour;

typedef struct s_vec4d
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4d;

typedef struct s_m4x4
{
	t_vec4d	r[4];
}	t_m4x4;

typedef struct s_ray
{
	t_vec3d	origin;
	t_vec3d	direction;
	t_vec3d	unit_direction;
}	t_ray;

typedef struct s_hit_record
{
	t_vec3d	p;
	t_vec3d	normal;
	double	t;
	int		front_face;
}	t_hit_record;

typedef struct s_element
{
	t_type		type;
	t_vec3d		coords;
	t_vec3d		orientation_vector;
	t_colour	colour;
	double		diameter;
	double		radius;
	double		height;
	double		light_ratio;
	double		hfov;
	int			hittable;
	int			(*ft_hit)(t_ray *, t_camera *, t_hit_record *,
			struct s_element *);
}	t_element;
/*Horizontalfield of view in degrees 0-180*/

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			image_width;
	int			image_height;
	int			samplex_per_pixel;
	t_list		*world;
	t_camera	*camera;
	double		aspect_ratio;
	double		max_depth;
}	t_data;

/*coord.c*/
double			coordx_center(double x);
double			coordx_uncenter(double x);
double			coordy_center(double y);
double			coordy_uncenter(double y);
/*normalize.c*/
double			normalize_coord(double coord, double max_coord,
					double min_coord);
double			unnormalize_coord(double n_coord, double max_coord,
					double min_coord);
/*hooks.c*/
int				key_hook(int keycode, t_data *img);
int				hook_close(void);
/*draw.c*/
void			ft_draw_background(t_data *img);
void			ft_draw_background_v2(t_data *img);
int				ft_color_double_to_int(double c);
int				ft_color_vector_to_int(t_vec3d v);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
/*aspect_ratio.c*/
double			aspect_ratio_h(void);
double			aspect_ratio_w(void);
/*rotations.c*/
void			rotation_x(double angle, t_vec4d *v);
void			rotation_y(double angle, t_vec4d *v);
void			rotation_z(double angle, t_vec4d *v);
void			ft_rotate_elements(t_list *lst, void (f)(double, t_vec4d *));
/*angle.c*/
double			ft_degree_to_radians(double degree);
double			ft_radians_to_degree(double radians);
/*projection.c*/
void			*ft_get_matrix_projection(double fovangle);
/*element.c*/
/*init_figures.c*/
void			sphere(t_element *element, t_vec3d coord, double diameter,
					t_colour colour);
/*matrix.c*/
void			matrixmultiplication(t_vec4d *origin, t_vec4d *destiny,
					t_m4x4 *matrix);
/*vec3d.c*/
t_vec3d			ft_init_vec3d(double x, double y, double z);
void			ft_set_vec3d(t_vec3d *ptr, double x, double y, double z);
double			ft_vec3d_len(t_vec3d o1);
double			ft_vec3d_squared_len(t_vec3d o1);
t_vec3d			ft_vec3d_unit_lenght(t_vec3d o1);
t_vec3d			ft_vec3d_negative(t_vec3d ptr);
/*vec3d_math_vec3d.c*/
t_vec3d			ft_vec3d_plus_vec3d(t_vec3d o1, t_vec3d o2);
t_vec3d			ft_vec3d_minus_vec3d(t_vec3d o1, t_vec3d o2);
t_vec3d			ft_vec3d_pro_vec3d(t_vec3d o1, t_vec3d o2);
double			ft_vec3d_dot(t_vec3d o1, t_vec3d o2);
t_vec3d			ft_vec3d_cross(t_vec3d o1, t_vec3d o2);
/*vec3d_math_double.c*/
t_vec3d			ft_vec3d_pro_double(t_vec3d o1, double o2);
t_vec3d			ft_vec3d_div_double(t_vec3d o1, double o2);
/*vector4d.c*/
t_vec4d			*ft_vec4d_init(double x, double y, double z, double w);
/*ray.c*/
t_ray			ft_init_ray(t_vec3d origin, t_vec3d direction);
t_vec3d			ft_ray_at(t_ray *ray, double t);
int				ft_ray_color(t_ray *ray);
t_vec3d			ft_ray_direction(t_data *img, int x, int y);
int				ft_ray_color_v2(t_ray *ray, t_data *img);
/*ppm.c*/
void			ft_draw_ppm_header(int width, int height, int fd);
void			ft_draw_ppm_pixel(int colour, int fd);
int				get_mlx_pixel_colour(t_data *img, int x, int y);
void			ft_prt_ppm_file_from_img(t_data *img, int width, int height,
					int fd);
/*camera.c*/
void			ft_img(t_data *img, const int image_width,
					const double aspect_ratio);
t_camera	*ft_init_camera(t_vec3d lookfrom, const double aspect_ratio,
		const double fov, t_vec3d lookat, t_vec3d vup);
/*sphere.c*/
double			ft_hit_sphere(t_vec3d *center, double diameter, t_ray *ray);
int				ft_hit_sphere_v2(t_ray *ray, t_camera *camera,
					t_hit_record *rec, t_element *sphere);
/*hit.c*/
void			ft_hit_face(t_ray *ray, t_hit_record *rec);
int				ft_hittable(t_ray *ray, t_camera *camera, t_hit_record *rec,
					t_list *world);
/*struct.c*/
void			*ft_alloc_struct(size_t size);
/*world.c*/
void			ft_world(t_data *img);
/*ft_avoid_leaks_vec3d*/
t_vec3d			ft_avoid_leaks_vec3d(t_vec3d	*ptr);
/*random_number.c*/
unsigned int	uint_random_nbr(void);
double			pseudo_random(void);
double			random_double(double min, double max);
/*antialiasing.c*/
void			ft_draw_background_v3(t_data *img);
int				ft_antialiasing(t_data *img, int x, int y);
t_vec3d			ft_ray_color_v3(t_ray *ray, t_data *img);
t_vec3d			ft_ray_direction_v2(t_data *img, int x, int y);
/*color.c*/
int				ft_write_color(t_vec3d vector, int samplex_per_pixel);
int				ft_color_vector_to_int_v2(t_vec3d v);
int				ft_color_double_to_int_v2(double c);
/*number.c*/
double			clamp(double x, double min, double max);
/*diffuse_materials.c*/
void			ft_draw_background_v4(t_data *img);
t_vec3d			ft_vec3d_random(double min, double max);
t_vec3d			random_in_unit_sphere(void);
t_vec3d			ft_ray_color_v4(t_ray ray, t_data *img, int depth);
int				ft_antialiasing_v2(t_data *img, int x, int y);
void			ft_draw_background_v4(t_data *img);
#endif
