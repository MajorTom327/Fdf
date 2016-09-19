/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_pixelintensity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 03:22:59 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/19 00:55:02 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	f_draw_pixelintensity(const t_v2 pos, int color, float intensity, const t_data data)
{
	int red;
	int green;
	int blue;

	red = color & 0xFF0000;
	green = color & 0x00FF00;
	blue = color & 0x0000FF;
	intensity = (1.0 - intensity);
	if (intensity != 0.0)
	{
		red = (red - (int)((float)red * intensity)) & 0xFF0000;
		green = (green - (int)((float)green * intensity)) & 0x00FF00;
		blue = (blue - (int)((float)blue * intensity)) & 0x0000FF;
		color = red + green + blue;
	}
	else
		color = 0;
	mlx_pixel_put(data.mlx, data.win, pos.x, pos.y, color);
}
