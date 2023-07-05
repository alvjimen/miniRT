#include "minirt.h"

/*
y = -cos(tetha)
x = -cos(phi)sin(tetha)
z = sin(phi)sin(tetha)

u = phi / (2 * PI)
v = tetha / PI
phi = with atan2(z, -x)
phi = atan2(-z, x) + PI
tetha = acos(-y)
*/
void	ft_sphere_uv(t_hit_record *rec, t_element *sphere)
{
	t_vec3d	p;
	double	theta;
	double	phi;

	p = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(sphere->coords, rec->p));
	theta = acos(-p.y);
	phi = atan2(-p.z, p.x) + M_PI;
	rec->u = phi / (2 * M_PI);
	rec->v = theta / M_PI;
}
/*
 * u = (M_PI + tetha) / (2 * M_PI)
 * v = (h/2 + y) / h
 */
void	ft_cylinder_uv(t_hit_record *rec, t_element *cylinder)
{
	rec->u = 0.5 + atan2(rec->normal.x / cylinder->radius, rec->normal.z / cylinder->radius) / (2 * M_PI);
	rec->v = ft_vec3d_len(ft_vec3d_minus_vec3d(cylinder->coords, rec->h)) / cylinder->height;
}

double	ft_perlin_noise(t_hit_record *rec, t_data *img)
{
	int i;
	int j;
	int k;

	if (!img->perlin_init)
		ft_perlin_init(img);
	i = (int)(4 * rec->p.x) & 0xff;
	j = (int)(4 * rec->p.y) & 0xff;
	k = (int)(4 * rec->p.z) & 0xff;
	return (img->perlin_ranfloat[i ^ j ^ k]);
}

void	ft_perlin_init(t_data *img)
{
	int		counter;

	counter = -1;
	while (++counter < 256)
		img->perlin_ranfloat[counter] = random_double(0, 1);
	img->perlin_init = 1;
}

void	ft_checker_texture(t_hit_record *rec, t_element *sphere, t_data *img)
{
	if (sphere)
		ft_perlin_init(img);
	else
		ft_perlin_init(img);
	ft_bzero(&rec->colour, sizeof(rec->colour));
		rec->colour.red =  ft_perlin_noise(rec, img) * 255;
		rec->colour.green =  ft_perlin_noise(rec, img) * 255;
		rec->colour.blue =  ft_perlin_noise(rec, img) * 255;
}
/*
u = i / (Nx - 1);
v = j / (Ny - 1);
*/
void	ft_checkerboard_v2(t_hit_record *rec, t_element *element, t_data *img)
{

	if (((fmod(ft_dabs(rec->v), 0.05) < 0.025) == (fmod(ft_dabs(rec->u), 0.05) < 0.025)))
		ft_bzero(&rec->colour, sizeof(rec->colour));
	else
	{
		rec->colour.red = 255;
		rec->colour.green = 255;
		rec->colour.blue = 255;
	}
	if (element || img)
		return ;
}

/*
void	ft_checkerboard(t_hit_record *rec, t_element *element, t_data *img)
{
	t_vec3d	p;
	double	sines;

	p = ft_vec3d_unit_lenght(rec->normal);
	sines = sin(p.x * 10) * sin(p.y * 10) * sin(p.z * 10);
	if (sines < 0)
		ft_bzero(&rec->colour, sizeof(rec->colour));
	else
		rec->colour.red = 255;
	if (element || img)
		return ;
}
*/

void	ft_load_img(t_data *img)
{
	if (!img->xpm)
	{
		img->xpm = mlx_xpm_file_to_image(img->mlx, XPM_PATH,
				&img->xpm_width, &img->xpm_height);
		if (!img->xpm)
			exit (1);
		img->xpm_address = mlx_get_data_addr(img->xpm, &img->xpm_bits_per_pixel, 
				&img->xpm_line_length, &img->xpm_endian);
		if (!img->xpm_address)
			exit (1);
	}
	if (!img->xpm_bump)
	{
		img->xpm_bump = mlx_xpm_file_to_image(img->mlx, XPM_BUMP_PATH,//"brick wall.xpm",
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

void	ft_checker_texture_image(t_hit_record *rec, t_element *sphere, t_data *img)
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
	pixel = &img->xpm_address[j * img->xpm_line_length + i * (img->xpm_bits_per_pixel / 8)];
	rec->colour.alpha = pixel[0];
	rec->colour.red = pixel[1];
	rec->colour.green = pixel[2];
	rec->colour.blue = pixel[3];
}

unsigned char	*ft_bump_pixel(int x, int y, t_data *img)
{
	return ((void *)&img->xpm_bump_address[y * img->xpm_bump_line_length +
			x * (img->xpm_bump_bits_per_pixel / 8)]);
}
/*
void ft_map_value(unsigned char *pixel, t_vec3d *ptr, int coord)
{
	if (!coord)
		*ptr = ft_init_vec3d(pixel[1], 0, 0);
	else 
		*ptr = ft_init_vec3d(0, pixel[1], 0);
}
*/

/*
void	ft_finite_difference(t_hit_record *rec, t_data *img, t_vec3d *bu, t_vec3d *bv)
{
	unsigned char	*pixel;
	int				i;
	int				j;
	t_vec3d			tmp;

	i = rec->u * img->xpm_bump_width;
	j = rec->v * img->xpm_bump_height;
	if (i >= img->xpm_bump_width)
		i = img->xpm_bump_width - 1;
	if (j >= img->xpm_bump_height)
		j = img->xpm_bump_height - 1;
	pixel = ft_bump_pixel((i + 1) % img->xpm_bump_width, j, img);
	ft_map_value(pixel, bu, 0);
	if (i - 1 < 0)
		pixel = ft_bump_pixel(img->xpm_bump_width - 1, j, img);
	else
		pixel = ft_bump_pixel(i - 1, j, img);
	ft_map_value(pixel, &tmp, 0);
	*bu = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(tmp, *bu));
	pixel = ft_bump_pixel(i, (j + 1) % img->xpm_bump_height, img);
	ft_map_value(pixel, bv, 1);
	if (j - 1 < 0)
		pixel = ft_bump_pixel(i, img->xpm_bump_height - 1, img);
	else
		pixel = ft_bump_pixel(i, j - 1, img);
	ft_map_value(pixel, &tmp, 1);
	*bv = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(tmp, *bv));
}
*/
void	ft_texture(t_data *img)
{
	if (img->textured == CHECKER)
		img->ft_texture = ft_checkerboard_v2;
	if (img->textured == IMG)
		img->ft_texture = ft_checker_texture_image;
	if (img->textured == BUMP)
		img->ft_texture = ft_checker_bump;
	if (img->textured == BUMP_IMG)
		img->ft_texture = ft_checker_bump_image;
}
//https://stackoverflow.com/questions/41015574/raytracing-normal-mapping

void	ft_checker_bump(t_hit_record *rec, t_element *sphere,
		t_data *img)
{
	int				i;
	int				j;
	t_vec3d			t;
	t_vec3d			b;
	t_vec3d			map;
	t_m3x3			tbn;
	unsigned char	*pixel;

	ft_load_img(img);
	i = rec->u * img->xpm_bump_width;
	j = rec->v * img->xpm_bump_height;
	if (i >= img->xpm_bump_width)
		i = img->xpm_bump_width - 1;
	if (j >= img->xpm_bump_height)
		j = img->xpm_bump_height - 1;
	t = ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 1, 0));
	if (!ft_vec3d_squared_len(t))
		t = ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 0, 1));
	t = ft_vec3d_unit_lenght(t);
	b = ft_vec3d_unit_lenght(ft_vec3d_cross(rec->normal, t));
	pixel = ft_bump_pixel(i, j, img);
	map = ft_init_vec3d(pixel[0], pixel[1], pixel[2]);
	map = ft_vec3d_minus_vec3d(
			ft_vec3d_pro_double(ft_vec3d_div_double(map,
					255), 2), ft_init_vec3d(1, 1, 1));
	tbn = ft_init_m3x3(t, b, rec->normal);
	rec->normal = ft_vec3d_unit_lenght(
			ft_vec3d_pro_matrix(map, tbn));
//	ft_checker_texture_image(rec, sphere, img);
	if (sphere)
		return ;
}

void	ft_checker_bump_image(t_hit_record *rec, t_element *sphere,
		t_data *img)
{
	int				i;
	int				j;
	t_vec3d			t;
	t_vec3d			b;
	t_vec3d			map;
	t_m3x3			tbn;
	unsigned char	*pixel;

	ft_load_img(img);
	i = rec->u * img->xpm_bump_width;
	j = rec->v * img->xpm_bump_height;
	if (i >= img->xpm_bump_width)
		i = img->xpm_bump_width - 1;
	if (j >= img->xpm_bump_height)
		j = img->xpm_bump_height - 1;
	t = ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 1, 0));
	if (!ft_vec3d_squared_len(t))
		t = ft_vec3d_cross(rec->normal, ft_init_vec3d(0, 0, 1));
	t = ft_vec3d_unit_lenght(t);
	b = ft_vec3d_unit_lenght(ft_vec3d_cross(rec->normal, t));
		pixel = ft_bump_pixel(i, j, img);
	map = ft_init_vec3d(pixel[0], pixel[1], pixel[2]);
	map = ft_vec3d_minus_vec3d(
			ft_vec3d_pro_double(ft_vec3d_div_double(map,
					255), 2), ft_init_vec3d(1, 1, 1));
	tbn = ft_init_m3x3(t, b, rec->normal);
	rec->normal = ft_vec3d_unit_lenght(
			ft_vec3d_pro_matrix(map, tbn));
	ft_checker_texture_image(rec, sphere, img);
	if (sphere)
		return ;
}

/*
void	ft_checker_bump_image(t_hit_record *rec, t_element *sphere, t_data *img)
{
	int		i;
	int		j;
	t_vec3d	bu;
	t_vec3d	bv;
	t_vec3d	bump_normal;
	t_vec3d	new_normal_bumped;

	if (!sphere && !rec)
		return ;
	ft_load_img(img);
	rec->u = clamp(rec->u, 0.0, 1.0);
	rec->v = clamp(rec->v, 0.0, 1.0);
	i = rec->u * img->xpm_bump_width;
	j = rec->v * img->xpm_bump_height;
	if (i >= img->xpm_bump_width)
		i = img->xpm_bump_width - 1;
	if (j >= img->xpm_bump_height)
		j = img->xpm_bump_height - 1;
	ft_finite_difference(rec, img, &bu, &bv);
	//bump_normal = ft_init_vec3d(bu.x, bv.y, sqrt(1 - bu.x * bu.x - bu.y * bu.y));
	//bump_normal = ft_vec3d_div_double(ft_vec3d_plus_vec3d(bump_normal, ft_init_vec3d(1, 1, 1)), 2);
	bump_normal = ft_vec3d_cross(ft_vec3d_plus_vec3d(rec->normal, bu), ft_vec3d_plus_vec3d(rec->normal, bv));
	new_normal_bumped = ft_vec3d_plus_vec3d(bump_normal, rec->normal);
	//More or less the same result
//	new_normal_bumped = bump_normal;
	if (ft_vec3d_squared_len(new_normal_bumped) != 1.0)
		new_normal_bumped = ft_vec3d_unit_lenght(new_normal_bumped);
	rec->normal = new_normal_bumped;
	//ft_checker_bump_image(rec, sphere, img);
}*//*
p' = p + (f(u,v)*N) / ||N||
*/
/*
void	ft_checker_bump_mapping(t_hit_record *rec, t_element *sphere, t_data *img)
{

}
*/
/*
TODO configure the textures/ image with more than unit radius sphere. 
*/
