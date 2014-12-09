/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 20:28:12 by adoussau          #+#    #+#             */
/*   Updated: 2014/12/01 20:28:23 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "lib2d.h"
#include "libft.h"
#include "readmap.h"

void		init(t_all *all)
{
	all->img.ly = SCREEN_SIZE_Y;
	all->redraw = 1;
	all->img.mult = 1;
	all->pad = 30;
	all->env.x = 0;
	all->env.y = 0;
	all->img.env = &all->env;
	all->env.cst = 2.0;
}

int			file_to_lst(int fd, t_all *all, t_list **lst)
{
	char	**tmp;
	char	**tmp2;
	char	*line;
	t_pt3d	point;
	int		ret;

	all->map.ly = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (0);
		tmp = ft_strsplit(line, ' ');
		tmp2 = tmp;
		free(line);
		all->map.lx = 0;
		while (*tmp)
		{
			point = ft_new_point3d(all->map.lx++, all->map.ly, ft_atoi(*tmp));
			ft_lstsmartpushback(lst, ft_lstnew(&point, sizeof(t_pt3d)));
			free(*tmp++);
		}
		free(tmp2);
		all->map.ly++;
	}
	return (1);
}

void		list_to_map(t_all *all, t_list *lst)
{
	int		i;
	t_pt3d	point;
	t_list	*lsttmp;

	i = 0;
	all->map.tab = (t_pt3d **)malloc(sizeof(t_pt3d *) * all->map.lx);
	while (i < all->map.lx)
		all->map.tab[i++] = malloc(sizeof(t_pt3d) * all->map.ly);
	while (lst)
	{
		point = *((t_pt3d *)lst->content);
		if (all->map.min > point.z)
			all->map.min = point.z;
		if (all->map.max < point.z)
			all->map.max = point.z;
		all->map.tab[point.x][point.y] = point;
		lsttmp = lst;
		lst = lst->next;
		ft_lstsimpledelone(&lsttmp);
	}
}

void		getmap(char *file, t_all *all)
{
	t_list	*lst;
	int		fd;

	all->name = file;
	lst = NULL;
	if ((fd = open(file, 'r')) == -1)
	{
		ft_putstr_fd("fdf: Map does not exist or is invalid\n", 2);
		exit(0);
	}
	if (!file_to_lst(fd, all, &lst))
	{
		ft_putstr_fd("fdf: Map is a directory\n", 2);
		exit(0);
	}
	list_to_map(all, lst);
	init(all);
}
