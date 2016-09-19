#include <fdf.h>
#include <debug.h>

void	move_grid(t_data *data, t_v3 dir)
{
	t_v2	tmp;

	tmp.y = 0;
	while (tmp.y < data->size.y)
	{
		tmp.x = 0;
		while (tmp.x < data->size.x)
		{
			data->grid[tmp.y][tmp.x].x += (dir.x * FDF_MOVE_PADDING);
			data->grid[tmp.y][tmp.x].y += (dir.y * FDF_MOVE_PADDING);
			tmp.x++;
		}
		tmp.y++;
	}
	refresh(*data);
}

void	resize_grid(t_data *data, t_v3 dir)
{
	if (dir.z)
	{
		data->format.z += dir.z;
	}
	refresh(*data);
}
