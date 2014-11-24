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
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}	t_rect;



#endif
