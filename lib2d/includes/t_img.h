/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_img.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 14:37:31 by adoussau          #+#    #+#             */
/*   Updated: 2014/12/02 14:37:32 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_IMG_H
# define T_IMG_H

typedef struct s_img
{
	char		*data;
	void		*img;
	int			bpp;
	int			lx;
	int			ly;
	int			endian;
}				t_img;

#endif
