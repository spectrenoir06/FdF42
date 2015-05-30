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

static void swap(void *a, void *b)
{
	void* temp;
	temp = a;
	a = b;
	b = temp;
}

void	fillBottomFlatTriangle(t_img i, t_pt2d v1, t_pt2d v2, t_pt2d v3)
{
	float invslope1 = (float)(v2.x - v1.x) / (float)(v2.y - v1.y);
	float invslope2 = (float)(v3.x - v1.x) / (float)(v3.y - v1.y);
	int scanlineY;

	printf("1= %f, 2= %f\n", invslope1, invslope2);

	t_pt2d p1;
	t_pt2d p2;

	float curx1 = v1.x;
	float curx2 = v1.x;

	t_color color = {0,0,0};

	for (scanlineY = v1.y; scanlineY <= v2.y; scanlineY++)
	{
		p1.x = (int)curx1;
		p1.y =  scanlineY;

		p2.x = (int)curx2;
		p2.y =  scanlineY;

		color.r = scanlineY;

		ft_draw_horz_img(i, p1, p2, color);
		curx1 += invslope1;
		curx2 += invslope2;
		printf("x1 = %d, x2 = %d, y = %d\n", p1.x, p2.x, p1.y);
	}
}

void fillTopFlatTriangle(t_img i, t_pt2d v1, t_pt2d v2, t_pt2d v3)
{
	float invslope1 = (float)(v3.x - v1.x) / (float)(v3.y - v1.y);
	float invslope2 = (float)(v3.x - v2.x) / (float)(v3.y - v2.y);


	t_color color = {0,100,255};

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

		ft_draw_horz_img(i, p1, p2, color);
	}
}


void	drawTriangle(t_img i, t_pt2d v1, t_pt2d v2, t_pt2d v3)
{
	if (v1.y > v3.y)
		swap(&v1, &v3);
	if (v1.y > v2.y)
		swap(&v1, &v2);
	if (v2.y > v3.y)
		swap(&v2, &v3);

	if (v2.y == v3.y)
		fillBottomFlatTriangle(i, v1, v2, v3);
	else if (v1.y == v2.y)
		fillTopFlatTriangle(i, v1, v2, v3);
	else
	{
		t_pt2d v4 = {(int)(v1.x + ((float)(v2.y - v1.y) / (float)(v3.y - v1.y)) * (v3.x - v1.x)), v2.y};
		fillBottomFlatTriangle(i, v1, v2, v4);
		fillTopFlatTriangle(i, v2, v4, v3);
	}
}
