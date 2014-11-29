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

void	draw_map(t_all *all)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 18)
		{
			ft_draw_line3d(all->env, ft_point3d_mul(all->tab[x][y], 20),
				ft_point3d_mul(all->tab[x + 1][y], 20),
				ft_rgb_to_color(0, 255, 100));
			ft_draw_line3d(all->env, ft_point3d_mul(all->tab[x][y + 1], 20),
				ft_point3d_mul(all->tab[x][y], 20),
				ft_rgb_to_color(0, 255, 100));
			x++;
		}
		y++;
	}
}

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
	usleep(5000);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_list	*lst;
	char	*line;
	char	**tmp;
	t_pt3d	**tab;
	t_pt3d	point;
	int x;
	int y;
	int i;
	int fd;

	all.env.mlx = mlx_init();
	all.env.win = mlx_new_window(all.env.mlx, 500, 500, "Hello world!");
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
			x = 0;
			while (*tmp)
			{
				point = ft_new_point3d(x, y, ft_atoi(*tmp));
				ft_lstsmartpushback(&lst, ft_lstnew(&point, sizeof(t_pt3d)));
				tmp++;
				x++;
			}
			y++;
		}
		tab = (t_pt3d **)malloc(sizeof(t_pt3d *) * x);
		while (i < x)
			tab[i++] = malloc(sizeof(t_pt3d) * y);
		while (lst)
		{
			point = *((t_pt3d *)lst->content);
			point.z = -point.z;
			tab[point.x][point.y] = point;
			lst = lst->next;
		}
		all.tab = tab;
	}
	else
		ft_putstr("pas de fichier\n");
	mlx_key_hook(all.env.win, key_press, &all);
	mlx_mouse_hook(all.env.win, mouse_press, &all);
	mlx_loop_hook(all.env.mlx, loop, &all);
	mlx_loop(all.env.mlx);
	return (0);
}
