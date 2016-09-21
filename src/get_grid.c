/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/22 00:10:10 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

#include <fdf.h>
#include <libft.h>
#include <get_next_line.h>

static int	cleargnl(int fd)
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

static void	get_line_len(const char *file, t_v2 *size)
{
	char	*str;
	t_v2	pos;
	int		f;

	if ((f = open(file, O_RDONLY)) < 0)
		exitf();
	if ((pos.y = get_next_line(f, &str)) < 0)
		exitf();
	pos.y = (int)ft_strlen(str);
	size->y = cleargnl(f);
	pos.x = 0;
	size->x = 0;
	while (pos.x < pos.y)
	{
		if (str[pos.x] >= '0' && str[pos.x] <= '9' && ++size->x)
			while (str[pos.x] >= '0' && str[pos.x] <= '9')
				pos.x++;
		pos.x++;
	}
	if (size->x == 0)
		exitfile();
	ft_strdel(&str);
}

static void	sf_grid(t_v2 *i, t_v2 *pos, char *str, t_v3 **grid)
{
	int		l;
	char	*tmp;

	l = ft_strlen(str);
	while (i->x <= l)
	{
		if (ft_isdigit(str[i->y]) || str[i->y] == '-')
		{
			while (ft_isdigit(str[i->x]) || str[i->x] == '-')
				i->x++;
			tmp = ft_strnew(i->x - i->y);
			ft_strncpy(tmp, &str[i->y], i->x - i->y);
			grid[pos->y][pos->x].z = ft_atoi(tmp);
			grid[pos->y][pos->x].x = pos->x;
			grid[pos->y][pos->x].y = pos->y;
			ft_strdel(&tmp);
			pos->x++;
			i->y = i->x;
		}
		else
			i->y = i->x;
		i->x++;
	}
	pos->y++;
}

t_v3		**get_grid(const char *av, t_v2 *size)
{
	t_v3	**grid;
	t_v2	pos;
	t_v2	i;
	int		fd;
	char	*str;

	get_line_len(av, size);
	exitm((void*)(grid = (t_v3**)ft_memalloc(sizeof(t_v3 *) * (size->y + 1))));
	if ((fd = open(av, O_RDONLY)) < 0)
		exitf();
	pos.y = 0;
	while (get_next_line(fd, &str) > 0)
	{
		i.x = 0;
		i.y = 0;
		pos.x = 0;
		exitm((void*)(grid[pos.y] = (t_v3*)\
		ft_memalloc(sizeof(t_v3) * size->x)));
		sf_grid(&i, &pos, str, grid);
	}
	ft_strdel(&str);
	close(fd);
	return (grid);
}
