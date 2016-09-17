/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_linefade.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 04:49:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/17 03:52:06 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "stdio.h"

static int	f_purcentcolor(int *c, int p)
{
	int red;
	int green;
	int blue;

	red = (((c[0] & 0xFF0000) - (c[1] &0xFF0000))/ 100 * p) & 0xFF0000;
	green = (((c[0] & 0x00FF00) - (c[1] &0x00FF00))/ 100 * p) & 0x00FF00;
	blue = (((c[0] & 0x0000FF) - (c[1] &0x0000FF))/ 100 * p) & 0x0000FF;
//	printf("r: 0x%x\tg: 0x%x\tb: 0x%x\n", red, green, blue);
	fflush(stdout);
	return (red + green + blue);
}

/*
** f_draw_linefade
** Function take 4 Param:
** 	- 2 param for coord of the extremity of the line
** 	- Data for all needed important info
** 	- Color for the color start ([0]) and for the color end ([1])
*/

void	f_draw_linefade(t_coord src, t_coord dst, t_data data, int *c)
{
	/*
	t_coord		pos;
	const int	dx = dst.x - src.x;
	const int	dy = dst.y - src.y;
	const int	distance = f_distance(src, dst);
	int tmp;
	float grad;
	float xgap;

	if (dx > dy)
	{
		if (dst.x < src.x)
		{
			tmp = dst.x;
			dst.x = src.x;
			src.x = tmp;
			tmp = dst.y;
			dst.y = src.y;
			src.y = tmp;
		}
		grad = dy / dx;
		pos.x = src.x;
		pos.y = dst.y + grad * (pos.x - src.x);
		xgap = (1.0 - (float)src.x + 0.5);
	}
	//mlx_pixel_put(data.mlx, data.win, new_pos.x, new_pos.y, new_color);
	*/
}
