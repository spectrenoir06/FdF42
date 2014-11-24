/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 10:25:22 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/24 20:11:25 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib2d.h"

int		colortoint(t_color c)
{
	int		i;

	i = c.r;
	i = i << 8;
	i += c.g;
	i = i << 8;
	i += c.b;
	return (i);
}

int		get_color(char r, char g, char b)
{
	int		i;

	i = r;
	i << 8;
	i += g;
	i << 8;
	i += b;
	return (i);
}

void	ft_putsquare(void *mlx, void *win, int x, int y, int lx, int ly, int c)
{
	int		x2;
	int		y2;

	x2 = x + lx;
	y2 = y + ly;

	while (x <= x2 && y <= y2)
	{
		mlx_pixel_put(mlx, win, x++, y, c);
		if (x >= x2)
		{
			x -= lx;
			y++;
		}
	}
}

void	ft_putpixel(t_env env, t_point p, t_color c)
{
	mlx_pixel_put(env.mlx, env.win, p.x, p.y, colortoint(c));
}

void ft_putline(t_env env, t_point p1, t_point p2, t_color c)
{
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	if ( dx > dy )
	{
		cumul = dx / 2 ;
		i = 1;
		while (i++ <= dx)
		{
			p1.x += xinc ;
			cumul += dy ;
			if (cumul >= dx)
			{
				cumul -= dx;
				p1.y += yinc;
			}
			ft_putpixel(env, p1, c);
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (i++ <= dy)
		{
			p1.y += yinc ;
			cumul += dx ;
			if ( cumul >= dy )
			{
				cumul -= dy;
				p1.x += xinc;
			}
			ft_putpixel(env, p1, c);
		}
	}
}

int		color_set_r(int color, char c)
{
	int i;
	i = c;
	color = color & (i<<8);
}

int		main()
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	t_env	env = {mlx, win};

	t_point		p1 = {10, 10};
	t_point		p2 = {300, 500};
	t_point		p3 = {200, 400};
	t_color		blue = {0, 0x99, 0xFF};

	printf("color = %d\n",colortoint(blue));

	while (1)
	{
		ft_putline(env, p1, p2, blue);
		ft_putline(env, p2, p3, blue);
		sleep(1);
		//line(env, p);
	}
}
