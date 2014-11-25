/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 16:18:43 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/24 19:13:50 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB2D_H
# define LIB2D_H

typedef struct s_env
{
	void	*mlx;
	void	*win;
}	t_env;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_rect
{
	t_point		p1;
	t_point		p2;
}	t_rect;

int		ft_colortoint(t_color c);
void	ft_putsquare(void *mlx, void *win, int x, int y, int lx, int ly, int c);
void	ft_putpixel(t_env env, t_point p, t_color c);
void 	ft_putline(t_env env, t_point p1, t_point p2, t_color c);

#endif
