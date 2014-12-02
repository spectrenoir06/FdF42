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
#include "color.h"
#include "t_pt2d.h"
#include "t_pt3d.h"
#include "t_pt2d_img.h"
#include "t_pt3d_img.h"
#include "line.h"
#include "t_img.h"

int		mouse_press(int button, int x, int y, t_all *all)
{
	(void)all;
	printf("%d , x = %d , y = %d\n", button, x, y);
	return (0);
}

int		key_press(int keycode, t_all *all)
{
	(void)all;
	printf("%d = %c\n", keycode, keycode);
	return (0);
}

int		loop(t_all *all)
{
	draw_map(all);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_list	*lst;
	t_img	img;

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
		img.img =  mlx_new_image(all.env.mlx, SCREEN_SIZE_X, SCREEN_SIZE_Y);
       	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.lx, &img.endian);
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
