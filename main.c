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

typedef struct s_all
{
	t_env			env;
	t_pt3d			origin;
	t_pt3d			x;
	t_pt3d			y;
	t_pt3d			z;

	t_pt3d			tab[100][100];

}	t_all;

int rand_a_b(int a, int b)
{
    return rand()%(b-a) +a;
}


void	draw_map(t_all *all)
{
	int x = 0;
	int y = 0;

	while (y < 99)
	{
		x = 0;
		while (x < 99)
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

void	gen(t_pt3d t[][100])
{
	int x = 0;
	int y = 0;

	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			printf("%f\n", cos(x));
			t[x++][y] = ft_new_point3d(x * 20 + 300,y * 20, (cos(x / 10.0 ) + cos(y / 10.0 )) * 100);
;
		}
		y++;
	}

}

int		main()
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 2560, 1440, "Hello world!");
	t_env	env = {mlx, win};
	t_all	all;
	all.env = env;
	t_pt3d	origin = {100,100,100};
	t_pt3d	x = {200,100,100};
	t_pt3d	y = {100,0,100};
	t_pt3d	z = {100,100,200};


	all.origin = origin;
	all.x		= x;
	all.y 		= y;
	all.z 		= z;

	gen(all.tab);

	/*all.tab[5][5].z = -12;
	all.tab[5][6].z = -12;
	all.tab[6][6].z = -12;
	all.tab[6][5].z = -12;*/



	

	mlx_key_hook(env.win, key_press, &all);
	mlx_mouse_hook(env.win, mouse_press, &all);
	mlx_loop_hook(env.mlx, loop, &all);
	mlx_loop(env.mlx);
	return (0);
}