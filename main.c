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
	printf("Key = %d, %c\n", keycode, keycode);
	if (keycode >= '1' && keycode < '4')
		all->mode = keycode - '0';
	else if (keycode == '&')
		all->mode = 3;
	else if (keycode == 65307)
		quit(all);
	else if (keycode == 65364)
		all->env.y -= 30;
	else if (keycode == 65362)
		all->env.y += 30;
	else if (keycode == 65361)
		all->env.x += 30;
	else if (keycode == 65363)
		all->env.x -= 30;
	else if (keycode == 'r')
		init(all);
	else if (keycode == 'a')
		all->env.cst += 0.2;
	else if (keycode == 'q' && all->env.cst > 1.0)
		all->env.cst -= 0.2;
	all->redraw = 1;
	return (0);
}

int		loop(t_all *all)
{
	if (all->redraw)
	{
		ft_bzero(all->img.data, all->img.lx * all->img.ly);

		t_pt2d p3 = {500, 0};
		t_pt2d p2 = {1000, 500};
		t_pt2d p1 = {500, 600};
		t_color c = {0,100,255};
		//drawTriangle(all->img, p1, p2, p3, c);
		//fillBottomFlatTriangle(all->img, p1, p2, p3);
		if (all->mode > 1)
			draw_map_fill(all);
		else
			draw_map(all);
		mlx_put_image_to_window(all->env.mlx, all->env.win, all->img.img, 0, 0);
		mlx_string_put(all->env.mlx, all->env.win,
			SCREEN_SIZE_X / 2 - (ft_strlen(all->name) * 5 / 2), 20, 0xFFFFFF,
			all->name);
		mlx_string_put(all->env.mlx, all->env.win, 10, 20, 0xFFFFFF,
		"Button 1, 2, 3 = Change mode");
		mlx_string_put(all->env.mlx, all->env.win, 10, 40, 0xFFFFFF,
		"Mouse click = Zoom");
		mlx_string_put(all->env.mlx, all->env.win, 10, 60, 0xFFFFFF,
		"Arrows keys = Move");
		mlx_string_put(all->env.mlx, all->env.win, 10, 80, 0xFFFFFF,
		"r = reset");
		mlx_string_put(all->env.mlx, all->env.win, 10, 100, 0xFFFFFF,
		"a/q = rotation");
		all->redraw = 0;
	}
	return (0);
}

int		expose(t_all *all)
{
	mlx_put_image_to_window(all->env.mlx, all->env.win, all->img.img, 0, 0);
	mlx_string_put(all->env.mlx, all->env.win, 10, 20, 0xFFFFFF,
	"Button 1, 2, 3 = Change mode");
	mlx_string_put(all->env.mlx, all->env.win, 10, 40, 0xFFFFFF,
	"Mouse click = Zoom");
	mlx_string_put(all->env.mlx, all->env.win, 10, 60, 0xFFFFFF,
	"Arrows keys = Move");
	mlx_string_put(all->env.mlx, all->env.win, 10, 80, 0xFFFFFF,
	"r = reset");
	mlx_string_put(all->env.mlx, all->env.win, 10, 100, 0xFFFFFF,
	"a/q = rotation");
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;

	all.env.mlx = mlx_init();
	all.env.win = mlx_new_window(all.env.mlx,
		SCREEN_SIZE_X, SCREEN_SIZE_Y, "Fdf");
	all.map.max = 1;
	all.map.min = 0;
	all.mode = 1;
	if (argc == 2)
	{
		getmap(argv[1], &all);
		all.img.img = mlx_new_image(all.env.mlx, SCREEN_SIZE_X, SCREEN_SIZE_Y);
		all.img.data = mlx_get_data_addr(all.img.img, &all.img.bpp,
			&all.img.lx, &all.img.endian);
		fill_palette(all.palette);
		mlx_key_hook(all.env.win, key_press, &all);
		mlx_mouse_hook(all.env.win, mouse_press, &all);
		mlx_loop_hook(all.env.mlx, loop, &all);
		mlx_expose_hook (all.env.win, expose, &all);
		mlx_loop(all.env.mlx);
	}
	else
		ft_putstr_fd("usage: ./fdf <map.fdf>\n", 2);
	return (0);
}
