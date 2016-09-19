#include <libft.h>
#include <fdf.h>

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

int		event_key(int keycode, t_data *data)
{
	t_v3	tmp;

	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	if (keycode == VK_W)
		tmp.y = -1;
	if (keycode == VK_A)
		tmp.x = -1;
	if (keycode == VK_S)
		tmp.y = 1;
	if (keycode == VK_D)
		tmp.x = 1;
	if (tmp.x != 0 || tmp.y != 0)
	{
		move_grid(data, tmp);
		return (0);
	}
	if (keycode == VK_UP)
		tmp.y = -1;
	if (keycode == VK_LEFT)
		tmp.x = -1;
	if (keycode == VK_DOWN)
		tmp.y = 1;
	if (keycode == VK_RIGHT)
		tmp.x = 1;
	if (keycode == VK_ADD)
		tmp.z = 1;
	if (keycode == VK_SUB)
		tmp.z = -1;
	if (tmp.x != 0 || tmp.y != 0 || tmp.z != 0)
		resize_grid(data, tmp);
}
