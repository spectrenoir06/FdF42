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

typedef struct s_all
{
	t_env			env;
	t_pt3d			origin;
	t_pt3d			x;
	t_pt3d			y;
	t_pt3d			z;

	t_pt3d			tab[4][4];

}	t_all;

void	draw_map(t_all *all)
{
	int x = 0;
	int y = 0;

	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			ft_draw_pixel3d(all->env, all->tab[x][y], ft_rgb_to_color(0,255, 100));
			ft_draw_line3d(all->env, all->tab[x][y], all->tab[x + 1][y], ft_rgb_to_color(0,255, 100));
			ft_draw_line3d(all->env, all->tab[x][y+1], all->tab[x][y], ft_rgb_to_color(0,255, 100));
			x++;
		}
		y++;
	}
}

int		mouse_press(int button, int x, int y, t_all *all)
{
	return (0);
}

int		key_press(int keycode, t_all*	all)
{
	printf("%d = %c\n", keycode, keycode);
	return (0);
}

int		loop(t_all	*all)
{
	draw_map(all);
	
	//ft_draw_pixel(all->env, ft_3d_to_2d(all->origin), ft_rgb_to_color(0,100,255));

	ft_draw_line3d(all->env, all->origin, all->x, ft_rgb_to_color(0,0,255));
	ft_draw_line3d(all->env, all->origin, all->y, ft_rgb_to_color(0,255,0));
	ft_draw_line3d(all->env, all->origin, all->z, ft_rgb_to_color(255,0,0));

	usleep(5000);
	return (0);
}

int		main()
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	t_env	env = {mlx, win};
	t_all	all;
	all.env = env;
	t_pt3d	origin = {100,100,100};
	t_pt3d	x = {200,100,100};
	t_pt3d	y = {100,0,100};
	t_pt3d	z = {100,100,200};

	t_pt3d	p1 = {100,0,0};
	t_pt3d	p2 = {120,0,0};
	t_pt3d	p3 = {140,0,0};
	t_pt3d	p4 = {160,0,0};

	t_pt3d	p5 = {100,20,0};
	t_pt3d	p6 = {120,20,0};
	t_pt3d	p7 = {140,20,0};
	t_pt3d	p8 = {160,20,0};

	t_pt3d	p9 = {100,40,0};
	t_pt3d	p10 = {120,40,-5};
	t_pt3d	p11 = {140,40,0};
	t_pt3d	p12 = {160,40,0};

	t_pt3d	p13 = {100,60,0};
	t_pt3d	p14 = {120,60,0};
	t_pt3d	p15 = {140,60,0};
	t_pt3d	p16 = {160,60,0};

	all.tab[0][0] = p1;
	all.tab[1][0] = p2;
	all.tab[2][0] = p3;
	all.tab[3][0] = p4;

	all.tab[0][1] = p5;
	all.tab[1][1] = p6;
	all.tab[2][1] = p7;
	all.tab[3][1] = p8;

	all.tab[0][2] = p9;
	all.tab[1][2] = p10;
	all.tab[2][2] = p11;
	all.tab[3][2] = p12;

	all.tab[0][3] = p13;
	all.tab[1][3] = p14;
	all.tab[2][3] = p15;
	all.tab[3][3] = p16;

	all.origin = origin;
	all.x		= x;
	all.y 		= y;
	all.z 		= z;



	

	mlx_key_hook(env.win, key_press, &all);
	mlx_mouse_hook(env.win, mouse_press, &all);
	mlx_loop_hook(env.mlx, loop, &all);
	mlx_loop(env.mlx);
	return (0);
}