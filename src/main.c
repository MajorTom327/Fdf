/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/28 09:29:34 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

int	main(void)
{
	t_data	data;
	t_coord	pos;
	t_coord target;

	pos.x = 5;
	pos.y = 5;
	target.x = 512;
	target.y = 64;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Title");
	f_line(pos, target, data, 0x990000);
	mlx_pixel_put(data.mlx, data.win, pos.x,pos.y, 0xFFFFFF);
	mlx_pixel_put(data.mlx, data.win, target.x,target.y, 0xFFFFFF);
	mlx_key_hook(data.win, &f_exit, 0);
	mlx_loop(data.mlx);
	return (0);
}
