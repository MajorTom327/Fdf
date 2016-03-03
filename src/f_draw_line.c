/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:22:23 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 05:54:10 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "math.h"

/*
** f_draw_line
** Function take 4 Param:
** 	- 2 param for coord of the extremity of the line
** 	- Data for all needed important info
** 	- Color for the color of the point
*/

void	f_draw_line(t_coord src, t_coord dst, t_data data, int c)
{
	t_coord		new_pos;
	const int	dist_x = dst.x - src.x;
	const int	dist_y = dst.y - src.y;

	new_pos.x = src.x;
	while (new_pos.x != dst.x)
	{
		new_pos.x++;
		new_pos.y = src.y + dist_y * (new_pos.x - src.x) / dist_x;
		mlx_pixel_put(data.mlx, data.win, new_pos.x, new_pos.y, c);
	}
}
