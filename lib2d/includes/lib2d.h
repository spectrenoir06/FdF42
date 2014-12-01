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

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# include "color.h"
# include "t_pt2d.h"
# include "t_pt3d.h"
# include "line.h"

# define SCREEN_SIZE_X 1280
# define SCREEN_SIZE_Y 720

typedef unsigned char	t_byte;
typedef unsigned char	t_uint8;
typedef unsigned short	t_uint16;
typedef unsigned long	t_uint32;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

#endif
