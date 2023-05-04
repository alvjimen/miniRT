/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:49:59 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/04 18:37:55 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H
/*KEYBOARD BINDING*/
# ifdef	__APPLE__
#  define ESC 53
# else
#  define ESC 65307
# endif
/*WIN SIZE*/
# define WIN_H 640
# define WIN_W 640

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

typedef struct	s_3dcord
{
	float	x;
	float	y;
	float	z;
}	t_3dcord;

int			coordx_center(int x);
int			coordx_uncenter(int x);
int			coordy_center(int y);
int			coordy_uncenter(int y);
int			key_hook(int keycode);
int			hook_close(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_draw_square(t_data *img, int c, int p, int px, int py);
void		ft_draw_circle(t_data *img, int c, int p, int radius);
double		ft_aspect_ratio(void);
#endif

