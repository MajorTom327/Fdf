/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_distance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 04:54:24 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 06:06:31 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "libft.h"
#include "fdf.h"

int	f_distance(t_coord src, t_coord dst)
{
	int a;
	int b;

	a = ft_pow(dst.x - src.x, 2);
	b = ft_pow(dst.y - src.y, 2);
	return (sqrt(a + b));
}
