/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt3d_img.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:28:14 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 18:28:15 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PT3D_H
# define T_PT3D_H

# include "lib2d.h"
# include "t_pt3d.h"
# include "t_pt2d.h"
# include "color.h"

void				ft_draw_line3d_img(t_env env, t_pt3d p1, t_pt3d p2, t_color c);
void				ft_draw_pixel3d_img(t_env env, t_pt3d p, t_color c);
#endif
