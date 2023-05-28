/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:49:59 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/28 16:38:28 by alvjimen         ###   ########.fr       */
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
# define ASPECT_RATIO 16.0 / 9.0
# define WIN_W 640.0
# define ANGLE 1.5707963268f /*90º*/
# define NEAR 0.1f
# define FAR 1000.0f
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

typedef enum	e_type
{
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;


typedef struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

typedef	struct	s_camera
{
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	double	t_max;

	t_vec3d	*lower_left_corner;
	t_vec3d	*origin;
}	t_camera;

typedef	struct	s_colour
{
	unsigned char	alpha;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_colour;

typedef struct	s_vec4d
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4d;

typedef struct	s_m4x4
{
	t_vec4d	r[4];
}	t_m4x4;

typedef struct	s_ray
{
	t_vec3d	*origin;
	t_vec3d	*direction;
	t_vec3d	*unit_direction;
}	t_ray;

typedef struct	s_hit_record
{
	t_vec3d	*p;
	t_vec3d	*normal;
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
	double		height;
	double		light_ratio;
	double		hfov;
	int			hittable;
	int			(*ft_hit)(t_ray *, t_camera *, t_hit_record *, struct s_element *);
}	t_element;

typedef	struct	s_data
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
	t_list		*world;
	t_camera	*camera;
	double		aspect_ratio;
}	t_data;

/*Horizontalfield of view in degrees 0-180*/

/*coord.c*/
double			coordx_center(double x);
double			coordx_uncenter(double x);
double			coordy_center(double y);
double			coordy_uncenter(double y);
/*normalize.c*/
double			normalize_coord(double coord, double max_coord, double min_coord);
double			unnormalize_coord(double n_coord, double max_coord, double min_coord);
/*hooks.c*/
int				key_hook(int keycode, t_data *img);
int				hook_close(void);
/*draw.c*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_draw_background(t_data *img);
void			ft_draw_background_v2(t_data *img);
int				ft_color_double_to_int(double c);
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
void			sphere(t_element *element, t_vec3d coord, double diameter, t_colour colour);
/*matrix.c*/
void matrixmultiplication(t_vec4d *origin, t_vec4d *destiny, t_m4x4 *matrix);
/*vec3d.c*/
t_vec3d			*ft_init_vec3d(double x, double y, double z);
void			ft_set_vec3d(t_vec3d *ptr, double x, double y, double z);
double			ft_vec3d_len(t_vec3d *o1);
double			ft_vec3d_squared_len(t_vec3d *o1);
t_vec3d			*ft_vec3d_unit_lenght(t_vec3d *o1);
void			ft_vec3d_negative(t_vec3d *ptr);
/*vec3d_math_vec3d.c*/
t_vec3d			*ft_vec3d_plus_vec3d(t_vec3d *o1, t_vec3d *o2);
t_vec3d			*ft_vec3d_minus_vec3d(t_vec3d *o1, t_vec3d *o2);
t_vec3d			*ft_vec3d_pro_vec3d(t_vec3d *o1, t_vec3d *o2);
double			ft_vec3d_dot(t_vec3d *o1, t_vec3d *o2);
/*vec3d_math_double.c*/
t_vec3d			*ft_vec3d_pro_double(t_vec3d *o1, double o2);
t_vec3d			*ft_vec3d_div_double(t_vec3d *o1, double o2);
void			ft_vec3d_div_double_ptr(t_vec3d *o1, double o2, t_vec3d *dst);
void			ft_vec3d_pro_double_ptr(t_vec3d *o1, double o2, t_vec3d *dst);
/*vector4d.c*/
t_vec4d			*ft_vec4d_init(double x, double y, double z, double w);
/*ray.c*/
t_ray		*ft_init_ray(t_vec3d *origin, t_vec3d *direction);
t_vec3d		*ft_ray_at(t_ray *ray, double t);
int			ft_ray_color(t_ray *ray);
t_vec3d		*ft_ray_direction(t_data *img, int x, int y);
void		ft_destroy_ray(t_ray *ray);
int			ft_ray_color_v2(t_ray *ray, t_data *img);
/*ppm.c*/
void	ft_draw_ppm_header(int	width, int height, int fd);
void	ft_draw_ppm_pixel(int colour, int fd);
int		get_mlx_pixel_colour(t_data *img, int x, int y);
void	ft_prt_ppm_file_from_img(t_data *img, int width, int height, int fd);
/*camera.c*/
void	ft_img(t_data *img, const int image_width, const double aspect_ratio);
t_camera	*ft_init_camera(t_vec3d *origin, const double aspect_ratio);
/*sphere.c*/
double	ft_hit_sphere(t_vec3d *center, double diameter, t_ray *ray);
int		ft_hit_sphere_v2(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *sphere);
/*hit.c*/
void	ft_hit_face(t_ray *ray, t_hit_record *rec);
int	ft_hittable(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_list *world);
/*struct.c*/
void	*ft_alloc_struct(size_t size);
/*world.c*/
void	ft_world(t_data *img);
#endif
