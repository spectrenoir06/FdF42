/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:11:27 by adoussau          #+#    #+#             */
/*   Updated: 2014/12/01 15:11:29 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"
#include "main.h"
#include "draw_map.h"

t_pt2d		moy2(t_all *all, int x, int y)
{
	t_pt2d	p1;
	t_pt2d	p2;
	t_pt2d	p3;
	t_pt2d	p4;

	p1 = ft_3d_to_2d(warp(all, all->map.tab[x][y]), all->env);
	p2 = ft_3d_to_2d(warp(all, all->map.tab[x + 1][y]), all->env);
	p3 = ft_3d_to_2d(warp(all, all->map.tab[x][y + 1]), all->env);
	p4 = ft_3d_to_2d(warp(all, all->map.tab[x + 1][y + 1]), all->env);
	return (ft_new_point2d((p3.x + p2.x) / 2, (p1.y + p4.y) / 2));
}

void		draw_map_fill_2(t_all *all)
{
	int		x = (all->map.lx - 2);
	int		y = (all->map.ly - 2);
	t_byte	c1;

	while (y >= 0)
	{
		x = (all->map.lx - 2);
		while (x >= 0)
		{
			c1 = remap(moy(all->map.tab[x][y], all->map.tab[x + 1][y + 1]),
				all->map.min, all->map.max);

			drawTriangle3D(
				all->img,
				ft_3d_mul(all->map.tab[x][y], all->pad),
				ft_3d_mul(all->map.tab[x + 1][y], all->pad),
				ft_3d_mul(all->map.tab[x + 1][y + 1], all->pad),
				ft_int_to_color(all->palette[c1]));
			drawTriangle3D(
				all->img,
				ft_3d_mul(all->map.tab[x][y + 1], all->pad),
				ft_3d_mul(all->map.tab[x][y], all->pad),
				ft_3d_mul(all->map.tab[x + 1][y + 1], all->pad),
				ft_int_to_color(all->palette[c1]));

			x--;
		}
		y--;
	}
}

void		draw_map_end_v(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	y = all->map.ly - 1;
	x = (all->map.lx - 2);
	while (x >= 0)
	{
		c1 = remap(moy(all->map.tab[x][y], all->map.tab[x + 1][y]),
			all->map.min, all->map.max);
		ft_draw_line3d_img(all->img,
			ft_3d_mul(all->map.tab[x][y], all->pad),
			ft_3d_mul(all->map.tab[x + 1][y], all->pad),
			ft_int_to_color(all->palette[c1]));
		x--;
	}
}

void		draw_map_end_h(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	x = all->map.lx - 1;
	y = (all->map.ly - 2);
	while (y >= 0)
	{
		c1 = remap(moy(all->map.tab[x][y], all->map.tab[x][y + 1]),
			all->map.min, all->map.max);
		ft_draw_line3d_img(all->img,
			ft_3d_mul(all->map.tab[x][y], all->pad),
			ft_3d_mul(all->map.tab[x][y + 1], all->pad),
			ft_int_to_color(all->palette[c1]));
		y--;
	}
}

void		draw_map_fill(t_all *all)
{
	//2draw_map_end_v(all);
	//draw_map_end_h(all);
	draw_map_fill_2(all);
}
