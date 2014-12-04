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

int degra[] = {
	0x01B0F0,
	0x01B0F0,
	0x01B0F0,
	0xB4B44B,
	0xB7A749,
	0xBA9A47,
	0xBD8D46,
	0xBD8D46,
	0xBD8D46,
	0xCBA46B,
	0xD8BB90,
	0xE5D2B5,
	0xFFFFFF,
	0xFFFFFF,
	0xFFFFFF,
};

/*
int degra[] = {
0x00FFFFFF,
0x00FFFFF7,
0x00FFFFEE,
0x00FFFFE6,
0x00FFFFDD,
0x00FFFFD5,
0x00FFFFCC,
0x00FFFFC4,
0x00FFFFBB,
0x00FFFFB3,
0x00FFFFAA,
0x00FFFFA2,
0x00FFFF99,
0x00FFFF91,
0x00FFFF88,
0x00FFFF80,
0x00FFFF77,
0x00FFFF6F,
0x00FFFF66,
0x00FFFF5E,
0x00FFFF55,
0x00FFFF4D,
0x00FFFF44,
0x00FFFF3C,
0x00FFFF33,
0x00FFFF2B,
0x00FFFF22,
0x00FFFF1A,
0x00FFFF11,
0x00FFFF09,
0x00FFFF00
*/
/*
int degra[] = {
	0xFFFFFF,
	0xB9121B,
	0xAEEE00,
};*/

int		moy(t_pt3d p1, t_pt3d p2)
{
	return ((p1.z + p2.z) / 2.0);
}

int		remap(int x, int inmi, int inma)
{
	return (x - inmi) * (14 - 0) / (inma - inmi) + 0;
}

void	draw_map_end1(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	x = 0;
	y = all->map.ly - 2;
	while (x < (all->map.lx - 2))
	{
		c1 = remap(moy(all->map.tab[x][y], all->map.tab[x + 1][y]),
			all->map.min, all->map.max);
		ft_draw_line3d_img(all->img, ft_3d_mul(all->map.tab[x][y], all->pad),
			ft_3d_mul(all->map.tab[x + 1][y], all->pad), ft_int_to_color(degra[c1]));
		x++;
	}
}

void	draw_map_end2(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	y = 0;
	x = all->map.lx - 2;
	while (y < (all->map.ly - 2))
	{
		c1 = remap(moy(all->map.tab[x][y], all->map.tab[x][y + 1]),
						all->map.min, all->map.max);
		ft_draw_line3d_img(all->img,
				ft_3d_mul(all->map.tab[x][y], all->pad),
				ft_3d_mul(all->map.tab[x][y + 1], all->pad),
				ft_int_to_color(degra[c1]));
		y++;
	}
}

#include <stdio.h>

void	draw_map(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;
	t_map	map;

	map = all->map;
	y = 0;
	while (y < (map.ly - 2))
	{
		x = 0;
		while (x < (map.lx - 2))
		{
			c1 = remap(moy(map.tab[x][y], map.tab[x + 1][y]), map.min, map.max);
			//printf("c1 = %d\n",c1);
			ft_draw_line3d_img(all->img, ft_3d_mul(map.tab[x][y], all->pad),
				ft_3d_mul(map.tab[x + 1][y], all->pad), ft_int_to_color(degra[c1]));
			c1 = remap(moy(map.tab[x][y], map.tab[x][y + 1]), map.min, map.max);
			ft_draw_line3d_img(all->img, ft_3d_mul(map.tab[x][y + 1], all->pad),
				ft_3d_mul(map.tab[x][y], all->pad), ft_int_to_color(degra[c1]));
			x++;
		}
		y++;
	}
	draw_map_end1(all);
	draw_map_end2(all);
}


