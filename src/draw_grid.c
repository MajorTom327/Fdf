/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/24 23:33:22 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <unistd.h>
#include <libft.h>
#include <get_next_line.h>

static void	draw_cur(t_data *data)
{
	t_v3 v;
	t_v3 o;

	o.x = 0;
	o.y = 0;
	o.z = 0;
	v.x = 1;
	v.y = 0;
	v.z = 0;
	f_draw_linev3(o, v, *data, 0xFF0000);
	v.x = 0;
	v.y = 1;
	f_draw_linev3(o, v, *data, 0x00FF00);
	v.y = 0;
	v.z = 10;
	f_draw_linev3(o, v, *data, 0x0000FF);
}

void		draw_grid(t_data *data, t_v3 **grid, t_v2 size, int c)
{
	t_v2	p;

	p.y = 0;
	while (p.y < size.y)
	{
		p.x = 0;
		while (p.x < size.x)
		{
			if (p.x > 0)
				f_draw_linev3(grid[p.y][p.x], grid[p.y][p.x - 1], *data, c);
			if (p.y > 0)
				f_draw_linev3(grid[p.y][p.x], grid[p.y - 1][p.x], *data, c);
			if (p.x + 1 < size.x - 1)
				f_draw_linev3(grid[p.y][p.x], grid[p.y][p.x + 1], *data, c);
			if (p.y + 1 < size.y)
				f_draw_linev3(grid[p.y][p.x], grid[p.y + 1][p.x], *data, c);
			p.x++;
		}
		p.y++;
	}
	if (data->show)
		draw_cur(data);
}

int			cleargnl(int fd)
{
	char	*str;
	int		i;

	i = 1;
	while (get_next_line(fd, &str))
	{
		ft_strdel(&str);
		i++;
	}
	ft_strdel(&str);
	close(fd);
	return (i);
}
