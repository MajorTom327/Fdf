/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 07:05:24 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "stdio.h"

int	main(void)
{
	t_data	data;
	t_coord	src;
	t_coord	dst;
	t_poly *poly;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Title");

	src.x = 64;
	src.y = 64;
	dst.x = 640;
	dst.y = 64;
	f_draw_line(src, dst, data, 0xFF0000);
	poly = f_new_poly(3);
	poly->pos_corner[0].x = 128;
	poly->pos_corner[0].y = 64;
	poly->pos_corner[1].x = 64;
	poly->pos_corner[1].y = 192;
	poly->pos_corner[2].x = 32;
	poly->pos_corner[2].y = 56;
	while (poly->pos_corner[2].x != 96)
	{
		f_draw_poly(*poly, 0xFFFFFF, data);
		poly->pos_corner[2].x++;
		printf("%d;%d\n",poly->pos_corner[2].x, poly->pos_corner[2].y);
		fflush(stdout);
	}

	mlx_key_hook(data.win, &f_exit, 0);
	mlx_loop(data.mlx);
	return (0);
}
