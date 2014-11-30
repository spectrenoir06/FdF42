/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:03:39 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:03:40 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

void		ft_draw_pixel2d(t_env env, t_pt2d p, t_color c)
{
	mlx_pixel_put(env.mlx, env.win, p.x, p.y, ft_color_to_int(c));
}

static void		ft_draw_line_sub1(t_env env, t_line l)
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
		ft_draw_pixel2d(env, l.p1, l.c1);
	}
}

static void		ft_draw_line_sub2(t_env env, t_line l)
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
		ft_draw_pixel2d(env, l.p1, l.c1);
	}
}

void		ft_draw_line2d(t_env env, t_pt2d p1, t_pt2d p2, t_color c)
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

void		ft_draw_rect2d(t_env env, t_rect r, t_color c)
{
	int		lx;

	lx = r.p2.x - r.p1.x;
	while (r.p1.x <= r.p2.x && r.p1.y <= r.p2.y)
	{
		ft_draw_pixel2d(env, r.p1, c);
		if (++r.p1.x >= r.p2.x)
		{
			r.p1.x -= lx;
			r.p1.y++;
		}
	}
}

t_rect		ft_new_rect(t_pt2d p1, t_pt2d p2)
{
	t_rect		r;

	r.p1 = p1;
	r.p2 = p2;
	return (r);
}

