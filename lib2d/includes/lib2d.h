/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 16:18:43 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/24 19:13:50 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB2D_H
# define LIB2D_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define SCREEN_SIZE_X 500
# define SCREEN_SIZE_Y 500

typedef unsigned char	t_byte;
typedef unsigned char	t_uint8;
typedef unsigned short	t_uint16;
typedef unsigned long	t_uint32;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_color
{
	unsigned char			r;
	unsigned char			g;
	unsigned char			b;
}					t_color;

typedef struct		s_img
{
	char			*data;
	void			*img;
	int				bpp;
	int				lx;
	int				ly;
	int				endian;
	int				mult;
}					t_img;

typedef struct		s_pt2d
{
	int				x;
	int				y;
}					t_pt2d;

typedef struct		s_pt3d
{
	int				x;
	int				y;
	int				z;
}					t_pt3d;

typedef struct		s_rect
{
	t_pt2d			p1;
	t_pt2d			p2;
}					t_rect;

typedef struct		s_line
{
	t_pt2d			p1;
	t_pt2d			p2;
	t_color			c1;
	t_color			c2;
	t_pt2d			inc;
	int				dx;
	int				dy;
}					t_line;

t_pt2d				ft_new_point2d(int x, int y);

void				ft_draw_pixel3d(t_env env, t_pt3d p, t_color c);
t_pt3d				ft_new_point3d(int x, int y, int z);

t_pt2d				ft_3d_to_2d(t_pt3d p);

t_rect				ft_new_rect(t_pt2d p1, t_pt2d p2);

t_pt3d				ft_3d_mul(t_pt3d p, float k);

void				ft_draw_pixel2d(t_env env, t_pt2d p, t_color c);
void				ft_draw_rect2d(t_env env, t_rect r, t_color c);

int					ft_draw_pixel2d_img(t_img img, t_pt2d p, t_color c);
void				ft_draw_rect2d_img(t_img img, t_rect r, t_color c);

int					ft_color_to_int(t_color c);
t_color				ft_int_to_color(int c);
t_color				ft_rgb(unsigned char r, unsigned char g, unsigned char b);

void				ft_draw_line2d(t_env env, t_pt2d p1, t_pt2d p2, t_color c);
void				ft_draw_line3d(t_env env, t_pt3d p1, t_pt3d p2, t_color c);

void				ft_draw_line2d_img(t_img i, t_pt2d p, t_pt2d q, t_color c);
void				ft_draw_line3d_img(t_img i, t_pt3d p, t_pt3d q, t_color c);
void				ft_fill(t_img img, t_pt2d p, t_color c);

#endif
