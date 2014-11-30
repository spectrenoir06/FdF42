/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:28:14 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:28:15 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PT3D_H
# define T_PT3D_H

# include "lib2d.h"

typedef struct		s_pt3d
{
	int				x;
	int				y;
	int				z;
}					t_pt3d;

t_pt3d				ft_new_point3d(int x, int y, int z);
void				ft_draw_line3d(t_env env, t_pt3d p1, t_pt3d p2, t_color c);
void				ft_draw_pixel3d(t_env env, t_pt3d p, t_color c);
t_pt3d				ft_point3d_mul(t_pt3d p, int k);
t_pt2d				ft_3d_to_2d(t_pt3d p);

#endif