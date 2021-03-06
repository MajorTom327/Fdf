/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/24 23:28:35 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <fdf.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		usage();
	data.size.y = 1;
	get_grid(av[1], &(data.size), &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	data.format.x = W_WIDTH / (data.size.x + 4);
	data.format.y = W_HEIGHT / (data.size.y + 4);
	data.format.z = FDF_BASE_LVL;
	data.pos.x = data.format.x * 3;
	data.pos.y = data.format.y * 3;
	data.file = av[1];
	data.angle = 0.0;
	data.show = 0;
	refresh(&data);
	mlx_key_hook(data.win, &f_exit, (void *)&data);
	mlx_hook(data.win, 17, (1L << 17), &f_exitfull, (void *)&data);
	mlx_hook(data.win, 2, (1L << 0), &event_key, (void *)&data);
	mlx_loop(data.mlx);
	return (0);
}
