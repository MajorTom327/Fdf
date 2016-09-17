/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:22:23 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/17 03:05:06 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

/*
** f_draw_line
** Function take 4 Param:
** 	- 2 param for coord of the extremity of the line
** 	- Data for all needed important info
** 	- Color for the color of the point
*/

void	f_draw_line(t_coord src, t_coord dst, t_data data, int c)
{
	int dx = abs(dst.x - src.x), sx = src.x < dst.x ? 1 : -1;
	int dy = abs(dst.y - src.y), sy = src.y < dst.y ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;
	while (src.x != dst.x || src.y != dst.y)
	{
		mlx_pixel_put(data.mlx, data.win, src.x, src.y, c);
		if (src.x == dst.x && src.y == dst.y) break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			src.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			src.y += sy;
		}
	}
}
