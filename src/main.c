/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/19 09:46:11 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_v2	size;

	if (ac != 2)
		usage();
	data.grid = get_grid(av[1], &(data.size));
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Title");
	data.format.x = FDF_BASE_X;
	data.format.y = FDF_BASE_Y;
	data.format.z = FDF_BASE_LVL;
	data.pos.x = W_WIDTH / 2;
	data.pos.y = W_HEIGHT / 2;

	refresh(data);
	draw_grid(data, data.grid, data.size, 0xFFFFFF);

	mlx_key_hook(data.win, &f_exit, 0);
	//mlx_mouse_hook(data.win, &f_mouse, 0);
	//TODO: Create a function for exit and cleanup
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &exit, (void *)0);
	mlx_hook(data.win, 2, (1L<<0), &event_key, (void *)&data);
	mlx_loop(data.mlx);
	return (0);
}
