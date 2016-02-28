/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_getangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 08:31:06 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/28 10:44:10 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"
#include "stdio.h"

double	f_getangle(t_coord pos, t_coord target)
{
	double	angle;
	const double pi = 3.1415926;
	t_coord	cur;

	cur.x = (target.x - pos.x);
	cur.y = (target.y - pos.y);
	angle = atan2(cur.y, cur.x);
	angle = angle< 0 ? angle + 2.0 * pi : angle;
	return ((angle / pi * 180.0));
} 
