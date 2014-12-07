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
#include "../../main.h"

void		ft_draw_pixel3d(t_env env, t_pt3d p, t_color c)
{
	t_pt2d		t;

	t = ft_3d_to_2d(p, env);
	mlx_pixel_put(env.mlx, env.win, t.x, t.y, ft_color_to_int(c));
}

void		ft_draw_line3d(t_env env, t_pt3d p1, t_pt3d p2, t_color c)
{
	ft_draw_line2d(env, ft_3d_to_2d(p1, env), ft_3d_to_2d(p2, env), c);
}

t_pt3d		ft_new_point3d(int x, int y, int z)
{
	t_pt3d		t;

	t.x = x;
	t.y = y;
	t.z = z;
	return (t);
}

t_pt2d		ft_3d_to_2d(t_pt3d p, t_env env)
{
	t_pt2d		t;

	t.x = p.x - p.y + (SCREEN_SIZE_X / 2) + env.x;
	t.y = (-p.z) + (p.x / 2.0) + (p.y / 2.0) + env.y;
	return (t);
}

t_pt3d		ft_3d_mul(t_pt3d p, float k)
{
	p.x = p.x * k;
	p.y = p.y * k;
	return (p);
}
