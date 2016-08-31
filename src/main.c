/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:22:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/31 13:34:55 by vthomas          ###   ########.fr       */
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
	f_draw_line(src, dst, data, 0x00FF00);
	src.x = 512;
	src.y = 512;
	dst.x = 768;
	dst.y = 255;
	f_draw_line(src, dst, data, 0x00FF00);
	src.x = 512;
	src.y = 512;
	dst.x = 768;
	dst.y = 512;
	f_draw_line(src, dst, data, 0x00FF00);
	src.x = 512;
	src.y = 512;
	dst.x = 768;
	dst.y = 768;
	f_draw_line(src, dst, data, 0x00FF00);
	src.x = 512;
	src.y = 512;
	dst.x = 512;
	dst.y = 768;
	f_draw_line(src, dst, data, 0x00FF00);
	src.x = 512;
	src.y = 512;
	dst.x = 255;
	dst.y = 768;
	f_draw_line(src, dst, data, 0x00FF00);
	src.x = 512;
	src.y = 512;
	dst.x = 255;
	dst.y = 512;
	f_draw_line(src, dst, data, 0x00FF00);
	src.x = 512;
	src.y = 512;
	dst.x = 255;
	dst.y = 255;
	f_draw_line(src, dst, data, 0x00FF00);

	mlx_key_hook(data.win, &f_exit, 0);
	mlx_mouse_hook(data.win, &f_mouse, 0);
	mlx_loop(data.mlx);
	return (0);
}
