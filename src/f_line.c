/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:34:52 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 03:05:49 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "math.h"
#include "libft.h"

void static f_change(t_coord *new_pos, t_coord pos, int x, int y)
{
	new_pos->x = pos.x + x;
	new_pos->y = pos.y + y;
}


void	f_line(t_coord pos, t_coord target, t_data data, int color)
{
	t_coord new_pos;
	const int dist_x = target.x - pos.x;
	const int dist_y = target.y - pos.y;
	
	new_pos.x = pos.x;
	while (new_pos.x != target.x)
	{
		new_pos.x++;
		new_pos.y = pos.y + dist_y * (new_pos.x - pos.x) / dist_x;
		mlx_pixel_put(data.mlx, data.win, new_pos.x, new_pos.y, color);
	}
}
