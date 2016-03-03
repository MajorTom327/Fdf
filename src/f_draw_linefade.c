/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_linefade.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 04:49:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 06:25:30 by vthomas          ###   ########.fr       */
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
	t_coord		new_pos;
	const int	dist_x = dst.x - src.x;
	const int	dist_y = dst.y - src.y;
	const int	distance = f_distance(src, dst);
	int			cur_dist;
	int			purcent;
	int			new_color;

	new_pos.x = src.x;
	while (new_pos.x != dst.x)
	{
		cur_dist = f_distance(new_pos, dst);
		purcent = (int)(((float)cur_dist / (float)distance) * 100.0);
		printf("dist: \t%d\tpurcent:\t%d\n", cur_dist,purcent);
		new_color = f_purcentcolor(c, purcent); 
		new_pos.x++;
		new_pos.y = src.y + dist_y * (new_pos.x - src.x) / dist_x;
		mlx_pixel_put(data.mlx, data.win, new_pos.x, new_pos.y, new_color);
	}
}
