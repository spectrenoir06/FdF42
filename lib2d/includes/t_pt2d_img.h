/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt2d_img.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:08:45 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:08:50 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PT2D_H
# define T_PT2D_H

# include "lib2d.h"
# include "color.h"
# include "t_pt2d.h"

void				ft_draw_pixel2d_img(t_img img, t_pt2d p, t_color c);
void				ft_draw_line2d_img(t_img img, t_pt2d p1, t_pt2d p2, t_color c);
void				ft_draw_rect2d_img(t_img img, t_rect r, t_color c);

#endif
