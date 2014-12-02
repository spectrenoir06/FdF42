/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 20:05:22 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 20:05:24 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

static void		ft_draw_line_sub1_img(t_img img, t_line l)
{
	int			cumul;
	int			i;

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
		ft_draw_pixel2d_img(img, l.p1, l.c1);
	}
}

static void		ft_draw_line_sub2_img(t_img img, t_line l)
{
	int			cumul;
	int			i;

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
		ft_draw_pixel2d_img(img, l.p1, l.c1);
	}
}

void			ft_draw_line2d_img(t_img img, t_pt2d p1, t_pt2d p2, t_color c)
{
	t_line		l;

	l.inc.x = ((p2.x - p1.x) > 0) ? 1 : -1;
	l.inc.y = ((p2.y - p1.y) > 0) ? 1 : -1;
	l.dx = abs(p2.x - p1.x);
	l.dy = abs(p2.y - p1.y);
	l.p1 = p1;
	l.p2 = p2;
	l.c1 = c;
	l.c2 = c;
	ft_draw_pixel2d_img(img, p1, c);
	if (l.dx > l.dy)
		ft_draw_line_sub1_img(img, l);
	else
		ft_draw_line_sub2_img(img, l);
}
