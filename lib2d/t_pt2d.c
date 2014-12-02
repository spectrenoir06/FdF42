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
	t_rect	r;

	r.p1 = p1;
	r.p2 = p2;
	return (r);
}

t_pt2d		ft_new_point2d(int x, int y)
{
	t_pt2d	p;

	p.x = x;
	p.y = y;
	return (p);
}
