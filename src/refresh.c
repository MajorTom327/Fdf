/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:25 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/21 20:18:26 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <debug.h>

void	refresh(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_grid(data, data->grid, data->size, 0xFFFFFF);
}
