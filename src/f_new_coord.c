/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_new_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 04:34:21 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 05:59:30 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_coord	*f_new_coord(int x, int y)
{
	t_coord *tmp;

	tmp = (t_coord *)ft_memalloc(sizeof(t_coord));
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}
