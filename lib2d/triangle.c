/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 20:05:22 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/30 20:05:24 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

static void swap(t_pt2d *a, t_pt2d *b)
{
	t_pt2d temp = *a;
	*a = *b;
	*b = temp;
}

void	fillBottomFlatTriangle(t_img i, t_pt2d v1, t_pt2d v2, t_pt2d v3, t_color c)
{
	float invslope1 = (float)(v2.x - v1.x) / (float)(v2.y - v1.y);
	float invslope2 = (float)(v3.x - v1.x) / (float)(v3.y - v1.y);
	int scanlineY;

	//printf("1= %f, 2= %f\n", invslope1, invslope2);

	t_pt2d p1;
	t_pt2d p2;

	float curx1 = v1.x;
	float curx2 = v1.x;

	for (scanlineY = v1.y; scanlineY <= v2.y; scanlineY++)
	{
		p1.x = (int)curx1;
		p1.y =  scanlineY;

		p2.x = (int)curx2;
		p2.y =  scanlineY;

		//c.r = scanlineY;

		ft_draw_horz_img(i, p1, p2, c);
		curx1 += invslope1;
		curx2 += invslope2;
	}
}

void fillTopFlatTriangle(t_img i, t_pt2d v1, t_pt2d v2, t_pt2d v3, t_color c)
{
	float invslope1 = (float)(v3.x - v1.x) / (float)(v3.y - v1.y);
	float invslope2 = (float)(v3.x - v2.x) / (float)(v3.y - v2.y);

	int scanlineY;

	t_pt2d p1;
	t_pt2d p2;

	float curx1 = v3.x;
	float curx2 = v3.x;

	for (scanlineY = v3.y; scanlineY > v1.y; scanlineY--)
	{
		curx1 -= invslope1;
		curx2 -= invslope2;

		p1.x = (int)curx1;
		p1.y =  scanlineY;

		p2.x = (int)curx2;
		p2.y =  scanlineY;

		ft_draw_horz_img(i, p1, p2, c);
	}
}


void	drawTriangle(t_img i, t_pt2d v1, t_pt2d v2, t_pt2d v3, t_color c)
{

	if (v1.y > v3.y)
		swap(&v1, &v3);
	if (v1.y > v2.y)
		swap(&v1, &v2);
	if (v2.y > v3.y)
		swap(&v2, &v3);

	ft_draw_line2d_img(i, v1, v2, c);
	ft_draw_line2d_img(i, v2, v3, c);
	ft_draw_line2d_img(i, v3, v1, c);

	if (v2.y == v3.y)
		fillBottomFlatTriangle(i, v1, v2, v3, c);
	else if (v1.y == v2.y)
		fillTopFlatTriangle(i, v1, v2, v3, c);
	else
	{
		t_pt2d v4 = {(int)(v1.x + ((float)(v2.y - v1.y) / (float)(v3.y - v1.y)) * (v3.x - v1.x)), v2.y};
		fillBottomFlatTriangle(i, v1, v2, v4, c);
		fillTopFlatTriangle(i, v2, v4, v3, c);
	}
}

void	drawTriangle3D(t_img i, t_pt3d v1, t_pt3d v2, t_pt3d v3, t_color c)
{
	v1.z *= i.mult;
	v2.z *= i.mult;
	v3.z *= i.mult;

	t_pt2d p1 = ft_3d_to_2d(v1, *i.env);
	t_pt2d p2 = ft_3d_to_2d(v2, *i.env);
	t_pt2d p3 = ft_3d_to_2d(v3, *i.env);


	drawTriangle(i,p1,p2,p3,c);
}
