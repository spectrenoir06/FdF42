/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 10:25:22 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/25 17:35:35 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

int			ft_colortoint(t_color c)
{
	int		i;

	i = c.r;
	i = i << 8;
	i += c.g;
	i = i << 8;
	i += c.b;
	return (i);
}

t_color		ft_inttocolor(int c)
{
	t_color i;

	c = (c & 0x00FFFFFF);
	i.b = (c & 0xFF);
	c = c >> 8;
	i.g = (c & 0xFF);
	c = c << 8;
	i.r = c;
	return (i);
}

t_color		ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color t;

	t.r = r;
	t.g = g;
	t.b = b;
	return (t);
}

void		ft_draw_rect(t_env env, t_rect r, t_color c)
{
	int		lx;

	lx = r.p2.x - r.p1.x;
	while (r.p1.x <= r.p2.x && r.p1.y <= r.p2.y)
	{
		ft_draw_pixel(env, r.p1, c);
		if (++r.p1.x >= r.p2.x)
		{
			r.p1.x -= lx;
			r.p1.y++;
		}
	}
}

void		ft_draw_pixel(t_env env, t_pt2d p, t_color c)
{
	mlx_pixel_put(env.mlx, env.win, p.x, p.y, ft_colortoint(c));
}

void		ft_draw_pixel3d(t_env env, t_pt3d p, t_color c)
{
	t_pt2d		t;

	t = ft_3d_to_2d(p);
	mlx_pixel_put(env.mlx, env.win, t.x, t.y, ft_colortoint(c));
}

void		ft_draw_line(t_env env, t_pt2d p1, t_pt2d p2, t_color c)
{
	t_line	l;

	l.inc.x = ((p2.x - p1.x) > 0) ? 1 : -1;
	l.inc.y = ((p2.y - p1.y) > 0) ? 1 : -1;
	l.dx = abs(p2.x - p1.x);
	l.dy = abs(p2.y - p1.y);
	l.p1 = p1;
	l.p2 = p2;
	l.c1 = c;
	l.c2 = c;
	if (l.dx > l.dy)
		ft_draw_line_sub1(env, l);
	else
		ft_draw_line_sub2(env, l);
}

void		ft_draw_line_sub1(t_env env, t_line l)
{
	int		cumul;
	int		i;

	i = 1;
	cumul = l.dx / 2;
	while (i++ <= l.dx)
	{
		l.p1.x += l.inc.x;
		cumul += l.dy;
		if (cumul >= l.dx)
		{
			cumul -= l.dx;
			l.p1.y += l.inc.y;
		}
		ft_draw_pixel(env, l.p1, l.c1);
	}
}

void		ft_draw_line_sub2(t_env env, t_line l)
{
	int		cumul;
	int		i;

	i = 1;
	cumul = l.dy / 2;
	while (i++ <= l.dy)
	{
		l.p1.y += l.inc.y;
		cumul += l.dx;
		if (cumul >= l.dy)
		{
			cumul -= l.dy;
			l.p1.x += l.inc.x;
		}
		ft_draw_pixel(env, l.p1, l.c1);
	}
}

void		ft_draw_line3d(t_env env, t_pt3d p1, t_pt3d p2, t_color c)
{
	ft_draw_line(env, ft_3d_to_2d(p1), ft_3d_to_2d(p2), c);
}

t_pt2d		ft_new_point(int x, int y)
{
	t_pt2d		t;

	t.x = x;
	t.y = y;
	return (t);
}

t_pt3d		ft_new_point3d(int x, int y, int z)
{
	t_pt3d		t;

	t.x = x;
	t.y = y;
	t.z = z;
	return (t);
}

t_pt2d		ft_3d_to_2d(t_pt3d p)
{
	t_pt2d		t;

	t.x = p.x - p.y + (SCREEN_SIZE_X / 2);
	t.y = (-p.z * 10) + (p.x / 2.0) + (p.y / 2.0) + (SCREEN_SIZE_Y / 3);
	return (t);
}

t_rect		ft_new_rect(t_pt2d p1, t_pt2d p2)
{
	t_rect		r;

	r.p1 = p1;
	r.p2 = p2;
	return (r);
}

t_pt3d		ft_point3d_mul(t_pt3d p, int k)
{
	p.x *= k;
	p.y *= k;
	return (p);
}
