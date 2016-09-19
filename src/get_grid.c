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

	size->x = get_line_len(av);
	dbg_var_int("sf_grid", "x", size->x, 1);
	dbg_var_int("sf_grid", "y", size->y, 1);
	exitm((void*)(grid = (t_v3**)ft_memalloc(sizeof(t_v3 *) * (size->y + 1))));
	if ((fd = open(av, O_RDONLY)) < 0)
		exitf();
	pos.y = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		l = (int)ft_strlen(str);
		dbg_var_str("sf_grid", "str", str, 1);
		i.x = 0;
		i.y = 0;
		pos.x = 0;
		exitm((void*)(grid[pos.y] = (t_v3*)ft_memalloc(sizeof(t_v3) * size->x)));
		while (i.x < l)
		{
			if (ft_isdigit(str[i.y]) || str[i.y] == '-')
			{
				while (ft_isdigit(str[i.x]))
					i.x++;
				tmp = ft_strnew(i.x - i.y);
				ft_strncpy(tmp, &str[i.y], i.x - i.y);
				grid[pos.y][pos.x].z = ft_atoi(tmp);
				grid[pos.y][pos.x].x = pos.x;// * FDF_BASE_X + FDF_MARGIN;
				grid[pos.y][pos.x].y = pos.y;// * FDF_BASE_Y + FDF_MARGIN;
				ft_strdel(&tmp);
				pos.x++;
				//dbg_var_strint("sf_grid", "x", str, i.x, 2);
				//dbg_var_strint("sf_grid", "y", str, i.y, 2);
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
	int fd;
	int ret;
	char *str;

	if ((fd = open(av, O_RDONLY)) < 2)
		exitf();
	size->y = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		size->y++;
	}
	ft_strdel(&str);
	close(fd);
	return (sf_grid(av, size));
}
