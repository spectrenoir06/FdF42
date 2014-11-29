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

# define SCREEN_SIZE_X 1280
# define SCREEN_SIZE_Y 720

typedef unsigned char	t_byte;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_color
{
	t_byte			r;
	t_byte			g;
	t_byte			b;
}					t_color;

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

typedef struct		s_rect
{
	t_pt2d			p1;
	t_pt2d			p2;
}					t_rect;

int					ft_colortoint(t_color c);
void				ft_draw_rect(t_env e, t_rect r, t_color c);
void				ft_draw_pixel(t_env env, t_pt2d p, t_color c);
void				ft_draw_line(t_env env, t_pt2d p1, t_pt2d p2, t_color c);
t_pt2d				ft_new_point(int x, int y);
t_rect				ft_new_rect(t_pt2d p1, t_pt2d p2);
t_color				ft_rgb_to_color(t_byte r, t_byte g, t_byte b);
t_pt2d				ft_3d_to_2d(t_pt3d	p);
t_pt3d				ft_new_point3d(int x, int y, int z);
void				ft_draw_line3d(t_env env, t_pt3d p1, t_pt3d p2, t_color c);
void				ft_draw_pixel3d(t_env env, t_pt3d p, t_color c);
t_pt3d				ft_point3d_mul(t_pt3d p, int k);
void				ft_draw_line_sub1(t_env env, t_line l);
void				ft_draw_line_sub2(t_env env, t_line l);

#endif
