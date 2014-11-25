/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:37:32 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/25 17:37:33 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

typedef struct s_barre
{
	t_rect	rect;
	t_color	color;
}	t_barre;

typedef struct s_ball
{
	int		x;
	int		y;
	int		size;
	int		color;
	int		ox;
	int		oy;
}	t_ball;

typedef struct s_game
{
	t_env	env;
	t_barre		p1;
	t_barre		p2;
	t_ball		ball;
}	t_game;