/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:37:23 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/25 17:37:26 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"
#include <stdio.h>
#include "libft.h"
#include "main.h"
#include "draw_map.h"
#include "draw_map_fill.h"
#include "readmap.h"

int		mouse_press(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == 4)
		all->img.mult++;
	else if (button == 1)
	{
		all->pad++;
		all->img.mult++;
	}
	else if (button == 3)
	{
		all->pad--;
		if (all->img.mult)
			all->img.mult--;
	}
	else if (button == 5)
		if (all->img.mult)
			all->img.mult--;
	all->redraw = 1;
	return (0);
}

int		key_press(int keycode, t_all *all)
{
	if (keycode == '1')
	{
		all->mode = 1;
		all->redraw = 1;
	}
	else if (keycode == '2')
	{
		all->mode = 2;
		all->redraw = 1;
	}
	else if (keycode == '3')
	{
		all->mode = 3;
		all->redraw = 1;
	}
	else if (keycode == 65307)
		exit(0);
	return (0);
}

int		loop(t_all *all)
{
	if (all->redraw)
	{
		ft_bzero(all->img.data, all->img.lx * all->img.ly);
		if (all->mode > 1)
			draw_map_fill(all);
		else
			draw_map(all);
		mlx_put_image_to_window(all->env.mlx, all->env.win, all->img.img, 0, 0);
		mlx_string_put(all->env.mlx, all->env.win, 10, 20, 0xFFFFFF,
		"Bouton 1, 2, 3 = changer de mode");
		mlx_string_put(all->env.mlx, all->env.win, 10, 40, 0xFFFFFF,
		"Click souris = zoom");
		all->redraw = 0;
	}
	return (0);
}

int		expose(t_all *all)
{
	mlx_put_image_to_window(all->env.mlx, all->env.win, all->img.img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_list	*lst;

	all.env.mlx = mlx_init();
	all.env.win = mlx_new_window(all.env.mlx,
		SCREEN_SIZE_X, SCREEN_SIZE_Y, "Fdf");
	all.map.max = 0;
	all.map.min = 0;
	all.mode = 1;
	if (argc > 1)
	{
		file_to_lst(argv[1], &all, &lst);
		all.img.img = mlx_new_image(all.env.mlx, SCREEN_SIZE_X, SCREEN_SIZE_Y);
		all.img.data = mlx_get_data_addr(all.img.img, &all.img.bpp,
			&all.img.lx, &all.img.endian);
		fill_pallette(all.palette);
		mlx_key_hook(all.env.win, key_press, &all);
		mlx_mouse_hook(all.env.win, mouse_press, &all);
		mlx_loop_hook(all.env.mlx, loop, &all);
		mlx_expose_hook (all.env.win, expose, &all);
		mlx_loop(all.env.mlx);
	}
	else
		ft_putstr("pas de fichier\n");
	return (0);
}
