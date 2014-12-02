/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:03:49 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:03:51 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

void		ft_draw_pixel3d_img(t_img img, t_pt3d p, t_color c)
{
	t_pt2d		t;

	p.z *= img.mult;
	t = ft_3d_to_2d(p);
	ft_draw_pixel2d_img(img, t, c);
}

void		ft_draw_line3d_img(t_img img, t_pt3d p1, t_pt3d p2, t_color c)
{
	p1.z *= img.mult;
	p2.z *= img.mult;
	ft_draw_line2d_img(img, ft_3d_to_2d(p1), ft_3d_to_2d(p2), c);
}
