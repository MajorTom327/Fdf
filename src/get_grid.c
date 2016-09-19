#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

#include <fdf.h>
#include <libft.h>
#include <get_next_line.h>
#include <debug.h>

static int	get_line_len(const char *file)
{
	char	*str;
	char	*tmp;
	int		fd;
	int		i;
	int		l;
	int		c;

	if ((fd = open(file, O_RDONLY)) < 0)
		exitf();
	l = get_next_line(fd, &str);
	if (l < 0)
		exitf();
	l = (int)ft_strlen(str);
	while (get_next_line(fd, &tmp) > 0)
		;
	close(fd);
	ft_strdel(&tmp);
	i = 0;
	c = 0;
	while (i < l)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			c++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		i++;
	}
	if (c == 0)
		exitfile();
	ft_strdel(&str);
	return (c);
}

static t_v3	**sf_grid(const char *av, int c)
{
	t_v3	**grid;
	t_v2	pos;
	t_v2	i;
	int		y;
	char	*str;
	int		ret;
	char	*tmp;
	int		l;

	y = get_line_len(av);
	dbg_var_int("sf_grid", "x", y, 1);
	dbg_var_int("sf_grid", "y", c, 1);
	exitm((void*)(grid = (t_v3**)ft_memalloc(sizeof(t_v3 *) * (c + 1))));
	if ((c = open(av, O_RDONLY)) < 0)
		exitf();
	pos.y = 0;
	while ((ret = get_next_line(c, &str)) > 0)
	{
		l = (int)ft_strlen(&str);
		i.x = 0;
		i.y = 0;
		pos.x = 0;
		exitm((void*)(grid[pos.y] = (t_v3*)ft_memalloc(sizeof(t_v3) * y)));
		while (i.x < l)
		{
			if (ft_isdigit(str[i.y]))
			{
				while (ft_isdigit(str[i.x]))
					i.x++;
				tmp = ft_strnew(i.x - i.y);
				ft_strncpy(tmp, &str[i.y], i.x - i.y);
				grid[pos.y][pos.x].z = ft_atoi(tmp);
				grid[pos.y][pos.x].x = pos.x * FDF_BASE_X;
				grid[pos.y][pos.x].y = pos.y * FDF_BASE_Y;
				ft_strdel(&tmp);
				pos.x++;
				i.y = i.x;
			}
			i.x++;
		}
		pos.y++;
	}
	ft_strdel(&str);
	close(c);
	return (grid);
}

t_v3		**get_grid(const char *av)
{
	int fd;
	int c;
	int ret;
	char *str;

	if ((fd = open(av, O_RDONLY)) < 2)
		exitf();
	c = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		c++;
	}
	ft_strdel(&str);
	close(fd);
	return (sf_grid(av, c));
}
