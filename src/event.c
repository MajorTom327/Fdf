/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:05 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/21 21:24:11 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>

int		f_mouse(int btn, int x, int y, void *param)
{
	(void)*param;
	(void)btn;
	ft_putstr("Motion: [");
	ft_putnbr(x);
	ft_putstr(";");
	ft_putnbr(y);
	ft_putendl("]");
	return (0);
}

int		f_exit(int keycode, void *data)
{
	t_data	*d;

	if (keycode == 53)
	{
		d = (t_data *)data;
		ft_memdel((void **)d->grid);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		f_exitfull(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	ft_memdel((void **)d->grid);
	exit(EXIT_SUCCESS);
	return (0);
}

int		event_key(int keycode, t_data *data)
{
	if (keycode == VK_W || keycode == VK_A ||\
		keycode == VK_S || keycode == VK_D)
		move_grid(data, keycode);
	else if (keycode == VK_UP || keycode == VK_LEFT || keycode == VK_RIGHT ||\
		keycode == VK_DOWN || keycode == VK_ADD || keycode == VK_SUB)
		resize_grid(data, keycode);
	else if (keycode == VK_1)
		print_grid(data);
	else if (keycode == VK_2)
		print_file(data);
	return (0);
}
