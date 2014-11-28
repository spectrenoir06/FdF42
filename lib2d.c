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

int		ft_colortoint(t_color c)
{
	int		i;

	i = c.r;
	i = i << 8;
	i += c.g;
	i = i << 8;
	i += c.b;
	return (i);
}

t_color	ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color t;

	t.r = r;
	t.g = g;
	t.b = b;
	return (t);
}

void	ft_draw_rect(t_env env, t_rect r, t_color c)
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

void	ft_draw_pixel(t_env env, t_pt2d p, t_color c)
{
	mlx_pixel_put(env.mlx, env.win, p.x, p.y, ft_colortoint(c));
}

void	ft_draw_pixel3d(t_env env, t_pt3d p, t_color c)
{
	t_pt2d		t;

	t = ft_3d_to_2d(p);
	mlx_pixel_put(env.mlx, env.win, t.x, t.y, ft_colortoint(c));
}

void	ft_draw_line(t_env env, t_pt2d p1, t_pt2d p2, t_color c)
{
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	i = 1;
	if (dx > dy)
	{
		cumul = dx / 2;
		while (i++ <= dx)
		{
			p1.x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				p1.y += yinc;
			}
			ft_draw_pixel(env, p1, c);
		}
	}
	else
	{
		cumul = dy / 2;
		while (i++ <= dy)
		{
			p1.y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				p1.x += xinc;
			}
			ft_draw_pixel(env, p1, c);
		}
	}
}

void	ft_draw_line3d(t_env env, t_pt3d p1, t_pt3d p2, t_color c)
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

	t.x = p.x - p.y;
	t.y = p.z + (p.x / 2.0) + (p.y / 2.0);
	return (t);
}

t_rect		ft_new_rect(t_pt2d p1, t_pt2d p2)
{
	t_rect		r;

	r.p1 = p1;
	r.p2 = p2;
	return (r);
}

t_pt3d	ft_point3d_mul(t_pt3d p, int k)
{
	p.x *= k;
	p.y *= k;
	return (p);
}
