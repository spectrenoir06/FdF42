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

void	file_to_lst(char *file, t_all *all, t_list **lst)
{
	char	**tmp;
	char	**tmp2;
	char	*line;
	t_pt3d	point;
	int		fd;

	all->map.ly = 0;
	fd = open(file, 'r');
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		tmp2 = tmp;
		free(line);
		all->map.lx = 0;
		while (*tmp)
		{
			point = ft_new_point3d(all->map.lx, all->map.ly, ft_atoi(*tmp));
			ft_lstsmartpushback(lst, ft_lstnew(&point, sizeof(t_pt3d)));
			free(*tmp);
			tmp++;
			all->map.lx++;
		}
		free(tmp2);
		all->map.ly++;
	}
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_list	*lst;
	t_list	*lsttmp;
	t_pt3d	point;
	int		x;
	int		y;
	int		i;
	lst = NULL;

	all.env.mlx = mlx_init();
	all.env.win = mlx_new_window(all.env.mlx, SCREEN_SIZE_X, SCREEN_SIZE_Y, "Hello world!");
	all.map.max = 0;
	all.map.min = 0;
	x = 0;
	y = 0;
	i = 0;
	if (argc > 1)
	{
		file_to_lst(argv[1], &all, &lst);
		x = all.map.lx;
		y = all.map.ly;
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
		ft_lstsimpledel(&lsttmp);
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
