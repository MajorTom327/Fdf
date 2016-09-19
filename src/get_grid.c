#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

#include <fdf.h>
#include <libft.h>
#include <get_next_line.h>

static t_v3	**sf_grid(const char *av, int c)
{
	t_v3	**grid;
	char	*str;
	int		ret;

	exitm((void*)(grid = (t_v3**)ft_memalloc(sizeof(t_v3 *) * c)));
	if ((c = open(av, O_RDONLY)) < 0)
		exitf();
	while ((ret = get_next_line(c, &str)) > 0)
	{
		
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

	if ((fd = open(av, O_RDONLY)) == -1)
		exitf();
	c = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
		c++;
	ft_strdel(&str);
	close(fd);
	ft_putnbr_desc("Nb of line:\t", c);

	return (sf_grid(av, c));
}
