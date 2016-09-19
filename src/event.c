#include <libft.h>

int	f_mouse(int btn, int x, int y, void *param)
{
	ft_putstr("Motion: [");
	ft_putnbr(x);
	ft_putstr(";");
	ft_putnbr(y);
	ft_putendl("]");
	return (0);
}

int		f_exit(int keycode, void *data)
{
	if (keycode == 53)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}
