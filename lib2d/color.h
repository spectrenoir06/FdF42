/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:25:51 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:26:34 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "lib2d.h"

typedef struct		s_color
{
	t_byte			r;
	t_byte			g;
	t_byte			b;
}					t_color;

int			ft_color_to_int(t_color c);
t_color		ft_int_to_color(int c);
t_color		ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b);


#endif
