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

typedef struct s_all
{
	t_env			env;
	t_pt3d			**tab;

}	t_all;

int rand_a_b(int a, int b)
{
    return rand()%(b-a) +a;
}


void	draw_map(t_all *all)
{
	int x = 0;
	int y = 0;

	while (y < 10)
	{
		x = 0;
		while (x < 17)
		{
			//ft_draw_pixel3d(all->env, t_pt3d	ft_point3d_mul(t_pt3d p, int k)all->tab[x][y], ft_rgb_to_color(0,255, 100));
			ft_draw_line3d(all->env, ft_point3d_mul(all->tab[x][y], 20), ft_point3d_mul(all->tab[x + 1][y], 20), ft_rgb_to_color(0,255, 100));
			ft_draw_line3d(all->env, ft_point3d_mul(all->tab[x][y+1], 20), ft_point3d_mul(all->tab[x][y], 20), ft_rgb_to_color(0,255, 100));
			x++;
		}
		y++;
	}
}
/*
int		mouse_press(int button, int x, int y, t_all *all)
{
	return (0);
}

int		key_press(int keycode, t_all*	all)
{
	printf("%d = %c\n", keycode, keycode);
	return (0);
}
*/
int		loop(t_all	*all)
{

	draw_map(all);

	/*t_list	*lst = all->lst;
	t_pt3d pt;

	while (lst)
	{
		pt = *(t_pt3d *)lst->content;
		pt.x = pt.x * 20;
		pt.y = pt.y *10;
		ft_draw_pixel3d(all->env, pt, ft_rgb_to_color(0,255,100));
		lst = lst->next;
	}

	//ft_draw_pixel(all->env, ft_3d_to_2d(all->origin), ft_rgb_to_color(0,100,255));
*/
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
			t[x][y] = ft_new_point3d(x * 20 + 300,y * 20, (cos(x / 10.0 ) + cos(y / 10.0 )) * 100);
			x++;
		}
		y++;
	}

}

int		main(int argc, char **argv)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 500, 500, "Hello world!");
	t_env	env = {mlx, win};
	t_all	all;
	all.env = env;

	t_list	*lst = NULL;

	//gen(all.tab);
	char *line;
	char **tab;
	t_pt3d point;
	
	int x = 0;
	int y = 0;
	int i = 0;
	printf("argc = %d\n",argc);
	if (argc > 1)
	{
		int fd = open(argv[1] ,'r');
		while (get_next_line(fd, &line))
		{
			tab = ft_strsplit(line, ' ');
			x = 0;
			while (*tab)
			{
				point = ft_new_point3d(x,y,ft_atoi(*tab));
				//printf("<%s>\n",*tab);
				//printf("%d %d %d \n",point.x, point.y , point.z);
				ft_lstsmartpushback(&lst, ft_lstnew(&point, sizeof(t_pt3d)));
				tab++;
				x++;
			}
			y++;
		}

		printf("%d %d\n", x , y);

		t_pt3d **tab;

		tab = (t_pt3d **)malloc(sizeof(t_pt3d *) * x);
		while (i < x)
			tab[i++] = malloc(sizeof(t_pt3d) * y);


		while (lst)
		{
			point = *((t_pt3d *)lst->content);
			printf("%d %d = %d\n" ,point.x, point.y, point.z);
			tab[point.x][point.y] = point;
			lst = lst->next;
		}
		printf("fini\n");
		all.tab = tab;

	}
	else
		ft_putstr("pas de fichier\n");

	//mlx_key_hook(env.win, key_press, &all);
	//mlx_mouse_hook(env.win, mouse_press, &all);
	mlx_loop_hook(env.mlx, loop, &all);
	mlx_loop(env.mlx);
	return (0);
}