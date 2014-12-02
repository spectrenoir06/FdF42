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

int		remap(int x, int inmi, int inma)
{
	return (x - inmi) * (255 - 0) / (inma - inmi) + 0;
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
		ft_draw_line3d(all->env, ft_3d_mul(all->map.tab[x][y], 8),
			ft_3d_mul(all->map.tab[x + 1][y], 8), ft_rgb(255, 255, 255 - c1));
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
		ft_draw_line3d(all->env,
				ft_3d_mul(all->map.tab[x][y], 8),
				ft_3d_mul(all->map.tab[x][y + 1], 8),
				ft_rgb(255, 255, 255 - c1));
		y++;
	}
}

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
			ft_draw_line3d(all->env, ft_3d_mul(map.tab[x][y], 20),
				ft_3d_mul(map.tab[x + 1][y], 20), ft_rgb(255, 255, 255 - c1));
			c1 = remap(moy(map.tab[x][y], map.tab[x][y + 1]), map.min, map.max);
			ft_draw_line3d(all->env, ft_3d_mul(map.tab[x][y + 1], 20),
				ft_3d_mul(map.tab[x][y], 20), ft_rgb(255, 255, 255 - c1));
			x++;
		}
		y++;
	}
	draw_map_end1(all);
	draw_map_end2(all);
}
