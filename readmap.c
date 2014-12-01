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

void	list_to_map(t_all *all, t_list *lst)
{
	int		i;
	t_pt3d	point;
	t_list	*lsttmp;

	i = 0;
	lsttmp = lst;
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
		lst = lst->next;
	}
	ft_lstsimpledel(&lsttmp);
}