/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:34:52 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/28 10:44:13 by vthomas          ###   ########.fr       */
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

void static line_debug(t_coord pos, int color)
{
	ft_putstr("pixel at\t\t[");
	ft_putnbr(pos.x);
	ft_putstr("][");
	ft_putnbr(pos.y);
	ft_putstr("]\t\tcolor: ");
	ft_putnbr_endl(color);
}

void	f_line(t_coord pos, t_coord target, t_data data, int color)
{
	t_coord new_pos;
	double angle;

//	line_debug(pos, color);
	angle = f_getangle(pos, target);
	printf("%f\n",angle);
	if (angle > 22.5 && angle <= 67.5)
		f_change(&new_pos, pos, 1, 1);
	else if (angle > 67.5 && angle <= 112.5)
		f_change(&new_pos, pos, 0, 1);
	else if (angle > 112.5 && angle <= 157.5)
		f_change(&new_pos, pos, -1, 1);
	else if (angle > 157.5 && angle <= 203.5)
		f_change(&new_pos, pos, -1, 0);
	else if (angle > 203.5 && angle <= 248.5)
		f_change(&new_pos, pos, -1, -1);
	else if (angle > 248.5 && angle <= 293.5)
		f_change(&new_pos, pos, 0, -1);
	else if (angle > 293.5 && angle <= 338.5)
		f_change(&new_pos, pos, 1, -1);
	else
		f_change(&new_pos, pos, 1, 0);
	mlx_pixel_put(data.mlx, data.win, new_pos.x, new_pos.y, color);
	if (new_pos.x != target.x && new_pos.y != target.y)
		f_line(new_pos, target, data, color);
}
