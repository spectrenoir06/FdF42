/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:03:39 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:03:40 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

void		ft_draw_pixel2d_img(t_img img, t_pt2d p, t_color c)
{
	unsigned int i;

	i = ft_color_to_int(c);
	if (p.x > 0 && p.x <= img.lx && p.y > 0 && p.y <= img.ly)
		ft_memcpy((img.data + (p.x * 4) + (p.y * img.lx)), &i,
			(size_t)sizeof(int));
}

void		ft_draw_rect2d_img(t_img img, t_rect r, t_color c)
{
	int		lx;

	lx = r.p2.x - r.p1.x;
	while (r.p1.x <= r.p2.x && r.p1.y <= r.p2.y)
	{
		ft_draw_pixel2d_img(img, r.p1, c);
		if (++r.p1.x >= r.p2.x)
		{
			r.p1.x -= lx;
			r.p1.y++;
		}
	}
}