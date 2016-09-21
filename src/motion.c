#include <fdf.h>
#include <math.h>
#include <debug.h>

void	move_grid(t_data *data, int keycode)
{
	t_v2	dir;

	dir.x = 0;
	dir.y = 0;
	if (keycode == VK_W)
		dir.y = -1;
	if (keycode == VK_A)
		dir.x = -1;
	if (keycode == VK_S)
		dir.y = 1;
	if (keycode == VK_D)
		dir.x = 1;
	data->pos.x += dir.x * FDF_MOVE_PADDING;
	data->pos.y += dir.y * FDF_MOVE_PADDING;
	refresh(data);
}

void	resize_grid(t_data *data, int keycode)
{
	if (keycode == VK_UP)
		data->format.y -= 1;
	if (keycode == VK_LEFT)
		data->format.x -= 1;
	if (keycode == VK_DOWN)
		data->format.y += 1;
	if (keycode == VK_RIGHT)
		data->format.x += 1;
	if (keycode == VK_ADD)
		data->format.z += 1;
	if (keycode == VK_SUB)
		data->format.z -= 1;
	refresh(data);
}

void	rotate_grid(t_data *data, int keycode)
{
	t_v2	pos;
	t_v2	tmp;
	float		a;

	if (keycode == VK_Q)
		a = -0.1;
	else
		a = 0.1;
	pos.y = 0;
	while (pos.y < data->size.y)
	{
		pos.x = 0;
		while (pos.x < data->size.x - 1)
		{
			tmp.x = data->grid[pos.y][pos.x].x;
			tmp.y = data->grid[pos.y][pos.x].y;
			//data->grid[pos.y][pos.x].x = tmp.x * cos(angle) + tmp.y * -sin(angle);
			//data->grid[pos.y][pos.x].y = tmp.x * sin(angle) + tmp.y * cos(angle);
			data->grid[pos.y][pos.x].x = (int)((float) tmp.x * cosf(a) + (float)tmp.y * -sinf(a));
			data->grid[pos.y][pos.x].y = (int)((float) tmp.x * sinf(a) + (float)tmp.y * cosf(a));
			pos.x++;
		}
		pos.y++;
	}
	//dbg_diff_int("rotate_grid", "pos", pos.x, 0, 1);
	//dbg_diff_int("rotate_grid", "pos", pos.y, 1, 1);
	refresh(data);
}

void	change_view(t_data *data, int keycode)
{
	data->view = keycode - 82;
	refresh(data);
}
