/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/19 01:32:47 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_v2	src;
	t_v2	dst;
	t_v3	**grid;
	int		f;

	if (ac != 2)
		usage();
	grid = get_grid(av[1]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Title");

	src.x = 512;
	src.y = 512;
	dst.x = 524;
	dst.y = 16;
	f_draw_line(src, dst, data, 0xFFFFFF);

	mlx_key_hook(data.win, &f_exit, 0);
	mlx_mouse_hook(data.win, &f_mouse, 0);
	//TODO: Create a function for exit and cleanup
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, exit, (void *)0);
	mlx_loop(data.mlx);
	return (0);
}
