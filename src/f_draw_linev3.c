/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_linev3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:15 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/21 20:18:17 by vthomas          ###   ########.fr       */
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

void	f_draw_linev3(t_v3 src, t_v3 dst, t_data data, int c)
{
	t_v2	src2;
	t_v2	dst2;
	int		pad1;
	int		pad2;
	int		tmp;

	src2.x = (src.x * data.format.x);
	src2.y = (src.y * data.format.y) - (src.z * data.format.z);
	dst2.x = (dst.x * data.format.x);
	dst2.y = (dst.y * data.format.y) - (dst.z * data.format.z);
	if (data.view == 1 || data.view == 3)
	{
		pad1 = (data.current_y - 1) * (data.format.x / 2);
		pad2 = data.current_y * (data.format.x / 2);
	}
	else if (data.view == 2)
	{
		pad1 = 0;
		pad2 = 0;
	}
	pad1 = (data.view == 1) ? -pad1 : pad1;
	pad2 = (data.view == 1) ? -pad2 : pad2;
	if (src.x > dst.x)
	{
		tmp = pad1;
		pad1 = pad2;
		pad2 = tmp;
	}

	src2.x += data.pos.x + pad1;
	src2.y += data.pos.y;
	dst2.x += data.pos.x + pad2;
	dst2.y += data.pos.y;
	f_draw_line(src2, dst2, data, c);
}
