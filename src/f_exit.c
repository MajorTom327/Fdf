/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:31:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/17 03:51:28 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"
#include "libft.h"

int		f_exit(int keycode, void *data)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

void	usage()
{
	ft_putendl("Usage: ./fdf file...");
	exit(0);
}
