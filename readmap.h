/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 20:35:26 by adoussau          #+#    #+#             */
/*   Updated: 2014/12/01 20:36:00 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READMAP_H
# define READMAP_H
# include "main.h"

void	fill_pallette(int tab[15]);
void    getmap(char *file, t_all *all);
void    init(t_all *all);
void	fill_palette(int tab[30]);

#endif
