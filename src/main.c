/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/17 03:44:38 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_coord	src;
	t_coord	dst;
	int		f;

	if (ac != 1)
		usage();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Title");

	src.x = 512;
	src.y = 512;
	dst.x = 524;
	dst.y = 16;
	f_draw_line(src, dst, data, 0xFFFFFF);

	mlx_key_hook(data.win, &f_exit, 0);
	mlx_mouse_hook(data.win, &f_mouse, 0);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, exit, 0);
	mlx_loop(data.mlx);
	return (0);
}
