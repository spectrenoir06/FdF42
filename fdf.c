/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:11:27 by adoussau          #+#    #+#             */
/*   Updated: 2014/12/01 15:11:29 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"
#include "main.h"

int		moy(t_pt3d p1, t_pt3d p2)
{
	return ((p1.z + p2.z) / 2.0);
}

t_pt2d		moy2(t_pt3d p1, t_pt3d p2)
{
	t_pt2d	p3;
	t_pt2d	p4;

	p3 = ft_3d_to_2d(p1);
	p4 = ft_3d_to_2d(p2);
	return
	(
		ft_new_point2d
		(
			(p3.x + p4.x) / 2,
			(p3.y + p4.y) / 2
		)
	);
}

int		remap(int x, int inmi, int inma)
{
	return (x - inmi) * (14 - 0) / (inma - inmi) + 0;
}

void draw_map_end_v(t_all *all)
{
	int		x;
	int		y;

	y = all->map.ly - 1;
	x = (all->map.lx - 2);
	while (x >= 0)
		{
			ft_draw_line3d_img(all->img,
			ft_3d_mul(all->map.tab[x][y], all->pad),
			ft_3d_mul(all->map.tab[x + 1][y], all->pad),
			ft_rgb(100,100,100));
		x--;
	}
}

void draw_map_end_h(t_all *all)
{
	int		x;
	int		y;

	x = all->map.lx - 1;
	y = (all->map.ly - 2);
	while (y >= 0)
		{
			ft_draw_line3d_img(all->img,
			ft_3d_mul(all->map.tab[x][y], all->pad),
			ft_3d_mul(all->map.tab[x][y + 1], all->pad),
			ft_rgb(100,100,100));
			y--;
		}
	}

#include <stdio.h>

void draw_map_fill_2(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	t_pt2d	p3;
	//t_pt2d	p4;
	y = (all->map.ly - 2);
	while (y >= 0)
		{
			x = (all->map.lx - 2);
			while (x >= 0)
				{
					ft_draw_line3d_img(all->img,
					ft_3d_mul(all->map.tab[x][y], all->pad),
					ft_3d_mul(all->map.tab[x + 1][y], all->pad),
					ft_rgb(100,100,100));
					ft_draw_line3d_img(all->img,
						ft_3d_mul(all->map.tab[x][y], all->pad),
						ft_3d_mul(all->map.tab[x][y + 1], all->pad),
						ft_rgb(100,100,100));
					p3 = moy2(ft_3d_mul(all->map.tab[x + 1][y], all->pad),
							ft_3d_mul(all->map.tab[x][y + 1], all->pad));
					//printf("%d , %d\n",x,y);

					c1 = remap(moy(all->map.tab[x][y], all->map.tab[x][y + 1]),
						all->map.min, all->map.max);
					ft_fill(all->img, p3,
						ft_int_to_color(all->palette[c1]));
					//ft_draw_pixel2d_img(all->img, p3,
					//	ft_int_to_color(all->palette[c1]));
					x--;
				}
				y--;
			}
}

void	draw_map_v(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	y = (all->map.ly - 1);
	while (y >= 0)
		{
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
				y--;
			}
}

void	draw_map_h(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	x = (all->map.lx - 1);
	while (x >= 0)
		{
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
				x--;
			}
		}

void	draw_map(t_all *all)
{
	draw_map_h(all);
	draw_map_v(all);
}

void	draw_map_fill(t_all *all)
{
	draw_map_end_v(all);
	draw_map_end_h(all);
	draw_map_fill_2(all);
}
