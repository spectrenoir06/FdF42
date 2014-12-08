/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:48:38 by adoussau          #+#    #+#             */
/*   Updated: 2014/12/08 17:48:39 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "mlx.h"

void    quit(t_all *all)
{
	while (all->map.lx--)
		free(all->map.tab[all->map.lx]);
    free(all->map.tab);

    mlx_destroy_image(all->env.mlx, all->img.img);
    free(all->env.mlx);
    free(all->env.win);
    exit(0);
}
