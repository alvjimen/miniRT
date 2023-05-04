/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:49:59 by alvjimen          #+#    #+#             */
/*   Updated: 2023/05/04 13:11:45 by alvjimen         ###   ########.fr       */
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

int			key_hook(int keycode);
int			hook_close(void);
void		ft_draw_square(t_data *img, int px, int py, int width, int height);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif

