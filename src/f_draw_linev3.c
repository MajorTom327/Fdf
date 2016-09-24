/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_linev3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:15 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/24 23:33:32 by vthomas          ###   ########.fr       */
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

static void	rotate(t_v2 *pos, float a)
{
	pos->x = (pos->x * cos(a)) + (pos->y * -sin(a));
	pos->y = (pos->x * sin(a)) + (pos->y * cos(a));
}

void		f_draw_linev3(t_v3 src, t_v3 dst, t_data data, int c)
{
	t_v2	src2;
	t_v2	dst2;

	src2.x = (src.x * data.format.x);
	src2.y = (src.y * data.format.y) - (src.z * data.format.z);
	dst2.x = (dst.x * data.format.x);
	dst2.y = (dst.y * data.format.y) - (dst.z * data.format.z);
	rotate(&src2, data.angle);
	rotate(&dst2, data.angle);
	src2.x += data.pos.x;
	src2.y += data.pos.y;
	dst2.x += data.pos.x;
	dst2.y += data.pos.y;
	f_draw_line(src2, dst2, data, c);
}
