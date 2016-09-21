/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/21 19:44:09 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		usage();
	data.grid = get_grid(av[1], &(data.size));
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Title");
	data.format.x = W_WIDTH / (data.size.x + 4);
	data.format.y = W_HEIGHT / (data.size.y + 4);
	data.format.z = FDF_BASE_LVL;
	data.pos.x = data.format.x * 3;
	data.pos.y = data.format.y * 3;
	data.angle = 0;
	data.current_y = 0;
	data.view = 2;
	refresh(&data);
	mlx_key_hook(data.win, &f_exit, (void *)&data);
	mlx_hook(data.win, 17, (1L << 17), &f_exitfull, (void *)&data);
	mlx_hook(data.win, 2, (1L << 0), &event_key, (void *)&data);
	mlx_loop(data.mlx);
	return (0);
}
