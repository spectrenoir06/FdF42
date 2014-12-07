/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:19:58 by adoussau          #+#    #+#             */
/*   Updated: 2014/12/01 15:20:03 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MAP_H
# define DRAW_MAP_H

# include "lib2d.h"

void	draw_map(t_all *all);
int		moy(t_pt3d p1, t_pt3d p2);
int		remap(int x, int inmi, int inma);

#endif
