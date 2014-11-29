/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 20:09:54 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/28 20:10:15 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	int		lx;
	int		ly;
	t_pt3d	**tab;
}			t_map;

typedef struct s_all
{
	t_env	env;
	t_map	map;

}	t_all;