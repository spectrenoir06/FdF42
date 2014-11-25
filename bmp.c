/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:30:59 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/25 17:19:31 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_bmp
{
	int width;
	int height;
	int rowsize;
	unsigned int pallette[16];
	unsigned char *data;
} t_bmp;

unsigned short		read16(int fd)
{
	unsigned short result;
	read(fd, &result, 2);
	return (result);
}

unsigned long	read32(int fd)
{
	unsigned long result;
	read(fd, &result, 4);
	return result;
}

void bmpDraw(int fd,int x, int y)
{
	t_bmp	bmp;
	int       bmpImageoffset;
	int       rowSize;

	char      goodBmp = 0;
	char      flip    = 1;
	int       w;
	int       h;
	int       row;
	int       col;
	int       pos = 0;
	int       buf;
	int       color;

		if(read16(fd) == 0x4D42)
		{
			(void)read32(fd);
			(void)read32(fd);
			bmpImageoffset = read32(fd);

			(void)read32(fd);
			bmpWidth  = read32(fd);
			bmpHeight = read32(fd);
			if (read16(fd) == 1)
			{
				bmpDepth = read16(fd);
				if ((bmpDepth == 4) && (read32(fd) == 0))
				{
					goodBmp = 1;
					rowSize = 96/2;
					if(bmpHeight < 0)
					{
						bmpHeight = -bmpHeight;
						flip      = 0;
					}
					w = bmpWidth;
					h = bmpHeight; 
					(void)read32(fd); //
					(void)read32(fd); //
					(void)read32(fd); //
					(void)read32(fd); //
					(void)read32(fd); //

					for (int i=0 ; i < 16 ; i++)
					{
						color = read32(fd);
						pallette[i] = color;
					}



					for (row=0; row<h; row++)
					{

						for (col=0; col<w; col += 2)
						{
							tft.pushColor(pallette[buf>>4]);
							tft.pushColor(pallette[buf&0xF]);
						}
					}
				}
			}
		}
}
