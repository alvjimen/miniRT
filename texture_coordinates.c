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
	//t_vec3d	p;
//	double	sines;

	//p = ft_vec3d_unit_lenght(ft_vec3d_minus_vec3d(sphere->coords, rec->p));
	//sines = sin(p.x * 10) * sin(p.y * 10) * sin(p.z * 10); 
	if (sphere)
		ft_perlin_init(img);
	else
		ft_perlin_init(img);
	ft_bzero(&rec->colour, sizeof(rec->colour));
	//if (sines < 0)
		rec->colour.red =  ft_perlin_noise(rec, img) * 255;
		rec->colour.green =  ft_perlin_noise(rec, img) * 255;
		rec->colour.blue =  ft_perlin_noise(rec, img) * 255;
	//else
}
/*
u = i / (Nx - 1);
v = j / (Ny - 1);
*/

void	ft_checker_texture_image(t_hit_record *rec, t_element *sphere, t_data *img)
{
	int		i;
	int		j;
	char	*pixel;

	if (!sphere && !rec)
		return ;
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
	rec->u = clamp(rec->u, 0.0, 1.0);
	/*This becouse we start on the left_bottom corner*/
	rec->v = clamp(rec->v, 0.0, 1.0);
	i = rec->u * img->xpm_width;
	j = rec->v * img->xpm_height;
	if (i >= img->xpm_width)
		i = img->xpm_width - 1;
	if (j >= img->xpm_height)
		j = img->xpm_height - 1;
	/* a bad bump_mapping
	if ((!(i % 15) &&  j % 5) || !(j % 60))
		rec->normal = ft_vec3d_div_double(rec->normal, 2);
	*/
	pixel = &img->xpm_address[j * img->xpm_line_length + i * (img->xpm_bits_per_pixel / 8)];
	rec->colour.alpha = pixel[0];
	rec->colour.red = pixel[1];
	rec->colour.green = pixel[2];
	rec->colour.blue = pixel[3];
	//mlx_put_image_to_window(img->mlx, img->mlx_win, img->xpm, 0, 0);
}

/*
p' = p + (f(u,v)*N) / ||N||
*/
/*
void	ft_checker_bump_mapping(t_hit_record *rec, t_element *sphere, t_data *img)
{

}
*/
