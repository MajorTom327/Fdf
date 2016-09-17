/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/17 03:05:36 by vthomas          ###   ########.fr       */
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

	src.x = 512;
	src.y = 512;
	dst.x = 512;
	dst.y = 16;
	while (dst.x < W_WIDTH - 16)
	{
		f_draw_line(src, dst, data, 0xFFFFFF);
		dst.x++;
	}
	while (dst.y < W_HEIGHT - 16)
	{
		f_draw_line(src, dst, data, 0xFFFFFF);
		dst.y++;
	}
	while (dst.x > 16)
	{
		f_draw_line(src, dst, data, 0xFFFFFF);
		dst.x--;
	}
	while (dst.y > 16)
	{
		f_draw_line(src, dst, data, 0xFFFFFF);
		dst.y--;
	}
	while (dst.x < 512)
	{
		f_draw_line(src, dst, data, 0xFFFFFF);
		dst.x++;
	}
	/*
	src.x = 16;
	src.y = 16;
	dst.x = W_WIDTH - 16;
	dst.y = 16;
	f_draw_line(src, dst, data, 0xFFFFFF);
	dst.y = W_HEIGHT - 16;
	dst.x = 16;
	f_draw_line(src, dst, data, 0xFFFFFF);
	src.x = W_HEIGHT - 16;
	src.y = W_WIDTH - 16;
	dst.x = 16;
	dst.y = W_WIDTH - 16;
	f_draw_line(src, dst, data, 0xFFFFFF);
	dst.x = W_HEIGHT - 16;
	dst.y = 16;
	f_draw_line(src, dst, data, 0xFFFFFF);
*/
	mlx_key_hook(data.win, &f_exit, 0);
	mlx_mouse_hook(data.win, &f_mouse, 0);
	//mlx_hook(data.win, MLX_HOOK_MOUSE_MOTION, NoEventMask, *exit(), 0);
	mlx_loop(data.mlx);
	return (0);
}
