/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:22:23 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/31 13:22:12 by vthomas          ###   ########.fr       */
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
	const int	dx = dst.x - src.x;
	const int	dy = dst.y - src.y;
	int y;
	int x;
	int tmp;
	int err;

	err = 0.0;
	if (dst.x < src.x)
	{
		tmp = dst.x;
		dst.x = src.x;
		src.x = tmp;
		tmp = dst.y;
		dst.y = src.y;
		src.y = tmp;
	}
	new_pos.x = src.x;
	new_pos.y = src.y;
	while (new_pos.x < dst.x)
	{
		mlx_pixel_put(data.mlx, data.win, new_pos.x, new_pos.y, c);
		err += dy;
		if (err > 0)
		{
			err -= dx;
			new_pos.y++;
		}
		new_pos.x++;
	}
}
