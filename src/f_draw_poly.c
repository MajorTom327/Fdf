/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 06:25:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 06:56:29 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	f_draw_poly(t_poly poly, int c, t_data data)
{
	int i;

	i = 1;
	if (poly.nb_corner < 3)
		return ;
	while (i < poly.nb_corner)
	{
		f_draw_line(poly.pos_corner[i], poly.pos_corner[i - 1], data, c);
		i++;
	}
	f_draw_line(poly.pos_corner[i -1], poly.pos_corner[0], data, c);
}
