/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 10:25:22 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/24 13:47:20 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <math.h>

typedef struct s_color
{
	char	r;
	char	g;
	char	b;
}	t_color;

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

void	ft_putpixel(void *mlx, void *win, int x, int y, char r, char g, char b)
{
	int i;
	
	i = r;
	i = i << 8;
	i += g;
	i = i << 8;
	i += b;
	mlx_pixel_put(mlx, win, x, y, get_color(r, g, b));
}

void	ft_putline(void *mlx, void *wi, int x1, int y1, int x2 ,int y2 , int c)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	int		lx;
	int		ly;
	int		longueur;

	lx = x2 - x1;
	ly = y2 - y1;

	longueur = sqrt(pow(lx, 2) + pow (ly, 2));
	printf("%d\n", longueur);

	dx = longueur / lx;
	dy = longueur / ly;

	printf("%f , %f\n", dx, dy);

	while (x < lx && y < ly)
	{
		x += dx;
		y += dy;
		mlx_pixel_put(mlx, wi, x + x1, y + y1, c);
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
		//ft_putsquare(mlx, win, 10, 10, 100, 200, 255<<16);
		ft_putline(mlx , win , 50, 0, 100, 100, 255);
		ft_putline(mlx , win , 100, 100, 300, 300, 255);
	}
}
