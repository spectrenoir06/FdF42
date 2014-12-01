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

void	file_to_lst(char *file, t_all *all, t_list **lst);
void	list_to_map(t_all *all, t_list *lst);

#endif
