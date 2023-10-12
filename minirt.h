/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:49:59 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 11:58:37 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H
/*KEYBOARD BINDING*/
# ifdef	__APPLE__
#  define ESC 53
/* Modified lookfrom */
#  define C 8
#  define Q 12
#  define W 13
#  define E 14
/* Modified lookat */
#  define A 0
#  define S 1
#  define D 2
/* change ft_draw */
#  define N1 18
/* modify var to other step*/
#  define N2 19
#  define N3 20
#  define N4 21
#  define N5 22
/* Modify elements */
#  define L 37
#  define H 4
#  define R 15
#  define T 17
/* Set the var of vector */
#  define X 7
#  define Y 16
#  define Z 6

/* Printing info */
#  define P 35
/* REDRAW */
#  define F1 122
/* Make a picture */
#  define F2 120
#  define F3 99
/* undefined */
/* Put or quit shadow/light effects */
#  define U 32
#  define I 34
#  define O 31
#  define J 38
#  define K 40
#  define L_CLICK 1
#  define SHIFT 257
#  define G 103
#  define V 118
#  define LEFT_ARROW 123
#  define RIGHT_ARROW  124
#  define UP_ARROW 126
#  define DOWN_ARROW 125
#  define M 46
# else
#  define ESC 65307
/* REDRAW */
#  define F1 65470
#  define F2 65471
#  define F3 65472
/* Camera Origin */
#  define Q 113
#  define W 119
#  define E 101
/* Camera Lookat */
#  define C 99
#  define A 97
#  define S 115
#  define D 100
/* Elements mod */
#  define L 108
#  define H 104
/* Print values camera */
#  define P 112
/* Set the var of vector */
#  define X 120
#  define Y 121
#  define Z 122
/* Rotation */
#  define R 114
/* Translation */
#  define T 116
/* switch antialiasing */
#  define N1 49
/* Switch sign of var */
#  define N2 50
/* value * 2 */
#  define N3 51
/* value / 2 */
#  define N4 52
/* modify the angle */
#  define N5 53
/* Select element to modify later */
#  define L_CLICK 1
/* Undefined */
#  define J 106
#  define I 105
#  define K 107
#  define O 111
#  define U 117
#  define SHIFT 65505
#  define G 103
#  define V 118
#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363
#  define UP_ARROW 65362
#  define DOWN_ARROW 65364
#  define M 109

# endif
/*WIN SIZE*/
# define ASPECT_RATIO 1.7777777777777777 // 16.0 / 9.0
# define WIN_W 640.0
# define NEAR_ZERO 1e-8;
# define XPM_BUMP_PATH	  "./xpm/earthmap_bumpmap.xpm"
# define XPM_NORMAL_PATH	"./xpm/earthmap_normal.xpm"
# define XPM_PATH	"./xpm/earthmap.xpm"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define AMBIANCE 1
# define DIFFUSE 2
# define SPECULAR 4
# define CHECKER 1
# define IMG 2
# define BUMP 3
# define NORMAL 4
# define BUMP_IMG 5
# define NORMAL_IMG 6
# define TMAX INFINITY

typedef enum e_type
{
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}	t_type;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

typedef struct s_camera
{
	t_vec3d	lookat;
	t_vec3d	lookfrom;
	double	aspect_ratio;
	double	fov;
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

typedef struct s_m3x3
{
	t_vec3d	r[3];
}	t_m3x3;

/* w = 0 if vector w = 1 if point */
typedef struct s_ray
{
	t_vec3d	origin;
	t_vec3d	direction;
	t_vec3d	unit_direction;
}	t_ray;

typedef struct s_element	t_element;

typedef struct s_hit_record
{
	t_vec3d		p;
	t_vec3d		normal;
	double		t;
	double		u;
	double		v;
	int			front_face;
	t_colour	colour;
	double		attenuation;
	double		brightess_light;
	t_vec3d		h;
	double		q;
	double		reflection_index;
  t_colour	mirror_color;
}	t_hit_record;

typedef struct s_data	t_data;

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
	int				hittable;
	int				(*ft_hit)(t_ray *, t_camera *, t_hit_record *,
								struct s_element *);
	void			(*ft_texture)(t_hit_record *, struct s_element *,
			t_data *);
	int				textured; // init 0
	double		displacement_u; // init 0
	double		displacement_v; // init 0
	double		reflection_index; // init 0
	double		coefficient_diffuse; // init 1
	double		coefficient_ambient; // init 1
	double		coefficient_specular; // init 1
}	t_element;
/*Horizontalfield of view in degrees 0-180*/

typedef struct s_mouse
{
	int	x;
	int	y;
}	t_mouse;

typedef struct s_mlx_img {
	void	*img;
	char	*address;
	int	width;
	int	height;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}       t_mlx_img;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	t_mlx_img	display;
	int				samplex_per_pixel;
	int				rotated: 1;
	int				axis: 1;
	t_list		*world;
	t_camera	camera;
	t_element	ambient_light;
	double		aspect_ratio;
	double		max_depth;
	t_mouse		mouse;
	void		(*ft_draw)(t_data *);
	t_element	*element;
	t_vec3d		vector;
	double		modifier;
	double		angle;
	t_vec3d		(*ft_color)(t_hit_record *a, t_ray *b, struct s_data *c);
	int			value_color;
	t_mlx_img	img;
	t_mlx_img	normal;
	t_mlx_img	bump;
	int			textured;
	void		(*ft_texture)(t_hit_record *, struct s_element *,
			struct s_data *);
	int			mirror_limit;
//	t_vec3d		perlin;
//	double		perlin_ranfloat[256];
//	int			perlin_init;
}	t_data;


/* normalize.c */
double			normalize_coord(double coord, double max_coord,
		double min_coord);
double			unnormalize_coord(double n_coord, double max_coord,
					double min_coord);
/* hooks.c */
void	    ft_double_normalize(double *nbr);
int				key_hook(int keycode, t_data *img);
int				hook_close(void);
int				hook_mouse(int button, int x, int y, void *param);
void	ft_print_vector(const char *str, t_vec3d vector);
/* draw.c */
void			ft_draw_without_antialiasing(t_data *img);
void			my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);
/* rotations.c */
t_vec3d			ft_rotate_x(t_vec3d vector, double angle);
t_vec3d			ft_rotate_y(t_vec3d vector, double angle);
t_vec3d			ft_rotate_z(t_vec3d vector, double angle);
/* angle.c */
double			ft_degree_to_radians(double degree);
double			ft_radians_to_degree(double radians);
/* init_figures.c */
t_element		*sphere(t_vec3d coord, double diameter,
					t_colour colour);
t_element		ambient_light(double intensity, t_colour colour);
t_element		*light(t_vec3d origin, double brightness, t_colour colour);
t_element		*plane(t_vec3d coords, t_vec3d normalized_orientation_vector,
					t_colour colour);
t_element		*cylinder(t_vec3d coords, t_vec3d normalized_orientation_vector,
					double param[2], t_colour colour);
t_element		*cone(t_vec3d coords, t_vec3d normalized_orientation_vector,
					double param[2], t_colour colour);
/* vec3d.c */
t_vec3d			ft_init_vec3d(double x, double y, double z);
double			ft_vec3d_len(t_vec3d o1);
double			ft_vec3d_squared_len(t_vec3d o1);
t_vec3d			ft_vec3d_unit_lenght(t_vec3d o1);
int				ft_vec3d_eq(t_vec3d v1, t_vec3d v2);
t_vec3d			ft_vec3d_negative(t_vec3d ptr);
t_vec3d			ft_vec3d_xz(t_vec3d v1);
t_vec3d			ft_vec3d_yz(t_vec3d v1);
/* vec3d_math_vec3d.c */
t_vec3d			ft_vec3d_plus_vec3d(t_vec3d o1, t_vec3d o2);
t_vec3d			ft_vec3d_minus_vec3d(t_vec3d o1, t_vec3d o2);
t_vec3d			ft_vec3d_pro_vec3d(t_vec3d o1, t_vec3d o2);
double			ft_vec3d_dot(t_vec3d o1, t_vec3d o2);
t_vec3d			ft_vec3d_cross(t_vec3d o1, t_vec3d o2);
/* vec3d_math_double.c */
t_vec3d			ft_vec3d_pro_double(t_vec3d o1, double o2);
t_vec3d			ft_vec3d_div_double(t_vec3d o1, double o2);
/* ray.c */
t_ray			ft_init_ray(t_vec3d origin, t_vec3d direction);
t_vec3d			ft_ray_at(t_ray *ray, double t);
t_vec3d			ft_ray_color(t_ray *ray, t_data *img);
t_vec3d			ft_ray_direction(t_data *img, int x, int y, int flag);
/* ppm.c */
void			ft_draw_ppm_header(int width, int height, int fd);
void			ft_draw_ppm_pixel(int colour, int fd, int endian);
int				get_mlx_pixel_colour(t_mlx_img *img, int x, int y);
void			ft_prt_ppm_file_from_img(t_mlx_img *img, int width, int height,
					int fd);
/* camera.c */
void			ft_img(t_data *img, const int image_width,
					const double aspect_ratio);
t_camera		ft_init_camera(t_vec3d lookfrom, const double aspect_ratio,
					const double fov, t_vec3d lookat);
void	ft_fix_camera_lookat(t_camera *camera);
/* sphere.c */
int				ft_hit_sphere(t_ray *ray, t_camera *camera,
					t_hit_record *rec, t_element *sphere);
/* hit.c */
void			ft_hit_face(t_ray *ray, t_hit_record *rec);
int				ft_hittable(t_ray *ray, t_data *img, t_hit_record *rec);
t_element		*ft_hittable_element(t_ray *ray, t_data *img,
					t_hit_record *rec);
/* world.c */
int				ft_world(t_data *img);
/* random_number.c */
unsigned int	uint_random_nbr(void);
double			pseudo_random(void);
double			random_double(double min, double max);
/* antialiasing.c */
void			ft_draw_antialiasing(t_data *img);
/* color.c */
int				ft_write_color(t_vec3d vector, int samplex_per_pixel);
t_vec3d			ft_colour_to_vec3d(t_colour colour);
t_vec3d	  ft_pixel_to_raw_color_vec3d(int pixel, int endian);

/* number.c */
double			clamp(double x, double min, double max);
double			ft_dabs(double num);
/* parse.c */
void			ft_run_is_space(char *str, size_t *pos);
int				ft_parse_file(char *file, t_data *img);
/* ft_is_space.c */
int				ft_is_space(char chr);
/* ft_atof.c */
double			ft_atof(char	*str);
/* parse_utils.c */
int				ft_parse_double(char *str, size_t *pos, double *value);
int				ft_parse_unsigned_char(char *str, size_t *pos,
					unsigned char *value);
int				ft_parse_comma(char *str, size_t *pos);
int				ft_parse_end(char *str, size_t pos);
int				ft_parse_vec3d(char *str, size_t *pos, t_vec3d *vector);
int				ft_parse_colour(char *str, size_t *pos, t_colour *colour);
/* ft_run.c */
void			ft_run_is_space(char *str, size_t *pos);
int				ft_run_atof(char *str, size_t *pos);
int				ft_run_atoi(char *str, size_t *pos);
/* plane.c */
int				ft_hit_plane(t_ray *ray, t_camera *camera, t_hit_record *rec,
					t_element *plane);
/* cylinder.c */
int				ft_hit_cylinder(t_ray *ray, t_camera *camera, t_hit_record *rec,
					t_element *cylinder);
double			ft_hit_surface_base(t_ray *ray, t_camera *camera,
					t_element *cylinder, t_hit_record *rec);
void			ft_normal_cylinder(t_hit_record *rec, t_element *cylinder);
/* cone.c */
int				ft_hit_cone(t_ray *ray, t_camera *camera, t_hit_record *rec,
					t_element *cylinder);
//void			ft_normal_cone(t_hit_record *rec, t_element *cylinder, t_ray *ray);
/* light.c */
t_vec3d			ft_diffuse_light(t_hit_record *rec, t_ray *ray, t_data *img,
					t_element *light);
t_vec3d			ft_specular_light(t_hit_record *rec, t_ray *ray, t_data *img,
					t_element *light);
t_vec3d			ft_ambient_light(t_hit_record *rec, t_ray *ray, t_data *img);
void			ft_img_color(t_data *img);
t_vec3d			ft_color_diffuse_specular_ambiance_light(t_hit_record *rec,
					t_ray *ray, t_data *img);
/*light_utils.c*/
int				ft_find_light(void *node);
t_vec3d			ft_calculate_lights(t_hit_record *rec, t_ray *ray, t_data *img,
					t_vec3d (*f)(t_hit_record *, t_ray *, t_data *,
						t_element *));
double			ft_shadow_ray(t_hit_record *rec, t_data *img, t_element *light);
void			ft_img_color(t_data *img);
/* Unused function */
t_vec3d			ft_color_ambient_light(t_hit_record *rec, t_ray *ray,
				t_data *img);
/* light_fun.c */
t_vec3d			ft_color_diffuse_light(t_hit_record *rec, t_ray *ray,
				t_data *img);
t_vec3d			ft_color_specular_light(t_hit_record *rec, t_ray *ray,
					t_data *img);
t_vec3d			ft_color_ambient_diffuse_light(t_hit_record *rec, t_ray *ray,
				t_data *img);
t_vec3d			ft_color_specular_ambient_light(t_hit_record *rec, t_ray *ray,
				t_data *img);
t_vec3d			ft_color_specular_diffuse_light(t_hit_record *rec, t_ray *ray,
				t_data *img);
/* texture_coordinates.c  */
void	ft_checker_normal_image(t_hit_record *rec, t_element *sphere,
		t_data *img);
void			ft_sphere_uv(t_hit_record *rec, t_element *sphere);
void			ft_checker_texture(t_hit_record *rec, t_element *sphere,
					t_data *img);
void			ft_checker_texture_image(t_hit_record *rec, t_element *sphere,
				t_data *img);
double			ft_perlin_noise(t_hit_record *rec, t_data *img);
void			ft_perlin_init(t_data *img);
void			ft_checkerboard(t_hit_record *rec, t_element *element,
				t_data *img);
void			ft_cylinder_uv(t_hit_record *rec, t_element *cylinder);
void			ft_cone_uv(t_hit_record *rec, t_element *cylinder);
void			ft_plane_uv(t_hit_record *rec, t_element *plane);
void			ft_checker_bump_image(t_hit_record *rec, t_element *sphere,
					t_data *img);
void			ft_checker_bump(t_hit_record *rec, t_element *sphere,
					t_data *img);
void			ft_checker_normal(t_hit_record *rec, t_element *sphere,
					t_data *img);
void			ft_texture(t_data *img);
void			ft_load_img(t_data *img);
/* matrix.c */
t_m3x3			ft_init_m3x3(t_vec3d v1, t_vec3d v2, t_vec3d v3);
t_m3x3			ft_tbn(t_vec3d normal);
t_vec3d			ft_vec3d_pro_matrix(t_vec3d vector, t_m3x3 matrix);
/* parse.c */
int	ft_parse_sphere(char *str, size_t pos, t_data *img);
int	ft_parse_camera(char *str, size_t pos, t_data *img);
int	ft_parse_ambient_light(char *str, size_t pos, t_data *img);
int	ft_parse_light(char *str, size_t pos, t_data *img);
int	ft_parse_plane(char *str, size_t pos, t_data *img);
/* cone_utils.c */
int	ft_base_of_the_cone(t_ray *ray, t_camera *camera,
		t_hit_record *rec, t_element *cone);
void	ft_normal_cone(t_hit_record *rec, t_element *cylinder, t_ray *ray);
/* cylinder_utils.h */
double	ft_hit_surface_base(t_ray *ray, t_camera *camera, t_element *cylinder,
		t_hit_record *rec);
double	ft_hit_surface_top(t_ray *ray, t_camera *camera, t_element *cylinder,
		t_hit_record *rec);
int	ft_base_of_the_cylinder(t_ray *ray, t_camera *camera, t_hit_record *rec,
		t_element *cylinder);
/* parse_utils_v2 */
int	ft_common_cylinder_cone(char *str, size_t *pos, t_vec3d *coords,
		t_vec3d *normalized_orientation_vector);
/* bump.c */
t_vec3d	ft_raw_vec3d_to_normalized(t_vec3d raw);
t_vec3d ft_raw_bu(t_mlx_img *img, int x, int y);
t_vec3d ft_raw_bv(t_mlx_img *img, int x, int y);
t_vec3d	ft_bump(int x, int y, t_data *img, t_hit_record *rec);
/*reflect */
t_colour	ft_color_mix(const t_hit_record *rec, const t_ray *ray, t_data *img);
t_colour	ft_color_mirror(const t_hit_record *rec, const t_ray *ray, t_data *img);
t_vec3d	reflect(t_vec3d vector_n, t_vec3d normal_n);
#endif
