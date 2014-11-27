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
	draw_map(all);
	sleep(1);
	return (0);
}

int		main()
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	t_env	env = {mlx, win};
	t_all	all;
	all.env = env;
	
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