/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:31:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/31 13:39:18 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"
#include "libft.h"

int	f_exit(int keycode, void *data)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

int	f_mouse(int btn, int x, int y, void *param)
{
	ft_putstr("Motion: [");
	ft_putnbr(x);
	ft_putstr(";");
	ft_putnbr(y);
	ft_putendl("]");
	return (0);
}
