/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt2d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:08:45 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:08:50 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PT2D_H
# define T_PT2D_H

#include "lib2d.h"

typedef struct		s_pt2d
{
	int				x;
	int				y;
}					t_pt2d;

typedef struct		s_rect
{
	t_pt2d			p1;
	t_pt2d			p2;
}					t_rect;

typedef struct		s_line
{
	t_pt2d			p1;
	t_pt2d			p2;
	t_color			c1;
	t_color			c2;
	t_pt2d			inc;
	int				dx;
	int				dy;
}					t_line;

void		ft_draw_pixel(t_env env, t_pt2d p, t_color c);
void		ft_draw_line2d(t_env env, t_pt2d p1, t_pt2d p2, t_color c);
void		ft_draw_rect2d(t_env env, t_rect r, t_color c);
t_rect		ft_new_rect(t_pt2d p1, t_pt2d p2);

#endif