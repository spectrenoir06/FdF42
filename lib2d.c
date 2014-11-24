/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 10:25:22 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/24 17:18:43 by adoussau         ###   ########.fr       */
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
	i << 4;
	i += c.g;
	i << 4;
	i += c.b;
	return (i);
}

int		get_color(char r, char g, char b)
{
	int		i;

	i = r;
	i << 4;
	i += g;
	i << 4;
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

void ft_line(t_env env, t_point p1, t_point p2, int c)
{
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;

	dx = p1.x - p1.x;
	dy = p2.y - y1;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(mlx, win, x1, y1, c);
	if ( dx > dy )
	{
		cumul = dx / 2 ;
		i = 1;
		while (i++ <= dx)
		{
			x1 += xinc ;
			cumul += dy ;
			if (cumul >= dx)
			{
				cumul -= dx;
				y1 += yinc;
			}
			mlx_pixel_put(mlx, win, x1, y1, c);
		}
	}
	else
	{
		cumul = dy / 2 ;
		while (i++ <= dy)
		{
			y1 += yinc ;
			cumul += dx ;
			if ( cumul >= dy )
			{
				cumul -= dy;
				x1 += xinc;
			}
			mlx_pixel_put(mlx, win, x1, y1, c);
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

	int		x = 0;
	int		y = 0;
	int		dx = 1;
	int		dy = 1;
	unsigned char	r = 0;
	unsigned char	g = 0;
	unsigned char	b = 0;

	while (1)
	{
		ligne(mlx, win, 10, 10, 500, 300, 255);
		sleep(1);
		ligne(mlx, win, 500, 300, 600, 600, 255);
		sleep(10);
	}
}
