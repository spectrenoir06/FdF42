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
	unsigned char **tab;
	t_env			env;
	t_pt3d			origin;
	t_pt3d			x;
	t_pt3d			y;
	t_pt3d			z;
	t_pt3d			p1;
	t_pt3d			p2;
	t_pt3d			p3;
	t_pt3d			p4;
	t_pt3d			p5;
	t_pt3d			p6;
	t_pt3d			p7;
	t_pt3d			p8;

	t_pt3d			op1;
	t_pt3d			op2;
	t_pt3d			op3;
	t_pt3d			op4;
	t_pt3d			op5;
	t_pt3d			op6;
	t_pt3d			op7;
	t_pt3d			op8;

}	t_all;

void	draw_map(t_all *all)
{
	int x = 0;
	int y = 0;

	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			ft_draw_pixel(all->env, ft_new_point(x++,y), ft_rgb_to_color(0,0,all->tab[x][y] * 10));
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
	//draw_map(all);
	
	//ft_draw_pixel(all->env, ft_3d_to_2d(all->origin), ft_rgb_to_color(0,100,255));

	all->op1 = all->p1;
	all->op2 = all->p2;
	all->op3 = all->p3;
	all->op4 = all->p4;

	all->op5 = all->p5;
	all->op6 = all->p6;
	all->op7 = all->p7;
	all->op8 = all->p8;

	ft_draw_line3d(all->env, all->op1, all->op2, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op2, all->op3, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op3, all->op4, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op4, all->op1, ft_rgb_to_color(0,0,0));

	ft_draw_line3d(all->env, all->op1, all->op5, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op2, all->op6, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op3, all->op7, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op4, all->op8, ft_rgb_to_color(0,0,0));


	ft_draw_line3d(all->env, all->op5, all->op6, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op6, all->op7, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op7, all->op8, ft_rgb_to_color(0,0,0));
	ft_draw_line3d(all->env, all->op8, all->op5, ft_rgb_to_color(0,0,0));

	all->p1.x++;
	all->p2.x++;
	all->p3.x++;
	all->p4.x++;

	all->p5.x++;
	all->p6.x++;
	all->p7.x++;
	all->p8.x++;

	ft_draw_line3d(all->env, all->p1, all->p2, ft_rgb_to_color(255,0,0));
	ft_draw_line3d(all->env, all->p2, all->p3, ft_rgb_to_color(255,0,0));
	ft_draw_line3d(all->env, all->p3, all->p4, ft_rgb_to_color(255,0,0));
	ft_draw_line3d(all->env, all->p4, all->p1, ft_rgb_to_color(255,0,0));

	ft_draw_line3d(all->env, all->p1, all->p5, ft_rgb_to_color(0,255,0));
	ft_draw_line3d(all->env, all->p2, all->p6, ft_rgb_to_color(0,255,0));
	ft_draw_line3d(all->env, all->p3, all->p7, ft_rgb_to_color(0,255,0));
	ft_draw_line3d(all->env, all->p4, all->p8, ft_rgb_to_color(0,255,0));


	ft_draw_line3d(all->env, all->p5, all->p6, ft_rgb_to_color(0,0,255));
	ft_draw_line3d(all->env, all->p6, all->p7, ft_rgb_to_color(0,0,255));
	ft_draw_line3d(all->env, all->p7, all->p8, ft_rgb_to_color(0,0,255));
	ft_draw_line3d(all->env, all->p8, all->p5, ft_rgb_to_color(0,0,255));


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

	t_pt3d	p1 = {0,0,0};
	t_pt3d	p2 = {50,0,0};
	t_pt3d	p3 = {50,50,0};
	t_pt3d	p4 = {0,50,0};

	t_pt3d	p5 = {0,0,50};
	t_pt3d	p6 = {50,0,50};
	t_pt3d	p7 = {50,50,50};
	t_pt3d	p8 = {0,50,50};


	all.origin = origin;
	all.x		= x;
	all.y 		= y;
	all.z 		= z;

	all.p1 = p1;
	all.p2 = p2;
	all.p3 = p3;
	all.p4 = p4;

	all.p5 = p5;
	all.p6 = p6;
	all.p7 = p7;
	all.p8 = p8;


	
	/*unsigned char tab[5][5] = {	{0, 0, 0, 0, 0},
								{0, 3, 4, 5, 0},
								{0, 2, 0, 6, 0},
								{0, 1, 0, 7, 0},
								{0, 0, 0, 0, 0}
							};
	*/

	mlx_key_hook(env.win, key_press, &all);
	mlx_mouse_hook(env.win, mouse_press, &all);
	mlx_loop_hook(env.mlx, loop, &all);
	mlx_loop(env.mlx);
	return (0);
}