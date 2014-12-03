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
#include <time.h>
#include <math.h>
#include "libft.h"
#include "main.h"
#include "fdf.h"
#include "readmap.h"

int		mouse_press(int button, int x, int y, t_all *all)
{
	printf("%d , x = %d , y = %d\n", button, x, y);
	if (button == 4)
	{
		all->img.mult+=0.3;
		all->redraw=1;
	}
	if (button == 1)
	{
		all->pad++;
		//all->img.mult;
		all->redraw=1;
	}
	if (button == 3)
	{
		all->pad--;
		//all->img.mult--;
		all->redraw=1;
	}
	if (button == 5)
	{
		all->img.mult-=0.3;
		all->redraw=1;
	}
	return (0);
}

int		key_press(int keycode, t_all *all)
{
	printf("%d = %c\n", keycode, keycode);
	if (keycode == 'a')
		all->redraw = 1;
	return (0);
}

int		loop(t_all *all)
{
	if (all->redraw)
	{
		ft_bzero(all->img.data, all->img.lx * all->img.ly);
		draw_map(all);
		mlx_put_image_to_window(all->env.mlx, all->env.win, all->img.img, 0, 0);
		all->redraw = 0;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_list	*lst;

	lst = NULL;
	all.env.mlx = mlx_init();
	all.env.win = mlx_new_window(all.env.mlx,
		SCREEN_SIZE_X, SCREEN_SIZE_Y, "Fdf");
	all.map.max = 0;
	all.map.min = 0;
	if (argc > 1)
	{
		file_to_lst(argv[1], &all, &lst);
		list_to_map(&all, lst);
		all.img.img =  mlx_new_image(all.env.mlx, SCREEN_SIZE_X, SCREEN_SIZE_Y);
       	all.img.data = mlx_get_data_addr(all.img.img, &all.img.bpp, &all.img.lx, &all.img.endian);
       	all.img.ly = SCREEN_SIZE_Y;
       	all.redraw = 1;
       	all.img.mult = 10;
       	all.pad = 10;
       	printf("bpp = %d , lx = %d, endian = %d \n", all.img.bpp, all.img.lx, all.img.endian);
       	printf("max = %d , min = %d\n", all.map.max, all.map.min);
	}
	else
	{
		ft_putstr("pas de fichier\n");
		return (0);
	}
	mlx_key_hook(all.env.win, key_press, &all);
	mlx_mouse_hook(all.env.win, mouse_press, &all);
	mlx_loop_hook(all.env.mlx, loop, &all);
	mlx_loop(all.env.mlx);
	return (0);
}
