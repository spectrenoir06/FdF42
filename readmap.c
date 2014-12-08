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

void	init(t_all *all)
{
	all->img.ly = SCREEN_SIZE_Y;
	all->redraw = 1;
	all->img.mult = 1;
	all->pad = 30;
	all->env.x = 0;
	all->env.y = 0;
	all->img.env = &all->env;
}

void	file_to_lst(char *file, t_all *all, t_list **lst)
{
	char	**tmp;
	char	**tmp2;
	char	*line;
	t_pt3d	point;
	int		fd;

	*lst = NULL;
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
			point = ft_new_point3d(all->map.lx++, all->map.ly, ft_atoi(*tmp));
			ft_lstsmartpushback(lst, ft_lstnew(&point, sizeof(t_pt3d)));
			free(*tmp++);
		}
		free(tmp2);
		all->map.ly++;
	}
	list_to_map(all, *lst);
}

void	list_to_map(t_all *all, t_list *lst)
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
	init(all);
}

void	fill_pallette(int tab[15])
{
	tab[0] = 0x31698A;
	tab[1] = 0x2181AC;
	tab[2] = 0x1199CE;
	tab[3] = 0x01B0F0;
	tab[4] = 0xB4B44B;
	tab[5] = 0xB7A749;
	tab[6] = 0xBA9A47;
	tab[7] = 0xC29654;
	tab[8] = 0xC59A5C;
	tab[9] = 0xC89F63;
	tab[10] = 0xCBA46B;
	tab[11] = 0xD8BB90;
	tab[12] = 0xE5D2B5;
	tab[13] = 0xFFFFFF;
	tab[14] = 0xFFFFFF;
}
