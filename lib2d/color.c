/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:19:33 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:19:35 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

int			ft_color_to_int(t_color c)
{
	int		i;

	i = c.r;
	i = i << 8;
	i += c.g;
	i = i << 8;
	i += c.b;
	return (i);
}

t_color		ft_int_to_color(int c)
{
	t_color i;

	c = (c & 0x00FFFFFF);
	i.b = (c & 0xFF);
	c = c >> 8;
	i.g = (c & 0xFF);
	c = c << 8;
	i.r = c;
	return (i);
}

t_color		ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	t_color t;

	t.r = r;
	t.g = g;
	t.b = b;
	return (t);
}
