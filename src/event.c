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
	if (keycode == VK_W || keycode == VK_A ||\
		keycode == VK_S || keycode == VK_D)
		move_grid(data, keycode);
	else if (keycode == VK_UP || keycode == VK_LEFT || keycode == VK_RIGHT ||\
		keycode == VK_DOWN || keycode == VK_ADD || keycode == VK_SUB)
		resize_grid(data, keycode);
	else if (keycode == VK_Q || keycode == VK_E)
		rotate_grid(data, keycode);
}
