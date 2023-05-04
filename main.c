#include "mlx.h"
#include "minirt.h"
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y *data->line_length + x * 4);
	*(unsigned int *)dst = color;
}

/*
int	key_hook(int keycode)
{
	if (keycode == ESC)
		exit(0);
	printf("Keycode: %d\n", keycode);
	return (0);
}

int	hook_close(void)
{
	printf("Closing the window\n");	
	exit(0);
}
*/
void	ft_draw_square(t_data *img, int px, int py, int width, int height)
{
	int	counterx = 0;
	int	countery = 0;

	while (px + counterx < WIN_W && px + counterx >= 0 && width >= counterx)
	{
		countery = 0;
		while (py + countery < WIN_H && py + countery >= 0 && height >= countery)
		{
			my_mlx_pixel_put(img, py + countery, px + counterx, 0x00FF0000); 
			countery++;
		}
		counterx++;
	}

}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win  = mlx_new_window(mlx, WIN_W, WIN_H, "Hello World");
	img.img = mlx_new_image(mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	/*
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 4, 4, 0x00FF0000);
	my_mlx_pixel_put(&img, 3, 3, 0x00FF0000);
	my_mlx_pixel_put(&img, 2, 2, 0x00FF0000);
	my_mlx_pixel_put(&img, 1, 1, 0x00FF0000);
	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	*/
	ft_draw_square(&img, 5, 5, 100, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_hook(mlx_win, 17, 0, hook_close, &img);
	mlx_loop(mlx);
}
