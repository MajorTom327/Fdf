/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/21 21:15:52 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

#include <fdf.h>
#include <libft.h>
#include <get_next_line.h>
#include <debug.h>

static int	get_line_len(const char *file, t_v2 *size)
{
	char	*str;
	char	*tmp;
	t_v2	pos;
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		exitf();
	if ((pos.y = get_next_line(fd, &str)) < 0)
		exitf();
	pos.y = (int)ft_strlen(str);
	while (get_next_line(fd, &tmp) > 0)
		size->y++;
	close(fd);
	ft_strdel(&tmp);
	pos.x = 0;
	size->x = 0;
	while (pos.x < pos.y)
	{
		if (str[pos.x] >= '0' && str[pos.x] <= '9')
		{
			size->x++;
			while (str[pos.x] >= '0' && str[pos.x] <= '9')
				pos.x++;
		}
		pos.x++;
	}
	if (size->x == 0)
		exitfile();
	ft_strdel(&str);
	return (size->x);
}

static t_v3	**sf_grid(const char *av, t_v2 *size)
{
	t_v3	**grid;
	t_v2	pos;
	t_v2	i;
	int		fd;
	char	*str;
	int		ret;
	char	*tmp;
	int		l;

	get_line_len(av, size);
	exitm((void*)(grid = (t_v3**)ft_memalloc(sizeof(t_v3 *) * (size->y + 1))));
	if ((fd = open(av, O_RDONLY)) < 0)
		exitf();
	pos.y = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		l = (int)ft_strlen(str);
		i.x = 0;
		i.y = 0;
		pos.x = 0;
		exitm((void*)(grid[pos.y] = (t_v3*)ft_memalloc(sizeof(t_v3) * size->x)));
		while (i.x <= l)
		{
			if (ft_isdigit(str[i.y]) || str[i.y] == '-')
			{
				while (ft_isdigit(str[i.x]) || str[i.x] == '-')
					i.x++;
				tmp = ft_strnew(i.x - i.y);
				ft_strncpy(tmp, &str[i.y], i.x - i.y);
				grid[pos.y][pos.x].z = ft_atoi(tmp);
				grid[pos.y][pos.x].x = pos.x;
				grid[pos.y][pos.x].y = pos.y;
				ft_strdel(&tmp);
				pos.x++;
				i.y = i.x;
			}
			else
				i.y = i.x;
			i.x++;
		}
		pos.y++;
	}
	ft_strdel(&str);
	close(fd);
	return (grid);
}

t_v3		**get_grid(const char *av, t_v2 *size)
{
	return (sf_grid(av, size));
}
