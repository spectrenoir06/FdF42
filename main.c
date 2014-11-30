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

int MULTI = 5;

int moy(int x1, int y1, int x2, int y2, t_pt3d **map)
{
	return ((map[x1][y1].z + map[x2][y2].z) / 2.0);
}

int map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void	draw_map(t_all *all)
{
	int x;
	int y;

	x = 0;
	y = 0;

	unsigned char c1;
	while (y < (all->map.ly - 2))
	{
		x = 0;
		while (x < (all->map.lx - 2))
		{
			c1 = map(moy(x, y, x + 1, y, all->map.tab), all->map.min, all->map.max, 0, 255);
			ft_draw_line3d(all->env,
				ft_point3d_mul(all->map.tab[x][y], MULTI),
				ft_point3d_mul(all->map.tab[x + 1][y], MULTI),
				ft_rgb_to_color(255, 200, 255 - c1));
			c1 = map(moy(x, y, x, y + 1, all->map.tab), all->map.min, all->map.max, 0, 255);
			ft_draw_line3d(all->env,
				ft_point3d_mul(all->map.tab[x][y + 1], MULTI),
				ft_point3d_mul(all->map.tab[x][y], MULTI),
				ft_rgb_to_color(255, 200 , 255 - c1));
			x++;
		}
		y++;
	}
	x = 0;
	while (x < (all->map.lx - 2))
	{
		c1 = map(moy(x, y, x + 1, y, all->map.tab), all->map.min, all->map.max, 0, 255);
		ft_draw_line3d(all->env,
				ft_point3d_mul(all->map.tab[x][y], MULTI),
				ft_point3d_mul(all->map.tab[x + 1][y], MULTI),
				ft_rgb_to_color(250, 200, 255 - c1));
		x++;
	}
	y = 0;
	while (y < (all->map.ly - 2))
	{
		c1 = map(moy(x, y, x, y + 1, all->map.tab), all->map.min, all->map.max, 0, 255);
		ft_draw_line3d(all->env,
				ft_point3d_mul(all->map.tab[x][y], 20),
				ft_point3d_mul(all->map.tab[x][y + 1], 20),
				ft_rgb_to_color(250, 200, 255 - c1));
		y++;
	}
}

int		mouse_press(int button, int x, int y, t_all *all)
{
	(void)all;
	printf("%d , x = %d , y = %d\n", button, x, y);
	if (button == 5)
		MULTI++;
	if (button == 4)
		MULTI--;
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
	//usleep(5000);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_list	*lst;
	t_list	*lsttmp;
	char	*line;
	char	**tmp;
	char	**tmp2;

	t_pt3d	point;
	int x;
	int y;
	int i;
	int fd;

	all.env.mlx = mlx_init();
	all.env.win = mlx_new_window(all.env.mlx, 2560, 1440, "Hello world!");
	all.map.max = 0;
	all.map.min = 0;
	lst = NULL;
	x = 0;
	y = 0;
	i = 0;
	printf("argc = %d\n", argc);
	if (argc > 1)
	{
		fd = open(argv[1], 'r');
		while (get_next_line(fd, &line))
		{
			tmp = ft_strsplit(line, ' ');
			tmp2 = tmp;
			free(line);
			x = 0;
			while (*tmp)
			{
				point = ft_new_point3d(x, y, ft_atoi(*tmp));
				ft_lstsmartpushback(&lst, ft_lstnew(&point, sizeof(t_pt3d)));
				free(*tmp);
				tmp++;
				x++;
			}
			free(tmp2);
			y++;
		}
		lsttmp = lst;
		all.map.tab = (t_pt3d **)malloc(sizeof(t_pt3d *) * x);
		while (i < x)
			all.map.tab[i++] = malloc(sizeof(t_pt3d) * y);
		while (lst)
		{
			point = *((t_pt3d *)lst->content);
			if (all.map.min > point.z)
				all.map.min = point.z;
			if (all.map.max < point.z)
				all.map.max = point.z;
			all.map.tab[point.x][point.y] = point;
			lst = lst->next;
		}
		printf("x = %d, y = %d\n",x,y);
		printf("max = %d, min = %d\n",all.map.max,all.map.min);
		ft_lstsimpledel(&lsttmp);
		all.map.lx = x;
		all.map.ly = y;
	}
	else
		ft_putstr("pas de fichier\n");
	mlx_key_hook(all.env.win, key_press, &all);
	mlx_mouse_hook(all.env.win, mouse_press, &all);
	mlx_loop_hook(all.env.mlx, loop, &all);
	mlx_loop(all.env.mlx);
	return (0);
}
