/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 03:05:54 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "stdio.h"

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
	mlx_pixel_put(data.mlx, data.win, pos.x, pos.y, 0xFFFFFF);
	mlx_pixel_put(data.mlx, data.win, target.x,target.y, 0xFFFFFF);
	int i;
	int j = 16;
	float inten;
	while (j < 116)
	{
		i = 0;
		inten = 1.0;
		pos.y = 92;
		pos.x = j++;
		while (i < 100)
		{
			pos.y++;
			inten -= 0.01;
			f_pixelintensity(pos, 0x5E0243, inten, data);
			i++;
		}
//		printf("j:\t%d\tpos.x:\t%d\n", j, pos.x);
	}
	mlx_key_hook(data.win, &f_exit, 0);
	mlx_loop(data.mlx);
	return (0);
}
