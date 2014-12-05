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
	return (x - inmi) * (14 - 0) / (inma - inmi) + 0;
}

void	draw_map_h(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	x = 0;
	y = 0;
	while (y < (all->map.ly - 1))
	{
		x = 0;
		while (x < (all->map.lx - 2))
		{
			c1 = remap(moy(all->map.tab[x][y], all->map.tab[x + 1][y]),
			all->map.min, all->map.max);
			ft_draw_line3d_img(all->img,
			ft_3d_mul(all->map.tab[x][y], all->pad),
			ft_3d_mul(all->map.tab[x + 1][y], all->pad),
			ft_int_to_color(all->palette[c1]));
			x++;
		}
		y++;
	}
}

void	draw_map_v(t_all *all)
{
	int		x;
	int		y;
	t_byte	c1;

	x = 0;
	while (x < (all->map.lx - 1))
	{
		y = 0;
		while (y < (all->map.ly - 2))
		{
			c1 = remap(moy(all->map.tab[x][y], all->map.tab[x][y + 1]),
				all->map.min, all->map.max);
			ft_draw_line3d_img(all->img,
				ft_3d_mul(all->map.tab[x][y], all->pad),
				ft_3d_mul(all->map.tab[x][y + 1], all->pad),
				ft_int_to_color(all->palette[c1]));
			y++;
		}
		x++;
	}
}

void	draw_map(t_all *all)
{
	draw_map_h(all);
	draw_map_v(all);
}
