/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 20:09:54 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/28 20:10:15 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "lib2d.h"

typedef struct	s_map
{
	int			lx;
	int			ly;
	t_pt3d		**tab;
	int			max;
	int			min;
}				t_map;

typedef struct	s_all
{
	t_env		env;
	t_map		map;
	t_img		img;
	int			redraw;
	float		pad;
	int			mode;
	int			palette[15];
	int			x;
	int			y;
}				t_all;

#endif
