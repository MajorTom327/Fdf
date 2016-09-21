/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:44 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/21 20:21:02 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <debug.h>

void	move_grid(t_data *data, int keycode)
{
	t_v2	dir;

	dir.x = 0;
	dir.y = 0;
	if (keycode == VK_W)
		dir.y = -1;
	if (keycode == VK_A)
		dir.x = -1;
	if (keycode == VK_S)
		dir.y = 1;
	if (keycode == VK_D)
		dir.x = 1;
	data->pos.x += dir.x * FDF_MOVE_PADDING;
	data->pos.y += dir.y * FDF_MOVE_PADDING;
	refresh(data);
}

void	resize_grid(t_data *data, int keycode)
{
	if (keycode == VK_UP)
		data->format.y -= 1;
	if (keycode == VK_LEFT)
		data->format.x -= 1;
	if (keycode == VK_DOWN)
		data->format.y += 1;
	if (keycode == VK_RIGHT)
		data->format.x += 1;
	if (keycode == VK_ADD)
		data->format.z += 1;
	if (keycode == VK_SUB)
		data->format.z -= 1;
	refresh(data);
}
