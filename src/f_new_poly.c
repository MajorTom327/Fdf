/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_new_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 04:43:05 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 05:57:50 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_poly	*f_new_poly(int nb_corner)
{
	t_poly	*poly;

	poly = (t_poly *)ft_memalloc(sizeof(t_poly));
	poly->pos_corner = (t_coord *)ft_memalloc(sizeof(t_coord) * nb_corner);
	poly->nb_corner = nb_corner;
	return (poly);
}
